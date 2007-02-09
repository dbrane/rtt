/***************************************************************************
  tag: Peter Soetens  Mon May 10 19:10:29 CEST 2004  PeriodicActivity.cxx 

                        PeriodicActivity.cxx -  description
                           -------------------
    begin                : Mon May 10 2004
    copyright            : (C) 2004 Peter Soetens
    email                : peter.soetens@mech.kuleuven.ac.be
 
 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU General Public                   *
 *   License as published by the Free Software Foundation;                 *
 *   version 2 of the License.                                             *
 *                                                                         *
 *   As a special exception, you may use this file as part of a free       *
 *   software library without restriction.  Specifically, if other files   *
 *   instantiate templates or use macros or inline functions from this     *
 *   file, or you compile this file and link it with other files to        *
 *   produce an executable, this file does not by itself cause the         *
 *   resulting executable to be covered by the GNU General Public          *
 *   License.  This exception does not however invalidate any other        *
 *   reasons why the executable file might be covered by the GNU General   *
 *   Public License.                                                       *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU General Public             *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/

#ifdef ORO_PRAGMA_INTERFACE
#pragma implementation
#endif
#include "Time.hpp"
#include "PeriodicActivity.hpp"
#include "os/MutexLock.hpp"
#include "Logger.hpp"
#include "TimerThread.hpp"

// This define is used for creating and static_casting the Timer.
#include <rtt-config.h>
#ifdef OROSEM_CORELIB_ACTIVITIES_TASKTIMER_TimerOneShot
#include "TimerOneShot.hpp"
#elif defined(OROSEM_CORELIB_ACTIVITIES_TASKTIMER_TimerSequencer)
#include "TimerSequencer.hpp"
#else
#include "TimerOneShot.hpp" // default
#endif

#include <cmath>

namespace RTT
{
    using namespace detail;
    
    PeriodicActivity::PeriodicActivity(int priority, Seconds period, RunnableInterface* r )
        : runner(r), running(false), active(false),
          thread_( TimerThread::Instance(priority,period) )
    {
        thread_->start();
        per_ns = Seconds_to_nsecs( period );
        this->init();
    }

    PeriodicActivity::PeriodicActivity(TimerThreadPtr thread, RunnableInterface* r )
        : runner(r), running(false), active(false),
          thread_( thread )
    {
        per_ns = Seconds_to_nsecs( thread->getPeriod() );
        this->init();
    }

    PeriodicActivity::PeriodicActivity(Seconds period, TimerThreadPtr thread, RunnableInterface* r )
        : runner(r), running(false), active(false),
          thread_(thread)
    {
        per_ns = Seconds_to_nsecs( period );
        this->init();
    }

    PeriodicActivity::PeriodicActivity(secs s, nsecs ns, TimerThreadPtr thread, RunnableInterface* r )
        : runner(r),
          running(false), active(false),
          per_ns( secs_to_nsecs(s) + ns),
          thread_(thread)
    {
        this->init();
    }

    PeriodicActivity::~PeriodicActivity()
    {
        stop();
        if (runner)
            runner->setActivity(0);
    }

    void PeriodicActivity::init() {
        if (runner)
            runner->setActivity(this);

        TimerInterface* timer = thread_->timerGet( this->getPeriod() );
        if ( timer == 0 ) {
            timer = new TimerOneShot( per_ns );
//             Logger::log() << Logger::Debug << "Timer Created, period_ns: "<< per_ns <<" thread :"<< thread_->getName() <<Logger::endl;
            // The timer is owned by the thread !
            if ( thread_->timerAdd( timer ) == false ) {
                delete timer;
                timer = 0;
                Logger::log() << Logger::Critical << "PeriodicActivity with period "<<this->getPeriod()
                              << "s failed to schedule in thread " << thread_->getName()
                              << " which has period "<< thread_->getPeriod()<<"s."<< Logger::endl;
            }
        }
//         else
//             Logger::log() << Logger::Debug << "Existing timer, period_ns: "<< timer->getPeriod() <<" thread :"<< thread_->getName() <<Logger::endl;

        timer_ = timer;
    }

     
    bool PeriodicActivity::run( RunnableInterface* r )
    {
        if ( isRunning() )
            return false;
        if (runner)
            runner->setActivity(0);
        runner = r;
        if (runner)
            runner->setActivity(this);
        return true;
    }

    bool PeriodicActivity::start()
    {
        if ( !timer_ || isActive() || !thread_->isRunning() ) {
            //Logger::log() << Logger::Error << "PeriodicActivity : no timer, already active or thread not running." << Logger::endl;
            return false;
        }
	
        active = true;
        bool inError = !this->initialize();
        if ( inError ) {
            //Logger::log() << Logger::Error << "PeriodicActivity : initialize() returned false " << Logger::endl;
            active = false;
            return false;
        }

        bool res;
        res = timer_->addActivity( this );
        if ( res == false ) {
            //Logger::log() << Logger::Error << "PeriodicActivity : addActivity() returned false " << Logger::endl;
            this->finalize();
            active = false;
            return false;
        }

        running = true;
        return true;
    }

    bool PeriodicActivity::stop()
    {
        if ( !isActive() ) return false;

        // since removeActivity synchronises, we do not need to mutex-lock
        // stop()
        if ( timer_->removeActivity( this ) ) {
            running = false;
            this->finalize();
            active = false;
            return true;
        }
        return false;
    }

    bool PeriodicActivity::isRunning() const
    {
        return running;
    }

    bool PeriodicActivity::isActive() const
    {
        return active;
    }

    Seconds PeriodicActivity::getPeriod() const
    {
        return nsecs_to_Seconds( per_ns );
    }

    bool PeriodicActivity::initialize() { 
        if (runner != 0)
            return runner->initialize();
        else
            return true;
    }

    void PeriodicActivity::doStep()
    {
        this->step();
    }

    bool PeriodicActivity::execute()
    {
        return false;
    }
        
    bool PeriodicActivity::trigger()
    {
        return false;
    }
        
    void PeriodicActivity::step()
    {
        // override this method to avoid running runner.
        if (runner != 0)
            runner->step();
    }

    void PeriodicActivity::finalize() {
        if (runner != 0)
            runner->finalize();
    }

    OS::ThreadInterface* PeriodicActivity::thread() { return thread_.get(); }

    bool PeriodicActivity::isPeriodic() const {
        return true;
    }
}