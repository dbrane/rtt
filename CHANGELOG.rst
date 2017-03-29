^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package rtt
^^^^^^^^^^^^^^^^^^^^^^^^^

2.8.4 (2017-03-30)
------------------
* Merge pull request #202 from meyerj/fix/dev-test
  tests: fixed dev_test for gcc 5
* tests: fixed dev_test for gcc 5
  DigitalIniput expects a const bool & in its constructor and stores it in
  a member variable. The dev_test passed a boolean literal, but C++ creates a temporary
  in this case which is only valid during the call.
  At least with gcc 5 the dev_test consistenly failed because of this issue:
  /home/travis/build/orocos-toolchain/rtt/tests/dev_test.cpp(56): error in "testClasses": check din.isOn() failed
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge branch 'fix/cmake-version-printout'
* cmake: use SOVERSION in tests/CMakeList.txt
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #172 from meyerj/fix/cmake-version-printout
  cmake: fixed version printout and added variable RTT_SOVERSION
* Merge pull request #173 from meyerj/corba-anyconversion-full-template-args
  corba: added template arguments Alloc and Compare for RTT::corba::AnyConversion specializations for vectors and maps
* Merge pull request #196 from meyerj/fix/boost-fusion-1.58-c++11
  Fixed OperationInterfacePartFused for -std=c++11 builds with Boost 1.58 (master)
* Merge pull request #194 from meyerj/addDisconnect
  corba: fixed hidden overloaded virtual functions in RemotePorts.hpp
* Merge pull request #191 from planthaber/gcc6
  cmake gcc6 support
* Merge pull request #185 from meyerj/fix/do-not-log-in-pluginloader-destructor
  plugin: do not log during destruction of the PluginLoader singleton
* Merge pull request #190 from snrkiwi/fix-rtt-logger-realtime-enabling
  logger: Ensure that the notification of real-time logging being enabl…
* Merge pull request #184 from orocos-toolchain/mqueue_ignore_eintr_in_select
  mqueue: ignore EINTR in select()
* Merge pull request #186 from meyerj/fix-taskthread-fd-test
  tests: fixed timeout counter expectations in FileDescriptorActivity tests
* Merge pull request #182 from orocos-toolchain/fix_race_conditions_between_stop_and_the_runtime_error_state
  fix race conditions between stop() and the runtime error state
* Merge pull request #180 from meyerj/master-connectionmanager-real-timeliness
  Fixed potential memory allocation problem in ConnectionManager
* Merge pull request #174 from meyerj/corba-template-protocol-optimizations
  corba: removed special cases that depend on the data source type in CorbaTemplateProtocol<T>
* internal: avoid Boost Config macros only available in Boost 1.50 and later
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* internal: fixed brackets for the non-C++11 case in OperationInterfacePartFused.hpp
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Fixed internal::OperationInterfacePartFused for -std=c++11 builds with Boost 1.58
  The unfused adapter accepts only LValue arguments, while in general operations can also have RValues as arguments:
  http://www.boost.org/doc/libs/1_58_0/libs/fusion/doc/html/fusion/functional/adapters/unfused.html
  Without C++11 and for older Boost versions this was apparently not an issue and the necessary conversion have been
  done implicitly (?).
  The solution applies the forward_adapter template (http://www.boost.org/doc/libs/1_63_0/libs/functional/forward/doc/html/index.html)
  to overcome this limitation as suggested in the Boost Fusion documentation.
  This patch also reverts the USE_CPP11 macro usage for this file, as it did not use std::bind or any C++11 feature anyway and
  the only effect is the namespace of placeholders (see https://github.com/orocos-toolchain/rtt/commit/35cd426b4fd93c14a597b6ae590cc45c2dd2d105).
  boost::arg<i> is a simpler solution that also prevent namespace clashes without having to use boost::lambda.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* corba: fixed hidden overloaded virtual functions in RemotePorts.hpp
  This is a regression from https://github.com/orocos-toolchain/rtt/pull/142/commits/0db4e04b4cbaac2218f0d2a38a90671407d14f45.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #192 from planthaber/boost1.61
  boost 1.61 support
* check if BOOST_PFTO is definned instead of boost version, fixed boost::serialization::make_array guard in test case
  https://github.com/orocos-toolchain/rtt/pull/192#issuecomment-270619587
* boost 1.61 support
* cmake gcc6 support
* logger: Ensure that the notification of real-time logging being enabled is actually logged
  If you log and then turn on logging, then you will not get the logged item if RealTime
  level has been selected. This is simply due to the check occurring before everything
  has been enabled again.
  The fix is to turn on logging and then log, ensuring that the logged item will
  actually be logged (if the appropriate log level is already set).
* Merge branch 'add-orocos-env-hook'
* env-hooks: install env-hook to etc/orocos/profile.d without the OROCOS_TARGET part
  env-hooks can check the OROCOS_TARGET environment variable in case this is required.
  There is no need to install separate per-target env-hooks.
  The 00.rtt.sh env-hook sets the OROCOS_TARGET variable to whatever target has been installed last.
* Merge pull request #189 from orocos-toolchain/fix-boost-162
  Fixed BOOST_GLOBAL_FIXTURE() macro call for Boost >=1.60 and removed extra semicolons
* Merge pull request #188 from snrkiwi/fix-macosx-cxx11-errors
  macosx: Add static casts to slience C++11 narrowing errors
* Merge branch 'issue-164'
  See https://github.com/orocos-toolchain/rtt/issues/164.
* tests: replaced deprecated BOOST_MESSAGE() macro call with BOOST_TEST_MESSAGE() in property_test.cpp
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* .travis.yml: enable most compiler warnings and specify C/C++ standard explicitly
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* .travis.yml: increase log level of the Boost Unit Test Framework
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Fixed BOOST_GLOBAL_FIXTURE() macro call for Boost >=1.60 and removed extra semicolons
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* macosx: Add static casts to slience C++11 narrowing errors
  Erorrs are of the form:
  In file included from /opt/orocos/share/orocos_kdl/../../include/rtt/base/../os/fosi.h:59:
  /opt/orocos/share/orocos_kdl/../../include/rtt/base/../os/macosx/fosi.h:170:42: error: non-constant-expression cannot be narrowed from type '__darwin_time_t' (aka 'long') to 'unsigned int' in initializer list [-Wc++11-narrowing]
  mach_timespec_t mach_delayvl = { delayvl.tv_sec, delayvl.tv_nsec };
  ^~~~~~~~~~~~~~
  /opt/orocos/share/orocos_kdl/../../include/rtt/base/../os/macosx/fosi.h:170:42: note: insert an explicit cast to silence this issue
  mach_timespec_t mach_delayvl = { delayvl.tv_sec, delayvl.tv_nsec };
  ^~~~~~~~~~~~~~
  static_cast<unsigned int>( )
  Add the necessary casts, but only for C++ (this file is compiled in C for tlsf.c also).
* Merge branch 'fix-boost-162'
* Merge pull request #160 from meyerj/add-orocos-env-hook
  env-hooks: install env-hook to etc/orocos/OROCOS_TARGET/profile.d
* tests: fixed timeout counter expectations in FileDescriptorActivity tests
  BOOST_CHECK_CLOSE_FRACTION(left, right, tolerance) expects a tolerance given as fraction of absolute values
  (http://www.boost.org/doc/libs/1_62_0/libs/test/doc/html/boost_test/utf_reference/testing_tool_ref/assertion_boost_level_close_fraction.html).
  With the introduction of additional sleep delay of half a timeout cycle the timeout counter should be predictable enough
  for exact checks. However the checks could fail if the CPU is too busy to execute the FileDescriptorActivity.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #134 from meyerj/revert-taskcontext-load-plugin-operation
  Revert "added ability to load a plugin using a operation on a task."
* Renamed boost::serialization::array<T> class name for Boost version 1.62 and higher
  The class template was renamed to boost::serialization::array_wrapper<T>, probably to avoid conflicts with
  std::array<T> added in C++11.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* plugin: do not log during destruction of the PluginLoader singleton
  ... as this might trigger the creation of a new Logger instance during static destruction.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #183 from orocos-toolchain/expose_circular_buffer_on_corba
  corba: expose the CircularBuffer connection type on CORBA
* mqueue: ignore EINTR in select()
* fix race conditions between stop() and the runtime error state
  stop() does a synchronization point by stopping the activity, but
  then starts it right away. Given that the EE was not checking against
  mTargetState when deciding to call errorHook(), there was a chance
  that errorHook was called during or after stopHook.
  Moreover, while error() was checking that mTargetState was a runtime
  state, recover() was not, which could lead to a call to recover()
  overriding mTargetState during the stop, leaving the task stopped
  but in an inconsistent state.
* corba: expose the CircularBuffer connection type on CORBA
* Merge pull request #181 from orocos-toolchain/enforce_mq_name_convention
  mqueue: enforce MQ name convention
* mqueue: throw if name_id is not set and the port is not attached to a task
  In this case, generating a name that has a high chance of being
  unique system-wide is ... low. Throw asking the user to set a
  name_id explicitely.
* mqueue: enforce MQ name convention
* internal: avoid copying ChannelDescriptor tuples while reading ports in RTT::internal::ConnectionManager
  The ChannelDescriptor contains the ConnPolicy of the connection, which contains a std::string element.
  Copying ChannelDescriptor instances is therefore not real-time safe.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
  Conflicts:
  rtt/internal/ConnectionManager.hpp
* env-hooks: install env-hook to etc/orocos/OROCOS_TARGET/profile.d
  The env-hook sets the OROCOS_TARGET environment variable if not set and adds the lib/orocos directory
  of the install-space and all entries of the CMAKE_PREFIX_PATH (for catkin workspaces) to the
  RTT_COMPONENT_PATH.
  The scripts in etc/orocos/OROCOS_TARGET/profile.de will be sourced in lexical order by a new setup.sh
  script located in the orocos_toolchain repository.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge branch 'toolchain-2.8'
* cmake: updated exact version check semantics for find_package(Orocos-RTT)
  Every version that has the same major version number and at least the
  requested minor version number is considered as compatible. Nothing changed here.
  If an exact version of RTT is requested, the script also accepts it if the patch version
  or the minor version was not specified. If they are, they have to match.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #176 from meyerj/display_thread_names
  Do not abort if pthread_setname_np fails
* Merge pull request #176 from meyerj/display_thread_names
  Do not abort if pthread_setname_np fails
* gnulinux: do not abort if pthread_setname_np fails
  Fixed regression from bc05dceed2f123c35893bf0033d7257373f2f605.
  A failure the set the name of the thread should not lead to the termination of the process.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* corba: removed special cases that depend on the data source type in CorbaTemplateProtocol<T>
  This patch avoids some unnecessary copies during CORBA port write and read calls and during calling, sending
  or collecting operations. Only some of these callers of the CorbaTypeTransporter implementation actually passed
  instances of LateReferenceDataSource<T> or LateConstReferenceDataSource<T>.
  There is no reason to differentiate between different data source types here. The generic API of DataSource and
  AssignableDataSource should be just fine.
  See also related commit 2068263a0c8a32f2e372a00dff2ad60b837f7c71.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* corba: added template arguments Alloc and Compare for RTT::corba::AnyConversion specializations for vectors and maps
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* cmake: fixed version printout and added variable RTT_SOVERSION
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #169 from orocos-toolchain/use_oneway_for_signalling
  corba: use oneway for signalling the remote on pull channels
* corba: use oneway for signalling the remote on pull channels
* Merge branch 'toolchain-2.8'
  Conflicts:
  rtt/base/BufferLockFree.hpp
* Merge branch 'toolchain-2.8-bugfix-release' into toolchain-2.8
* 2.8.3
* tests: make slave_test more robust (fix occassional errors on Travis)
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #146 from meyerj/fix-bool-sequence-type-info
  Fixed typekit for bool sequences
* Fixed build when sequential activity is used by default
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* tests: fixed missing character in testThreadName
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #128 from pdima/display_thread_names
  Set thread name to match activity name on linux
* Merge pull request #127 from pdima/timer_fix
  Timer: fixed wake up time on 32 bit systems
* Merge pull request #129 from pdima/skip_late_updates
  Skip task/timer updated if late for more than a few periods
* .travis.yml: removed ROS bootstrapping from Travis config and switch to trusty
* Fixed potential double deallocation and pool corruption for circular BufferLockFree
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* tests: fixed CORBA ipc tests and made corba tests resilient against future changes in CConnPolicy struct
  This reverts commit 53d7559fefbf52b9fb1a08cf961967bb45bd808f.
  CConnPolicy has no default constructor (at least with OmniORB), so added fields may have left uninitialized with the previous implementation.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #113 from orocos-toolchain/self-deactivating-fsm
  scripting: added missing zero-pointer checks in StateMachine::executePending()
* Merge pull request #112 from meyerj/fix-corba-ipc-server
  tests: fixed typos in corba and mqueue ipc tests that caused segfaults
* Merge pull request #115 from meyerj/added-version-comparison-macro
  Added version comparison macro
* Merge pull request #132 from meyerj/fix/thread-destructor-invalid-read
  Fixed invalid read of freed thread name in os::Thread destructor
* Merge pull request #110 from meyerj/select-reader-channel-optimization
  Slight optimization of reader channel selection for input ports
* Merge pull request #152 from meyerj/remove-ros-traces
  Removed traces of ROS support directly in RTT
* Merge remote-tracking branch 'origin/stable'
* Merge pull request #154 from planthaber/gcc_version
  copied gcc version matching part from master
* Merge pull request #157 from meyerj/install-rpath-fixes
  useorocos: fix RPATH issues when linking to ocl or 3rd-party libraries
* Merge pull request #158 from orocos-toolchain/property-set-data-source-feature
  Added method setDataSource() and assignment operator to the PropertyBase interface
* Merge pull request #163 from meyerj/fix-propertybag-decomposition
  Fixed decomposition of PropertyBags which contain types that implement the TemplateCompositionFactory interface
* Merge pull request #162 from orocos-toolchain/lazytk
  Added option, to load typekits on demand
* Merge pull request #148 from meyerj/fix-circular-buffer
  Fixed potential double deallocation and pool corruption for circular BufferLockFree
* Merge branch 'master' into fix-circular-buffer
  Conflicts:
  rtt/base/BufferLockFree.hpp
* tests: make slave_test more robust (fix occassional errors on Travis)
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge remote-tracking branch 'meyerj/fix-propertybag-decomposition' into toolchain-2.8
* Fixed decomposition of PropertyBags which contain types that implement the TemplateCompositionFactory interface
  RTT::types::decomposePropertyBag() did not retain the type of the PropertyBag returned by RTT::types::TypeInfo::decomposeType(),
  which is implemented in subclasses of TemplateCompositionFactory, and therefore the subsequent composition did not recognize the
  original type. The KDL typekit implements composition and decomposition using that method. The fallback method of property
  decomposition implemented in types::propertyDecomposition() using getMember() is not affected by this issue and sets the type
  of the target bag correctly.
  The updated test in RTT cannot easily cover this case, because no RTT core typekit implements the TemplateCompositionFactory
  interface.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #146 from meyerj/fix-bool-sequence-type-info
  Fixed typekit for bool sequences
* Added option, to load typekits lazy
* tests: fixed printing of data source pointers
  ...due to overloaded stream operator for shared pointer types in rtt/internal/DataSourceBase.hpp.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* tests: added checks for property linking and fixed property update and copy checks
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Added method setDataSource() and assignment operator to the PropertyBase interface
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: restore pre-2.8 behavior by enabling INSTALL_RPATH_USE_LINK_PATH
  INSTALL_RPATH_USE_LINK_PATH was disabled in 85fc9d3f0bbb6fe31c81b97b7df8c2a49160dfb0 because it breaks
  installations where the linked libraries are not yet installed at their final location. This patch
  restores this behavior by default, but also adds a cmake options ORO_INSTALL_RPATH_USE_LINK_PATH to
  explicitly enable or disable it.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: fixed INSTALL_NAME_DIR and MAXOSX_RPATH target properties for Mac OS
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: added OROCOS-OCL_LIBRARY_DIRS to the default RPATH for all Orocos targets
  This patch fixes dynamic linker errors if OCL libraries have been found without the
  orocos_use_package() macro, e.g. with
  find_package(OROCOS-OCL REQUIRED COMPONENTS ocl-logging ocl-timer)
  target_link_libraries(foo ${OROCOS-OCL_OCL-LOGGING_LIBRARIES} ${OROCOS-OCL_OCL-TIMER_LIBRARIES})
  In this case USE_OROCOS_LIBRARY_DIRS will not contain the OCL library dirs and they are
  not added to the INSTALL_RPATH property in orocos_set_install_rpath().
  The orocos_library() macro still contained a copy of the default RPATH which has been moved to
  the orocos_set_install_rpath() macro in e8205f62ef70dd948e580de6f18d276277d19a68.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #142 from eberghoefer/addDisconnect
  Implement CORBA disconnect(port).
* Implement CORBA disconnect(port).
  Disconnect from certain port.
  missing logger init added.
  adding tests.
  leaving out disconnect of local to remote ports and vice versa, for now.
  tests: force non-local connection in testRemotePortDisconnect
  This commit amends PR https://github.com/orocos-toolchain/rtt/pull/142.
  I also replaced the createConnection() calls by connectTo(), which is a more generic method and is also available for input ports.
  createConnection() should imho not be part of the public OutputPortInterface API. At the end, connectTo() always calls output->createConnection(input).
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
  RemoteInputPort disconnect from local output port, now works (changed test accordingly)
  typo removed.
* copied gcc version matching part from master
* Removed traces of ROS support directly in RTT
  Everything related to ROS has been moved to the rtt_ros package in https://github.com/orocos/rtt_ros_integration
  since version 2.7.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Fixed potential double deallocation and pool corruption for circular BufferLockFree
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge branch 'pdima-default_sequential_activity_fix'
* Fixed build when sequential activity is used by default
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* types: added missing implementation of RTT::types::get_container_item_copy(const std::vector<bool> &, int)
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Added missing virtual destructors
* StreamFactory: added missing virtual destructor
* Merge branch 'display_thread_names'
* tests: fixed missing character in testThreadName
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #128 from pdima/display_thread_names
  Set thread name to match activity name on linux
* os: trim pthread name to the last 15 characters of the Orocos thread name and added a test
  As suggested by @jmachowinski in https://github.com/orocos-toolchain/rtt/pull/128#issuecomment-171686223.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #127 from pdima/timer_fix
  Timer: fixed wake up time on 32 bit systems
* Revert "added ability to load a plugin using a operation on a task."
  This reverts commits 9011cf9615dfdd6db02c4781c9bd38de76ebad12
  and 9c9e008f74d87e4b352d0294f5bda47b1c1550ef.
* os: fixed invalid read of freed thread name in os::Thread destructor
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #129 from pdima/skip_late_updates
  Skip task/timer updated if late for more than a few periods
* Merge pull request #131 from jmachowinski/fix_dropped
  Fix concurrency issue with droppedSamples
* .travis.yml: removed ROS bootstrapping from Travis config and switch to trusty
* BufferLockFree: Fix concurrency issue with droppedSamples variable
  This commit replaces the droppedSamples with a concurrency save
  variant, fixing possible wrong counts.
* AtomicInt: Make read const
* Merge pull request #130 from jmachowinski/warning_fix
  fix compiler warning (signess)
* fix compiler warning (signess)
* Skip task/timer updated if late for more than a few periods
  When the system time is changed ahead due to ntp/time zone/daylight/etc changed,
  it's better to skip updates than to run all the activities and timers
  continuously to catch up all the missing updates.
* Set thread name to match activity name on linux
  It simplifies debugging and allows to associate threads
  with tasks/activities
* Timer: fixed wake up time on 32 bit systems
  The existing comment is right:
  We can't use infinite as the OS may internally use time_spec, which can not
  represent as much in the future (until 2038) // XXX Year-2038 Bug
  but used value of InfiniteNSecs/4 exceeds max in32 seconds.
  Changed to use value to be converted within max int32 seconds.
* Merge pull request #90 from jmachowinski/introspection2
  Second Introspection implementation
  As No one complained, and it has been some time, I'm merging this
* Bumped version to 2.8.2 for ocl bugfix release
* tests: fixed CORBA ipc tests and made corba tests resilient against future changes in CConnPolicy struct
  This reverts commit 53d7559fefbf52b9fb1a08cf961967bb45bd808f.
  CConnPolicy has no default constructor (at least with OmniORB), so added fields may have left uninitialized with the previous implementation.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Added macro RTT_VERSION_GTE(major,minor,patch) to rtt-config.h
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #113 from orocos-toolchain/self-deactivating-fsm
  scripting: added missing zero-pointer checks in StateMachine::executePending()
* Merge pull request #112 from meyerj/fix-corba-ipc-server
  tests: fixed typos in corba and mqueue ipc tests that caused segfaults
* scripting: added missing zero-pointer checks in StateMachine::executePending()
  This is a follow-up of 6537ae7736ba887c25642f76ac96081d04039c5e merged in #64.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* tests: fixed typos in corba_ipc_server.cpp and corba_mqueue_ipc_server.cpp that cause segfaults if RT malloc is enabled
  This is a regression from 180e6905c43cb23a76f588783179e14ff5071caf.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #109 from snrkiwi/refactor-file-descriptor-activity
  Can't deterministically control execution of components in a unit test that explicit depend on FileDescriptorActivity.
* extras: Remove traces of RunnableInterface::WorkReason
  This functionality is not yet on the mainline, and so shouldn't pollute
  the FileDescriptorActivity classes here. Due to this, the
  FileDescriptorSimulationActivity is effectively useless as it can not
  tell why it was woken up with the RunnableInterface changes.
* extras: Fix doxygen comments on FileDescriptorActivity classes
* internal: slight optimization of reader channel selection in class ConnectionManager, avoiding to read from the current channel twice
  Reading from a channel might be expensive, e.g. for remote connections. The reader channel selection always tries to read from the
  current channel (the one with the last successful read) first. There is no need to read that channel again while iterating over all
  channels for the case that first read did not return new data.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* extras: Add simulation of FileDescriptorActivity useful to unit tests
  For unit tests that want to exercise a component which uses/requires a
  FileDescriptorActivity (FDA), the simulation version of FDA can be used
  to a) act as an actual FDA, and b) provide deterministic control of an
  FDA and, in particular, when and how it wakes up the component under
  test. See work(), isUpdated(), and hasTimeout(), in particular, for
  behaviour related to deterministic control by a unit test.
  Have to model both 'period' and 'running' to keep other parts of
  RTT happy, in particular, the TaskContext/TaskCore implementation that,
  in part, relies on isRunning() to make choices on what to do. The period
  is mostly to keep the component under test happy, which may require that
  it be running in a non-perioid activity.
* extras: Refactor FileDescriptorActivity to use new Interface class
  Derive from the Interface class as well as Activity, so that users can
  use either a "real" (ie the existing) FDA or use the simulated FDA (e.g.
  within unit tests that require determinism).
* extras: Add interface class for FileDescriptorActivity
  The interface class provides the basic funcitonality to use
  a FileDescriptorActivity, which would be useful within an
  actual activity implementation as well as an implementation
  that would be used in unit tests of a component.
* Merge pull request #107 from meyerj/fix-106
  Added ORO_WAIT_ABS and ORO_WAIT_ABS constants for all targets
* Added ORO_WAIT_ABS and ORO_WAIT_ABS constants for all targets even if setting the wait period policy is a no-op for them (fix #106)
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #104 from orocos-toolchain/fix-typekit-plugin-version-so
  cmake: add SOVERSION for typekits and plugins
* Merge pull request #100 from phyrog/master
  RTT fails when using gcc5
* Merge pull request #99 from orocos-toolchain/feature/expose_package_prefix
  cmake: also export the package install prefix
* Merge pull request #93 from snrkiwi/optionally-not-output-corba-ior
  corba: Optionally support not emitting IORs if name service not used
* cmake: add SOVERSION for typekits and plugins
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Bumping version for release
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Merge pull request #101 from orocos-toolchain/master
  Update toolchain-2.8 for new patch release.
* Merge pull request #88 from goldhoorn/cxx_flags_fix
  Removed setting env flags to cmake variables XXXX_FLAGS_ADD
* Merge pull request #103 from orocos-toolchain/clang-boost
  boost lambda ist not working for boost 1.57 and clang 3.4, 3.5, 3.6, …
* Cmake: Moved USE_CXX1 selection after incluide of orocos-rtt.cmake
* boost lambda ist not working for boost 1.57 and clang 3.4, 3.5, 3.6, apple clang
* Merge pull request #102 from orocos-toolchain/toolchain-2.8
  prevent ROS generated messages linking
* Merge pull request #92 from ahoarau/catkin_generated_msgs_fix
  prevent ROS generated messages linking
* Cleanup of CMAKE\_**_ADD flags.
  See: https://github.com/orocos-toolchain/rtt/pull/88
  This causes a set of COMPILE_OPTIONS with CXX flags.
  This causes that tlsf.c got compiled with cxx options.
  Which is failing with cxx11.
  The env settings of CMAKE_XXX_FLAGS is applied by default to all
  packages. There is no reason to add it to custom variables.
* Merge pull request #94 from goldhoorn/cxx11
  Fixed some C++11 Incompatibilities
* Merge pull request #95 from meyerj/fix-bool-composition
  typekit: fixed composition of type bool
* Make rtt ready for gcc5
* Fix indentation
* cmake: also export the package install prefix
  Use case: to build CORBA typekits you need the full path to the /include/orocos//transports/corba,
  as the include_dirs might consist of multiple paths, include_dirs cannot be used for this purpose. The prefix path can
  be used instead in this use-case.
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* ConnectionManager : Make lock and unlock const
* Added interface to lock and unlock the ConnectionManager mutex.
  This is needed to be able to safely traverse the channel
  elements that are managed by the connection manager.
* TaskContext::loadPlugin: use PluginLoader::loadPlugin instead of loadLibrary
  As we don't have any information, were on the machine the plugin is installed,
  we need to use the RTT plugin discovery mechanism.
* ChannelBufferElementBase: Added method getNumDroppedSamples()
  Returns how many samples were dropped by this buffer element.
  Pretty useful for debugging.
* bugfix: export ChannelBufferElementBase as public base class
  Without this, we can not down/up-cast to the base class.
* added new method dropped() to BufferBase / implemented it in concrete cases
  This method allows us to find out, how many samples were dropped
  by this buffer. This information is very useful for introspection,
  in order to identify bottlenecks in the flow graph.
* added ability to load a plugin using a operation on a task.
* Bugfix : Return correct remote and local URI in Corba and MQueue Channel Elements.
  We need to differentiate between the input and the output element case,
  and return the URI in respect to the cases.
* Added base class for ChannelBufferElement
  This baseclass allows us to cast up to it in the templated
  case if we don't know T. Thus it allows to inspect the
  buffer statistics.
* Added Connection tracing ability.
  This patch modifies the ChannelElementBase in order to inject
  information that can be used to trace back the connections between
  the ports.
* Merge pull request #97 from orocos-toolchain/rock-rc
  Automatic rock-release PR: integrate rc-patches in master
* Fixed some C++11 Incompatibilities
* typekit: fixed composition of type bool
  The BoolTypeInfo that overwrites the streaming operators for type bool did not inherit from StdTypeInfo<bool>,
  but directly from TemplateTypeInfo<bool,true>. Therefore the default composition factory methods composeType() and
  decomposeType() where not overwritten and composition/decomposition of PropertyBags containing bool properties failed.
  Also deleted header file StdPrimitiveTypeInfo.hpp as it is unused and was probably replaced by StdTypeInfo.hpp.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* corba: Optionally support not emitting IORs if name service not used
  A component that acts as a COBRA server, but that is not registering with the name
  service, will cause an IOR to be output to the deployer console and the IOR to
  be written to a file in PWD. This behaviour is not desirable in all app's.
  This makes the behaviour optional in RTT, by providing a global option to
  disable the IOR emission (defaults to OFF, to keep backwards compatibility).
  When not emitting then the IOR is not written to stdout nor to file.
* Fixed naming of constants in documentation of RTT::InputPort
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* prevent ROS generated messages linking
  This removes ROS generated messages from the exported libraries that
  might cause issues when auto-linking is enabled.
* Merge remote-tracking branch 'meyerj/fix-fda-blocking-trigger'
* Merge remote-tracking branch 'autobuild/rock1408'
* Revert "rtt: Use virtual destructor for OperationCaller"
  This reverts commit ca7e51098fd6bb2392bd312ced759876c19ddde5.
  It was accidentally pushed and should be replaced by abb8ecee57a5e81e6c99fdd91e9f22ef32ab7051.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* rtt: Add virtual destructor to OperationCallerBaseInvoker
  It has virtual functions but not a virtual destructor, which leads
  to build errors with XCode 6 on OS X 10.9.
* rtt: Use virtual destructor for OperationCaller
  It has virtual functions but not a virtual destructor, which leads
  to compile errors with certain compilers and options.
* timer: make internal struct RTT::os::Timer::TimerInfo CopyConstructible and Assignable
  This is required to store it in a std::vector and fixes a compile error in Mac OS Mountain Lion with clang 5.1 and Boost 1.56.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* cmake: suppress cmake policy CMP0042 warning in CMake >= 3.0.2
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: fixed INSTALL_NAME_DIR and MAXOSX_RPATH target properties for Mac OS
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* extras: added missing initializers to one of the FileDescriptorActivity constructors and fixed compiler warnings with -Wunused-result
  The missing initializers had no effect as these boolean flags are reset in start() anyway.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* globals: added ORO_WAIT_ABS and ORO_WAIT_REL to the GlobalsRepository
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* package.xml: unified maintainer name in package.xml across orocos-toolchain packages
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge remote-tracking branch 'origin/fix-corba-read-old-data'
* corba: fixed reading from remote channels with old data and copy_old_data flag set to false (fix #83)
  If the remote ChannelElement::read(sample, false) method does not set the sample reference because there
  are no new data available, the read CORBA call should return an empty Any object instead of converting the
  default value of the ValueDataSource to Any.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* types: fixup BoolTypeInfo, cleanup PrimitiveTypeInfo
  BoolTypeInfo did not pass on it was providing ostream functions.
  TemplateTypeInfo contained dead code that belonged in TypeInfo.
  Signed-off-by: Peter Soetens <marieke@intermodalics.eu>
* types: only add a streamFactory if use_ostream is true
  This was a bug in PrimitiveTypeInfo which caused it to register
  a streamfactory handler which can't print the type contents in
  case use_ostream was set to false. typegen for example leaves
  use_ostream to false, causing it to install defunct stream
  factories.
  Signed-off-by: Peter Soetens <marieke@intermodalics.eu>
* os/thread: fix error log to printout the correct timeout
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Merge pull request #80 from jmachowinski/master
  Allow the construction of an uninitialized TaskContextProxy
* Merge pull request #76 from meyerj/timer-waitfor
  Added os::Timer::waitFor(...) and os::Timer::waitForUntil(...… …) member functions
* Merge pull request #78 from meyerj/fix-fda-blocking-trigger
  Fixed blocking trigger() calls on FileDescriptorActivities if the step() function takes too long
* Merge pull request #79 from meyerj/destdir-support-same-workspace
  Extended DESTDIR support for packages built in the same workspace
* re-add return statement removed during refactoring in 0e1ead2db346
* Allow the construction of an uninitialized TaskContextProxy
  This is useful if a derived class wants to initialize the
  typekits, before initializing the Proxy itself.
* Allow the construction of an uninitialized TaskContextProxy
  This is useful if a derived class wants to initialize the
  typekits, before initializing the Proxy itself.
* useorocos: do not add devel/lib/pkg-config to the PKG_CONFIG_PATH anymore
  This commit reverts 40bbd086e9fa00e7d0b7e10da90135e89532963d.
  This should not be required anymore as packages in the same cmake workspace are found by the
  `${PACKAGE}_EXPORTED_OROCOS\_*` cmake variables now.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: extended DESTDIR support for the case where multiple packages are built in the same cmake workspace
  This patch extends and simplifies the DESTDIR support introduced in 85fc9d3f0bbb6fe31c81b97b7df8c2a49160dfb0.
  It should have no effect on normal builds where the DESTDIR environment variable is not set.
  The original patch assumed that DESTDIR is already set during the configure step, like with
  ```
  DESTDIR=/tmp/destdir catkin_make_isolated --install ...
  ```
  In a pure catkin workspace packages can be built for a whole workspace with a standard debian/rules file
  and debhelper's support for the cmake build system. In this case DESTDIR is only set during the install step
  and the previous patch was not effective, causing RPATH-related errors during runtime.
  The INSTALL_RPATH is still constructed based on the information from the pkg-config files for packages in
  *overlayed* workspaces or system packages. Additionally, libraries built in the *same* workspace will now export
  their library dirs in the *install-space* via the cmake cache so that other targets that link to it can already
  set their RPATH correctly.
  In order to make sure that no paths within DESTDIR end up in the installed RPATH of any library, a new cmake macro
  `orocos_set_install_rpath(target rpath)` has been introduced that cleans up all entries in the rpath list and
  removes duplicates. This could be an issue if RTT itself is installed in DESTDIR together with other packages, as
  `OROCOS-RTT_LIBRARY_DIRS` would have the DESTDIR prefix.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* tests: added test for waiting on timers
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* timers: waitFor(id) and waitForUntil(id) return true if the timer was killed or the activity was stopped
  There is no easy solution to detect these corner cases reliably.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* extras: fixed blocking trigger() calls on FileDescriptorActivities if the step() function takes too long
  A pipe in Linux seems to have a limited buffer size of 65536 bytes. Every trigger() has written a command byte to
  the pipe to wakeup the thread and the loop() function empties the command before each step() invocation. For the
  case the step takes too long, commands could queue up and after the pipe is full the write() system call has
  blocked the thread that triggered the FileDescriptorActivity.
  This patches makes the command pipe non-blocking and adds additional flags to the FileDescriptorActivity to make
  sure that we never miss a command event even if the queue was full.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* corba: Make RemoteChannelElement re-entrant
  This was necessary for the new CORBA one-way api, in which it is possible that multiple data samples arrive in parallel
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
  Conflicts:
  rtt/transports/corba/RemoteChannelElement.hpp
* timers: added os::Timer::waitFor(...) and os::Timer::waitForUntil(...) member functions
  This is needed for the implementation of `OCL::TimerComponent::wait()` and `OCL::TimerComponent::waitFor()`.
  See https://github.com/orocos-toolchain/ocl/issues/23.
  The value type of the protected mtimers vector was changed from `std::pair<Time,Time>` to a new struct `TimerInfo`,
  which additionally contains a condition variable that is broadcast when the timer expires.
  This patch also fixes a bug that caused the Timer::loop() function to exit immediately if the Timer is
  stopped and started again as the `mdo_quit` flag was not reset in initialize().
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge remote-tracking branch 'origin/toolchain-2.8'
* timers: fixed index checks in os::Timer
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* scripting: disable events in StateMachine::deactivate() and add mutex protection to StateMachine::activate()
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* scripting: first check if we are still loaded before we try to remove ourselves
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Merge pull request #75 from meyerj/carray-assignment-operators
  types: added assignment operators to RTT::types::carray to assign from boost::serialization::array and boost::array
* Merge pull request #74 from meyerj/new-activity-constructor
  Added a new Activity constructor
* Merge pull request #73 from meyerj/taskcontext-clear-service-requester
  Clear service requester in TaskContext::clear()
* Merge remote-tracking branch 'origin/fix-61'
* Merge remote-tracking branch 'origin/self-deactivating-fsm'
  Conflicts:
  tests/state_test.cpp
* types: added assignment operators to RTT::types::carray to assign from boost::serialization::array and boost::array
  The `boost::array` operator is required to assign an array data source from a `boost::array`, e.g. a fixed-sized
  field of a ROS message. The `boost::serialization::array` assignment operator was added for completeness as carray also
  has a `boost::serialization::array` constructor.
  The value type of the RHS of the assignment may differ from the value type of the carray as long as the elements are assignable.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #71 from meyerj/slave-activity-fixes
  Finally fixing the SlaveActivity message processing
* Added an Activity(int scheduler, int priority, ...) constructor
  Otherwise, the contructor call `Activity(ORO_SCHED_RT, os::HighestPriority)` would interpret the second
  argument as a double period time and ORO_SCHED_RT as a priority, which can lead to very strange and unforeseen
  results.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* taskcontext: also clear service requester in TaskContext::clear()
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Removed CHANGELOG.rst as it is not maintained anyway
* bumped version to 2.8.0
* Merge branch 'slave-activity-fixes' of https://github.com/meyerj/rtt into toolchain-2.8
* ExecutionEngine: moved message forwarding to master to the top of ExecutionEngine::process()
  The forwarding does not require that the slave engine has an activity.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* ExecutionEngine: do not forward waitForMessagesInternal() and waitAndProcessMessages() calls to master engine
  waitForMessagesInternal() is also used by waitForFunctions() and thus would wait for the wrong condition variable.
  Forwarding waitForMessages() to the master should be sufficient for processing operations in slave engines.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* rtt: moved isRunning() check from TaskContext::dataOnPort() to default TaskContext::dataOnPortHook()
  This allows the user to decide in an overwritten dataOnPortHook() implementation whether the user callbacks
  should be enqueued or not, indepedent of whether the component is running or not. Note that the callbacks are
  not executed until the component is started unless #70 is merged.
  See https://github.com/orocos-toolchain/rtt/commit/d03c66b69912714b851818d471beb3282f19bad3#commitcomment-8247917.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* tests: added slave_test to test operation calls between components running in a SlaveActivity
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Fixed setting of the master engine when assigning a SlaveActivity to an ExecutionEngine
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #51 from orocos-toolchain/destdir-support
  Added DESTDIR support for staged installs
* cmake/useorocos: added DESTDIR support for staged installs
  * DESTDIR is prepended to all include and link directories found by pkg-config
  * OROCOS-RTT_LIBRARY_DIRS variable added to OROCOS-RTT cmake config for RTT core libraries, plugins and typekits
  * Removed INSTALL_RPATH_USE_BUILD_PATH flag
  * INSTALL_RPATH is constructed from USE_OROCOS_LIBRARY_DIRS_WITHOUT_DESTDIR and OROCOS-RTT_LIBRARY_DIRS
  See also: https://www.gnu.org/prep/standards/html_node/DESTDIR.html
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* rtt: do not invoke user callbacks or trigger the component if the component is not running
  This commit fixes issue https://github.com/orocos-toolchain/rtt/issues/61.
  Additionally, a new dataOnPortHook() is introduced that can be overwritten by the user to influence
  whether the component is triggered or not.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* tests: fixed "will be initialized after" compiler warning in state_test
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* corba: update to new SendStatus enum which contains CollectFailure
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge pull request #65 from orocos-toolchain/provide_engine_in_corba_operation_calls
  corba: explicitly provide GlobalEngine::Instance when calling operations
* Merge pull request #62 from meyerj/global-service-named-plugin
  Added ORO_GLOBAL_SERVICE_PLUGIN macro to ServicePlugin.hpp
* Merge pull request #60 from orocos-toolchain/fix-59
  SlaveActivity without master ExecutionEngine (pull request)
  Functionally, the old behavior remains, but we delegate the responsibility from SlaveActivity to ExecutionEngine. Please yell if this breaks your case, but we believe it doesn't. The fatal error in the slave's trigger() function really needed to go since a slave without a master is quite valid.
* Merge pull request #55 from snrkiwi/support-orocos-application-tests
  cmake: Support configuring executables for Orocos
* Merge pull request #68 from psoetens/master
  Fix state_test failure by fixing StateMachine responding to signals
* corba: explicitly provide GlobalEngine::Instance when calling operations
  This fixes calling operations after dc81be1
  Operations now must have an explicit engine assigned, but the CORBA
  layer was still passing the NULL engine (which was defaulting to
  GlobalEngine()).
* scripting: protect FSM execution and tracing against self-deactivation
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* scripting: allow parsing of keywords at the end of a parse string.
  The Taskbrowser refused to parse 'foo=true' because keywords implicitly assumed something
  was after it. Users had to write 'foo=1' to work around this. Now we allow to parse a keyword
  at the end of a line or end of parse string.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: force user to set the caller when collecting is done.
  In order to save users from debugging deadlocks, force them to declare the
  caller when using collect(), directly or indirectly. Does not influence send()
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: extended plugins_test to include global service plugins
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* plugin: added ORO_GLOBAL_SERVICE_NAMED_PLUGIN for service plugins that want to install a global service
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* ExecutionEngine: forward incoming messages to a master ExecutionEngine if set
  The master ExecutionEngine is set automatically if the engine runs in a SlaveActivity whose master activity also runs an ExecutionEngine.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Revert "SlaveActivity"
  This reverts commit ed1d5f3f35221c3cb412fb1f002e5a3ede34055b.
* Revert "extras/slaveactivity: fix potential segfault if no master activity is set"
  This reverts commit e1559a65b19cca6a695f33f9c51a4268ac8c864b.
* Merge remote-tracking branch 'origin/rpath-mess'
* Merge remote-tracking branch 'meyerj/fix-timers'
* Merge remote-tracking branch 'origin/toolchain-2.7' into HEAD
* Merge remote-tracking branch 'origin/slave_activity_fix' into HEAD
* Merge remote-tracking branch 'meyerj/operationcaller-assignment-fix' into HEAD
* cmake: add all standard rpaths for all kind of targets to all kind of targes
  Since the rpath_use_link_paths cmake option does not work on OSX with cmake < 3.0 this is a way to make sure that in-project targets can link with eachother.
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* cmake: Support configuring executables for Orocos
  Instead of forcing the ADD_EXECUTABLE() and INSTALL() calls on the user,
  this allows them to configure an existing executable. This also supports
  configuring tests that require Orocos.
* extras/slaveactivity: fix potential segfault if no master activity is set
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* ports: add clear() to inputport operation object.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: correctly implement asynchronous events in eventTransition
  Before this patch, only the last eventTransition of two consecutive ones took effect,
  since the event data was shared among all subscribers. This patch makes eventTransition
  synchronous again such that each eventTransition evaluates its own data. This requires
  some proper locking in the SM.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: more robust state change scheduling in order to avoid races
  When evenTransition comes into a state machine, this may cause re-writing
  of the entry/running/exit programs currently being executed, becaues the
  event sets these hooks immediately, instead of letting the FSM finish
  the current (entry or exit) program.
  This patch lets changeState schedule a state change, and makes enterstate/
  leavestate effectively do the state change and switch the new state programs in.
  Since changeState now only schedules, in a number of places, the executePending()
  function needs to be called to effectively execute SM statements.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* docs: fix bug in documenting port reads + add section on level events with ports.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* revert change caused by commit 2c7c2c8e until we have a solution.
  This reverts the behavior of getNSecs so to always return rtos_get_time_ns(),
  like it did before.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* revert the removal of the GlobalEngine bookkeeping. This belongs in another patch
  This reverts one hunk of commit 00e748c5498865d210074d6fd618fca49941d355.
* timers: use rtos_get_time_ns() directly bypassing the TimeService
  TimeService normally counts time from zero, while rtos_get_time_ns() uses CLOCK_REALTIME directly.
  Timers are using semaphores internally which can only handle CLOCK_REALTIME.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* os: also cleanup the TypeInfoRepository in __os_exit
  When parts of the TIR use TLSF, the TIR would be cleaned up after
  the TLSF cleanup, causing asserts / segfaults.
  fixes #49 on github
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix bug where SM was installing synchronous operation callbacks
  this->getEngine() is still null when building the SM, so the intent
  of the code never happened.
  Added extra argument to createEventTransition to get the target EE
  where this SM wil run in, such that an asynchronous callback is
  created.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* config: allow user to also define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG on a global level
  If the user includes posix time headers himself, he'll need to define
  BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG in order to enable these features
  for our code as well.
  Alternatively, we could modify the RTT code to work in both cases, if this is possible.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: relax timer tests in order to avoid false failures.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* os: fixed getNSecs which did not return anything meaningful.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Do not reset the caller engine in OperationCaller assignment
  Use case:
  RTT::OperationCaller<bool()> op("bar", this->engine());
  op = this->getPeer("foo")->getOperation("bar");
  assert(op.mcaller);
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #47 from snrkiwi/fix-rpath-on-osx-cmake3
  cmake: Fix OS X RPATH issue with CMake 3.0
* cmake: Fix OS X RPATH issue with CMake 3.0
  CMake 3.0 defaults on RPATH support and in conjunction with a bug
  in the system install_name_tool, causes corrupt libraries and
  executables.
  This sets the RPATH correclty on OS X w/ CMake 3.0, and omits the
  explicit RPATH entry for the install path. The install path is
  automatically (and silently) added by CMake itself, which was
  causing duplicate RPATH entries which excited the bug in
  install_name_tool.
  Tested on
  - OS X 10.8.5 w/ CMake 3.0.0 and XCode 5.1.1
  - OS X 10.8.5 w/ CMake 2.8.12 and XCode 5.1.1
  - Linux Mint 15 w/ CMake 2.8.12 and gcc/g++ 4.8.2.
* Merge pull request #42 from smits/remove-duplicate-rpaths
  cmake: remove duplicate rpath settings for Apple
* Merge pull request #45 from psoetens/master
  os: update oro_allocator to be copy-able. Required for newer compilers.
* useorocos: fixed recursive orocos_find_package() for rosbuild packages
  This is a regression of 5c14c5d6291375d9e790a92d01a766d4bdc9b2b9.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* os: update oro_allocator to be copy-able. Required for newer compilers.
  We first discovered this on Mac OS-X 10.9
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: remove duplicate rpath settings for Apple
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Merge pull request #41 from smits/osx-typegen-rt_string
  osx: switch of boost chrono to allow typegen-generated typekits using rt_string
* Merge pull request #38 from smits/master
  Fix visibility flag for clang and intel compilers
* cmake: enable the visibility flag also for clang and intel compilers, needed if you use the rtt/typekit/Types.hpp explicit instantiation header
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Merge pull request #39 from smits/rt_string-typekit
  typekit: include explicit instantiation for rt_string based RTT classes ...
* Merge pull request #37 from smits/explicit_instantiation
  Explicit instantiation
* Merge pull request #40 from psoetens/master
  tests: don't require that a fd activity is running right after component...
* osx: switch of boost chrono to allow typegen-generated typekits using rt_string
  Signed-off-by: Ruben Smits <ruben@intermodalics.eu>
* tests: don't require that a fd activity is running right after component start
  Since components trigger when started, the fd activity is shortly running.
  Travis found this from time to time.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge pull request #36 from orocos-toolchain/bugfix_reset_port_interface_on_removal
  set a port's interface to 0 when it gets removed
* typekit: include explicit instantiation for rt_string based RTT classes in the rtt-typekit
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* internal: fix for explicit instantiantion of Operations and friends
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* fix constness of setOperationCallerImpl functions
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* set a port's interface to 0 when it gets removed
* Merge pull request #35 from goldhoorn/slave_acttivity_fix
  Slave acttivity fix
* SlaveActivity
  Fixed bug in which case operations within Task's were not called anymore
  if the task is not running, and a slave of another one.
* TaskContext: fixed zero pointer fault
  The our_act could be nil if there is a parent task given for execution.
  In this case our_act->stop() will defnilty fail.
* scripting: fixup parsing of mixed program/function and statement scripts.
  This patch allows to query the programgraphparser if it has seen any valid input at all.
  Also the commonparser was slightly rewritten for parsing identifiers. Some lexeme_d
  directives were ignored because they were stored in a rule_t instead of a lexeme_rule_t
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge pull request #34 from tjadevries/master
  Fix implicit conversion from shared_ptr to bool
* fix implicit conversion from shared_ptr to bool
  C++11 does not approve the implicit conversion, see http://stackoverflow.com/questions/7580009/gcc-error-cannot-convert-const-shared-ptr-to-bool-in-return
* fix implicit conversion from shared_ptr to bool
  C++11 does not approve the implicit conversion, see http://stackoverflow.com/questions/7580009/gcc-error-cannot-convert-const-shared-ptr-to-bool-in-return
* types: removed wrong assert statements in SequenceTypeInfoBase
  The asserts didn't take into account that the bag may contain
  an extra 'Size' element, in which case the bag size and sequence
  size are not the same length.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: cleanup Sequence composition code
  Allows reading xml files where the elements are nameless
  instead of 'ElementN'.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* corba: update corba to fit in with the new-old event api
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* tests: bring corba tests in sync with latest connpolicy changes
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* filedescriptoractivity: fix bug in start()
  start() and trigger() did not guard against accidental
  double calls, causing loop() to never return.
  Also, stop() did not cleanup some fd's in case loop had
  never run.
  Finally, unit tests should start/stop components, not
  activities.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* properties: fix decomposition of enums in structs.
  If decomposeType returned a new dsb, this was
  plainly ignored.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: support responding to peer event operations
  We lifted the limitation that signalling operations need to be ownthread.
  The signal is now always executed in the thread of the reacting task,
  The scripting StateMachine code uses this to support Orocos 1.x style
  events. Each signalled operation call is dispatched to the reacting
  task, together with the arguments of the operation. The limit of
  possibly dispatched signals is the amount of available TLSF memory.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Better detection of xpath usage
  The version of xpath on Fedora functions like the version that Apple has. Instead of making the syntax different only for Apple, parse the xpath usage.
* Fixed memory leak in RTT::PropertyBag::copyProperties()
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Fixed PropertyBag's reference semantic and added PropertyBase::copy() member function
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* rtt: fixed handling of owned properties in assignment operator
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* types: move ConnFactoryPtr in the types namespace (where it was before 281ba20)
* scripting: also allow global-to-global event transitions
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix crash in StateMachine when doing global transitions.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: regroup the TypeInfo headers to reduce dependencies.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* ports: store actual connpolicy object instead of default in input ports
  This is a minor refactoring to allow to pass on the
  conn policy used at the input port level.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: generate typegen typekit in build dir instead of src dir
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Merge branch 'fixes' of git://gitorious.org/orocos-toolchain/snrkiwi-rtt into toolchain-2.7
* logger: Support logging using log4cpp framework
  Supports logging using the log4cpp framework, which replaces logging
  both to file and via printf. The log4cpp option defaults off. This
  fix also ensures that application code is informed of the build option.
* time: Support Second conversions to/from micro- and milliseconds
* tests: Add tests for FileDescriptorActivity
* tests: Remove unused variable warning in property composition test
* tests: Remove unused variable warning in mqueue archive test
* gnulinux: Fix signedness compiler warning
* tests: Avoid compiler warnings
* corba: resurrect rt_string Corba support
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* operations: cleanups of internal API's + improved documentation
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix for runScript not setting the caller correctly.
  It should set the caller EE to the EE in which the script is loaded.
  It used the GlobalEngine() instead, which it must use for plain
  statements.
  In order to distinguish between program scripts and top-level
  statements, two script parsers are used with different callers
  set.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: more state machine operation tests.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: Fix caller thread of parser (serious bug)
  All Parsed scripts were being executed as if the GlobalEngine was calling
  all functions, causing hanging asynchronous operations. I've updated the
  API to allow to specify the GlobalEngine explicitly, or the Engine of the
  owner's TC.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* service: fix compilation error / wrong fix.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: extend state_test with calling operations in all kinds of states.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: also set the executor of an operation when adding to a Service
  One could construct an operation object where the executor engine was never set,
  leading to OwnThread calls blocking forever.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: remove accidental conflict markers in state_test.cpp
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix compiler warning regarding parentheses.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: fix not-signalling-bug in signalling operations
  A faulty copy constructor did not copy the msig pointer,
  leading to the signal function not being called when the
  operation is executed.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: remove accidental addition of services.
  I removed all occurences of provides(foo) in order to prevent
  accidental creation of services.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge remote-tracking branch 'snrkiwi/statemachine-operations' into toolchain-2.7-signalling-ops
  Conflicts:
  tests/state_test.cpp
* states: Fix Operation events not respecting transition order
  Any extra operation event would cause to overwrite the previous operation event while
  still being in the same state.
  Added test case + fix (check for current != next in inTransition)
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* states: fix double Operation event reception in following state transitions
  Several issues were addressed:
  * Event handles did not start in disconnected state
  * Event handles were disabled/enabled too soon, before the state transition took place
  * createEventTransition did not check if the Operation was of type OwnThread
  * We create empty OwnThread Operations by default again (reverts previous commit)
  * FusedMSignal leaked
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* WIP tests: Expand state machine with operations tests
* operations: introduce addEventOperation() and enable ORO_SIGNALLING_OPERATIONS by default.
  The code/compilation time increase is purely because of the boost::fusion code,
  so we eliminate generating that code in addOperation and enable it in addEventOperation.
  In this way, we can provide binary compatible signalling operations without putting
  the burden on users/components that don't use that feature.
  This does introduce an extra shared_ptr in the operation base classes, so excluding
  all this code can still be done by turning ORO_SIGNALLING_OPERATIONS off in cmake.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: Expand state machine test with signals from multiple operations
* service: fixed error message in Service::shared_from_this() for Boost >=1.53
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge branch 'useorocos-catkin-package-xml' of https://github.com/meyerj/rtt into HEAD
* WIP tests: Expand state machine with operations tests
* Merge branch 'servicerequester-refactoring-2' of https://github.com/meyerj/rtt into HEAD
* Merge branch 'file-descriptor-activity-fixes' of gitorious.org:orocos-toolchain/snrkiwi-rtt into HEAD
* Merge branch 'fixes' into pu2
* Revert "import: prefer typekits,plugins and components from preceding paths"
  The PluginLoader does not override already loaded typekit and plugin libraries and it is not required to reverse the path list.
  This reverts commit 1dc3db1b1505eec3441d675d75f9e670b2e5a6ef.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* cmake: UseOrocos/typegen_headers: support multiple dependencies correctly
* useorocos: removed orocos_get_catkin_deps macro and use `${PROJECT_NAME}_BUILD_DEPENDS` as returned by catkin_package_xml()
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge remote-tracking branch 'origin/master' into toolchain-2.7
* cmake: fix typegen --import flags
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Merge remote-tracking branch 'meyerj/useorocos-recursive-package-dependencies'
* ServiceRequesters are managed by shared pointers
  * Use shared pointers to manage ServiceRequester instances internally, like for Services.
  * Added a ServiceRequester::addServiceRequester(shared_ptr) member function to add service
  requesters created elsewhere to the interface (in analogy to Service::addService()).
  * Make ServiceRequester::connectTo() a virtual function so that implementations can
  override it (e.g. to connect ports).
  This commit breaks the ServiceRequester API and needs patches in ocl and rtt_roscomm.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge branch 'fix_import_with_overlays' of git://gitorious.org/orocos-toolchain/rsmits-rtt
* Merge branch 'toolchain-2.7-boost1.53' of git://gitorious.org/orocos-toolchain/peters-rtt
* Merge branch 'pluginloader-rlock' of git://gitorious.org/orocos-toolchain/jbohrens-rtt
* Merge branch 'timeservice-introspection-and-change-ticks' of gitorious.org:orocos-toolchain/jbohrens-rtt
* Replaced the ServiceRequester warning on connection of owner-less OperationCallers with a debug message
  Fix https://github.com/orocos-toolchain/rtt/issues/25.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: Removed INCLUDE_DIRS argument from implicit catkin_package() call in orocos_generate_package()
  ...as suggested in https://github.com/orocos-toolchain/rtt/pull/26#issuecomment-36592348
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* cmake: fix cmake error if DEPS list is empty
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* import: prefer typekits,plugins and components from preceding paths
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* useorocos: Fix typegen options when generating headers
  The logic that produces ORO_TYPEGEN_HEADERS_IMPORTS ensures a
  leading space. This confuses CMake's execute_command() output which
  causes typegen to produce odd errors.
  Typegen expects the -i import option before the project name.
* useorocos: Correctly log dependencies
* Revert "service: fixup shared_from_this saga for setOwner/setParent."
  This reverts commit d46e4beaff3feccdad45252a3cec539ae4580480.
  This patch was an incomplete solution
* service: fixup shared_from_this saga for setOwner/setParent.
  We now catch the bad weak ptr and create the shared_ptr
  ourselves. This is allowed since we know that it is stored
  in the other Service and not destructed at the end of the
  function.
  In addition, for Boost 1.53+. use enable_shared_from_raw which
  has the old enable_shared_from_this2 behavior again.
  See http://stackoverflow.com/questions/22184772/why-is-boostenable-shared-from-raw-so-undocumented
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: document why/where gcc gives a warning.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: remove some obsoleted keywords
  call was a duplicate, sync/async no longer relevant and
  time was too restrictive, since it's only used in a very
  specific syntax.
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* service: fixup shared_from_this saga for setOwner/setParent.
  We now catch the bad weak ptr and create the shared_ptr
  ourselves. This is allowed since we know that it is stored
  in the other Service and not destructed at the end of the
  function.
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* PluginLoader: Making mutex recursive to enable plugins to load other plugins.
* RTT::os::TimeService - Adding accessor to check if system clock is being used and adding function to change clock offset by ticks in addition to seconds
* tests: Avoid compiler warning
* tlsf: Add default memory pool statistic functions
  Without these statistics on the default memory pool are not
  available, as the pointer to the default memory pool ("mp")
  is not externally exposed.
* Make TaskContext::getName() a const function
  THe undelrying function that it calls in Service is a const function,
  and the TaskContext version does not modify anything. Without the const
  some compilers will error out, or produce warnings, when trying to
  get the name of a const TaskContext object, which is wrong.
* extras: Support an intended period in FileDescriptorActivity
  A component querying a FileDescriptorActivity (FDA) will always
  receive back a period=0. This may be invalid if the FDA is actually
  tracking a periodic signal, e.g. say a sync signal from hardware. In
  this case there is a period at deployment time that the component
  is intended to run at, but this is not available to the underlying
  component.
  This adds an intended period and returns that as the period of this
  activity. The default intended period is the same as the actual
  period=0. The actual period remains the same; 0.
* extras: Support pinning a FileDescriptorActivity to a CPU mask
* extras: Support microsecond timeouts in FileDescriptorActivity
  Use microsecond instead of millisecond timeouts. Adds new get/set
  operations that explicitly deal with microsecond level timeouts,
  while leaving the existing millisecond get/set timeout operations.
  Setting a negative timeout is now checked for and prevented.
* extras: Log an error if a FileDescriptorActivity fails to start
  The error simply occurs silently otherwise.
* useorocos: export the targets, libraries and include directories of packages in the orocos_generate_package(DEPENDS ...) list to other packages in the same workspace
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: minor control flow cleanup in orocos_find_package()
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* extras: Initialize work file descriptors in FileDescriptorActivity
  The work FD's didn't have initial values, and so if isUpdated() is
  called before the activity starts it's loop() then junk values are
  returned.
  This zeroes the work FD's during construction.
* Revert "services: also clear DataFlowInterface in Service::clear()"
  This reverts commit 2a254afb04ef4c922d4a9bd80b15c05e9628762c.
  The DataFlowInterface cannot be cleared anymore at this point as the port objects might already be destroyed.
  `DataFlowInterface::removePort()` is purely based on names, but `DataFlowInterface::clear()` calls `getName()`
  on the destroyed port object (invalid read).
  For a clean solution we would have to cache the port names or the pointers to the created port objects in the
  DataFlowInterface...
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* types: fix copy/clone semantics of PartDataSource classes
  It never worked. it kept returning the data in the old parent, instead of the
  newly created parent. It took some pointer calculus to get the reference in the
  new parent. The unit tests seem to agree with this patch.
  The never used OffsetPartDataSource is no longer necessary then, because the
  normal parts now calculate the offset themselves.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* partially revert commit 526bbf75cde567a3dcd793fd6b9f1209dcedfabd
  The modification is probably ok, but this is not the right time to do it
  (breaks ABI)
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fix bugs in ports unit test
  Remove a port from the TC before it gets destroyed/dangling.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix crash of skip parser definition
  The parsers were not saved on the stack, causing a segfault later-on.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: add two unit tests to reproduce reported parser bugs
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: export typekit plugin and include directory in orocos_typegen_headers() macro
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge branch 'toolchain-2.7'
* scripting: Allow to query the PeerParser for a succesful match
  Without this new foundPath() function, it would be impossible to find out
  if any parsing was possible at all. Used by the TaskBrowser.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix accidental insertion of empty scripting service into TaskContext.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: create unit test to check commenting in state machines.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Add catkin detection for catkin_make_isolated
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Merge branch 'enable_autolinking_for_catkin' of https://github.com/meyerj/rtt into toolchain-2.7
* useorocos: re-enable auto-linking also for catkin builds
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: fixed installation of empty directory for packages if DESTDIR environment variable is set (required for building Debian packages)
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* corba: check if local port is added to a DataFlowInterface before we continue
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Merge branch 'xpath-error-with-ros' of gitorious.org:orocos-toolchain/jbohrens-rtt
* Merge branch 'empty-package-install-target' of gitorious.org:orocos-toolchain/jbohrens-rtt
* Merge branch 'master' of gitorious.org:orocos-toolchain/jbohrens-rtt
* taskcontext: TaskContext::connectServices() always returned true
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* service: fixed initialization, missing definition and a typo in ServiceRequester/OperationCaller classes
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Moving empty install directory generation up so that it always runs if catkin is being used
* make some hidden scheduler/policy choices explicit
  Here and there in RTT there is a thread spawned to do some work.
  The parametrization of these threads are static and the creation
  of the thread is well hidden.
  This commit makes two of these threads apparent, and allows for
  explicit parametrization.
  It keeps ABI compatibility.
* cmake: do not complain about catkin not being found
* remove unused typedef
* UseOROCOS: Switching xpath detection warning to error if building with rosbuild or catkin
* tests: fix unit test which adds ports in various daring ways.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* service: fix adding a service to the global service
  The global service has no owner, so the parent was not set either.
  We now try to set the parent and fail if that is impossible. The
  owner is only set if one is present.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* marsh: support marshalling services and being loaded in the GlobalService
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* UseOrocos: Adding install target to create empty directories if someone calls orocos_generate_package without any contents. This will enable the package to be found by the componentloader.
* ComponentLoader: Adding better RTT Logger descriptions to import functions to help when debugging import errors.
* env-hooks: use the cmake prefix path as a source for the RTT component path
  Signed-off-by: Ruben Smits <ruben@intermodalics.eu>
* Merge branch 'toolchain-2.7' of https://gitorious.org/orocos-toolchain/rtt into toolchain-2.7
* cmake: use catkin_add_env_hooks() macro to install catkin env-hooks if available
* Merge branch 'even-more-useorocos-updates' of https://github.com/meyerj/rtt into toolchain-2.7
* Merge branch 'useorocos-auto-linking-rosbuild-updates' of https://github.com/meyerj/rtt into toolchain-2.7
* useorocos: readded presence of package.xml as a condition to select catkin buildsystem and allow to override the automatic choice by setting cmake variables manually
* Merge branch 'gmaster' of git://gitorious.org/orocos-toolchain/jbohrens-rtt into toolchain-2.7
* Merge branch 'master' of git://gitorious.org/orocos-toolchain/doudou-rtt into toolchain-2.7
* travis config: Fixing ros bootstrap checkout url
* Merge branch 'master' of https://github.com/meyerj/rtt into toolchain-2.7
* cmake: suppress output in orocos-rtt-config.cmake in QUIET mode
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge branch 'even-more-useorocos-updates' of https://github.com/meyerj/rtt
* useorocos: auto-linking is done on a per-target level in the orocos macros instead of linking globally in orocos_use_package()
  link_libraries() is deprecated in cmake: "Use TARGET_LINK_LIBRARIES unless you have a good reason for every target to link to the same set of libraries."
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: removed link_directories(CMAKE_CURRENT_BINARY_DIR) introduced in eceb1b4941d4acb93b18cd02ff5a4d3f2a99b2dc
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: compiler flags and linker flags set in UseOROCOS-RTT.cmake have been overridden by orocos_use_package()
  * Also add compiler and linker flags in orocos_typekit() (was missing).
  * We only use the new USE_OROCOS_CFLAGS_OTHER USE_OROCOS_LDFLAGS_OTHER macros now.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: check USE_OROCOS_RTT to not parse the UseOROCOS-RTT.cmake file twice
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* TinyDemarschaller: in endElement() print error msg if TAG_SIMPLE is of unknown type + in populateBag() print error msg with error line number
* useorocos: updated output and doc strings for the case rosbuild-style was selected based on the ORO_USE_ROSBUILD cmake variable
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: always store OROCOS_NO_AUTO_LINKING in the cache and check ORO_USE_ROSBUILD variable to enforce rosbuild-style builds
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: minor update to @jbohren's patch in a244593786bce8a6d0fa3ecd767b44f241b1ae49
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Making it so orocos_use_package doesn't add excessive flags from packages that were found through some other means
* Merge branch 'per-package-env-hook' into HEAD
* Merge branch 'global-service-cleanup' of https://github.com/meyerj/rtt into toolchain-2.7
* Merge branch 'service-clear-dataflowinterface' of https://github.com/meyerj/rtt into toolchain-2.7
* Merge branch 'unbuffered-connpolicy' of https://github.com/meyerj/rtt into toolchain-2.7
* Merge branch 'toolchain-2.7'
* Added UNBUFFERED type to ConnPolicy (outgoing streaming connections only)
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Copied environment hook from rtt_ros package
  This hook is only effective if RTT is installed to a catkin install space.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Added CleanupFunction to clear the GlobalService before termination
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* corba: give a way to forward C++ exceptions across the CORBA layer
  Right now, every error in the RTT-CORBA convertions and/or access to the RTT
  methods has to be translated into either a return value (if the method has
  true/false) or a specific exception. This gets difficult when the problem comes
  from sanity checks in the transport code itself.
  This commit introduces a specific CORBA exception (StdException) which embeds
  the C++ exception message (from what()), at least allowing to give proper
  feedback to the caller.
* useorocos: silently call catkin_package() from orocos_generate_package()
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: use version number from package.xml as default for generated pkg-config files
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: fixed orocos_generate_package(DEPENDS_TARGETS ...)
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: added INCLUDE_DIRS argument to orocos_generate_package() macro
  The INCLUDE_DIRS given will be exported to other catkin and rosbuild packages. They are never installed automatically.
  You still have to call orocos_install_headers() to make them available in the install-space.
  This mimics catkin's catkin_package(INCLUDE_DIRS ...) macro.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: added FILES and DIRECTORY argument types to orocos_install_headers()
  Example use cases:
  - `orocos_install_headers([FILES] foo.hpp ...)`
  installs header files to `include/orocos/${PROJECT_NAME}/foo.hpp` (FILES is optional)
  - `orocos_install_headers(DIRECTORY include/${PROJECT_NAME})`:
  installs all files in `include/${PROJECT_NAME}` to `include/orocos/${PROJECT_NAME}`
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* services: also clear DataFlowInterface in Service::clear()
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge branch 'master' of git.gitorious.org:orocos-toolchain/rtt
* useorocos: disable caching of pkg-config contents for orocos_find_package()
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* deployment/plugin: remove duplicates from component/plugin search paths
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: readded Eclipse project workaround with a cmake warning
  See discussion on https://github.com/orocos-toolchain/rtt/pull/12 for details.
  rosbuild users should really set their output paths explicitly before including UseOROCOS-RTT.cmake.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: do not set cmake output directories to CMAKE_CURRENT_BINARY_DIR for plain cmake builds as this breaks ocl
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: always set cmake library, runtime and archive output directories according to the build-tool in use
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge pull request #11 from meyerj/export-source-include-orocos-directory
  This enhances the use case that enables building depending packages in the same catkin workspace without relying on catkin to export and import include directories for non-generated headers. It also means you should put your headers into package/include/orocos/package to have a similar layout between the install-space and the source-space.  As a follow-up we would want to update the orocreate-pkg templates to illustrate this layout.
* Exception handling: Added option to disable exception
  The option could be enabled be setting either the enviorment Variable
  RTT_IGNORE_EXCEPTION or be setting the static variable
  RTT::m_catch_exception to a positive value.
  This make the life for developers much easier. Let the Exception Raise
  so that the user could use gdb for backtracke analysis. Only for Debuggig
  purposes.
* useorocos: always export ${PROJECT_SOURCE_DIR}/include/orocos in catkin workspaces if it exists
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* package: added pkg-config build and run dependency to package.xml
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: fixed a cmake error that caused duplicate package_LIBRARIES entries if orocos_find_package(package) has been called more than once
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: fixed verbose debug output if VERBOSE environment variable is set
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* cmake: export the used CORBA implementation, to be used by transport typekits etc.
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Merge remote-tracking branch 'jhu-lcsr-forks/another-fix-5' into catkin
* useorocos: renamed OROCOS_DEFINED_TARGETS to ${PROJECT_NAME}_EXPORTED_TARGETS because this nicely integrates with catkin. Added ${PROJECT_NAME}_EXPORTED_INCLUDE_DIRS for typekits.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* UseOrocos: adding pkg-config path for catkin workspaces which have yet to be source'd
* useorocos: maintain a list of exported targets and include directories in orocos_generate_package
  This lists are used if orocos_use_package is called for a package within the same workspace
  instead of invoking pkg-config. This allows users to generate and use packages within the same workspace.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Revert "Fixing orocos catkin detection."
  This reverts commit b7a2c84395fc73f17400e6e2b9c8df7ad2edbb93.
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* useorocos: enable verbose output if orocos_use_package() macro is called with the VERBOSE option
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Preparing 2.7.0 release
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* updating travis harness to use catkin_make_isolated to invoke tests
* fixing travis build after catkin behavior change
  More details here: http://github.com/ros/catkin/issues/534
* debugging travis
* debugging travis
* Merge remote-tracking branch 'oro/catkin' into catkin
* Merge branch 'remove_duplicates_from_use_orocos_variables-updated' into catkin
* trying to fix travis test config
* Fixing orocos catkin detection.
  Previously, it was required that find_package(catkin) was called before
  including orocos's use-file so that it could know you wanted to use
  caktkin. Now, instead, if there is a package.xml file in the root
  directory of the project, it tries to find catkin, and if catkin is
  found, it enables ORO_USE_CATKIN.
* preparing v2.6.9 release
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* catkin: added run_depend from catkin to package.xml for released packages
  Signed-off-by: Johannes Meyer <johannes@intermodalics.eu>
* Merge branch 'catkin' into prepare-catkin-merge
  Conflicts:
  UseOROCOS-RTT.cmake
* os: fix for bug 1046: OSX 10.8, boost 1.54, apple-gcc-4.2 RTT main-test FAILS
  Apparently copying the boost functions went wrong and we ended up with a NULL pointer.
  Fixed by directly using the function pointer instead of the boost function.
  Signed-off-by: Ruben Smits <ruben@intermodalics.eu>
* fix for bug 1047: Added missing boost version check
  Signed-off-by: Ruben Smits <ruben@intermodalics.eu>
* tests: disable testThreadPID for macosx, this is not supported yet
  Signed-off-by: Ruben Smits <ruben@intermodalics.eu>
* cmake: fix the SelectOneLibrary macro, it added one } too many
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Merge pull request #17 from jhu-lcsr-forks/remove_duplicates_from_use_orocos_variables-updated
  Removing duplicates, with merged conflicts
* resolving conflicts in duplicate removal in orocos_use_package
* Merge pull request #16 from jhu-lcsr-forks/find-vs-use-macro
  Fixing the distinction between "find" and "use"
* Merge pull request #18 from jhu-lcsr-forks/rosbuild_orocos_libdir_with_package_name-updated
  Add package name to the orocos libdir also for rosbuild packages Edit
* Resolving conflict
* Merge branch 'catkin' into rosbuild_orocos_libdir_with_package_name
* Fixing the distinction between "find" and "use"
  orocos_find_package() now only finds and sets individual ${${PACKAGE}_*}
  variables, and orocos_use_package() now adds those variables to the
  aggregated ${USE_OROCOS\_*} variables. As such, the catkin package.xml
  parsing now uses orocos_use_package() but with OROCOS_NO_AUTO_LINKING
  enabled so that nothing gets auto-linked. This enables people to _find\_
  orocos packages withoug having other side-effects not related to that
  package.
* Adding xpath to manifest rosdep
* increasing number of travis cores
* Merge pull request #10 from jhu-lcsr-forks/repair
  Additional features / robustness for orocos_use_package and orocos_find_package
* Merge branch 'catkin' into repair
* disabling more tests which don't work on CI
* Merge branch 'catkin' of github.com:jhu-lcsr-forks/rtt into catkin
* adding xpath rosdep
* missing xpath dep
* compatibility with rosdep just isn't worth this
* only install package.xml.in files automatically
* fixing package.xml rename in install target
* Merge branch 'repair' of github.com:jhu-lcsr-forks/rtt into repair
* Adding install targets for orocos sub-packages
* Merge pull request #12 from jhu-lcsr-forks/disable-affinity-test-on-ci
  disabling cpu affinity tests with the CI environment variable is defined
* disabling cpu affinity tests with the CI environment variable is defined, workaround for #11
* adding travis build config
* Adding more status output
* adding STATUS, un-caching orocos_find and orocos_use macro variables
* removing auto-link from targets
* cleaning up
* Adding options to orocos_find_package and orocos_use_package, adding more debug output, adding link commands to orocos\_* targets
* wip: repair
* Merge remote-tracking branch 'autobuild/master' into next
* macosx: fix clashing Posix features defines
  Signed-off-by: Ruben Smits <ruben@intermodalics.eu>
* cmake: fix APPLE LINKFLAGS wrt rpath settings
  Signed-off-by: Ruben Smits <ruben@intermodalics.eu>
* cmake: add project/package name suffix to the orocos libdir
* Fix building with boost 1.53: this header has been deprecated since boost 1.53
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* Merge remote-tracking branch 'orocos/master'
* Default to dry setup for Groovy and wet for Hydro or later. Set NO_ROS_BUILD to force wet/catkin.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge remote-tracking branch 'orocos/master'
* extras: fix ROPtr::reset(ptr) when 'ptr' is the actual pointer that 'this' already manages
* useorocos: generate typekits in the project source dir
  Required in case we use catkin.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge remote-tracking branch 'orocos/master'
* add missing setter for RTT::os::Thread::stopTimeout
* os: add a way to set the stop timeout on a per-activity basis
* cmake: UseOrocos macros should use the correct way of rpath setting on OSX
  Signed-off-by: Ruben Smits <ruben@intermodalics.eu>
* Also append target suffix for macosx to not confuse the OCL utility scripts
  Signed-off-by: Ruben Smits <ruben@intermodalics.eu>
* deregister the dataflow servant in cleanupServer
* corba: CORBA was doing an unnecessary copy in CorbaTemplateProtocol
  The issue was a mismatch between RemoteChannelElement using
  Late(Const)ReferenceDataSource and CorbaTemplateProtocol looking
  for (Const)ReferenceDataSource. Both have been moved to the Late*
  versions.
  This most likely will improve performance of the CORBA transport
* mqueue: factor the createStream in a base class
  The issue this commit tries to fix is that all subclasses of
  MQTemplateProtocol have the restriction that T needs to have
  no virtual tables, as a static assert in MQTemplateProtocol
  checks this.
  However, there is no need for such a check in the general case,
  only the "use memcpy to marshal" case has this issue. So,
  create MQTemplateProtocolBase to get the completely generic
  createStream method, and make the other marshaller implementations
  depend on it
* Merge remote-tracking branch 'autobuild/master' into next
* Merge remote-tracking branch 'autobuild/stable' into next
* Allow customization of lock timeout for periodic and non periodic threads
* Fixed cmake 2.8.9 bugg during include, Cmake only acceps true if find_package is used
* Merge remote-tracking branch 'autobuild/master' into orocos_master
* Merge remote-tracking branch 'autobuild/next'
  This reverts the (wrongly) pushed rtt_next changes
* Fixed cmake 2.8.9 bugg during include, Cmake only acceps true if find_package is used
* Contributors: Antoine Hoarau, Bert Willaert, Dmytro Poplavskiy, Elmar Berghöfer, Janosch Machowinski, Javier Hidalgo Carrio, Johannes Meyer, Jonathan Bohren, Malte Langosz, Matthias Goldhoorn, Peter Soetens, Ruben Smits, Scott K Logan, Steffen Planthaber, Stephen Roderick, Sylvain Joyeux, Thomas Roehr, Tom Gehrke, jmachowinski, tjadevries

2.6.0 (2013-09-24)
------------------
* adding travis build config
* Merge pull request #9 from jhu-lcsr-forks/set_found_variable
  Added ${PACKAGE}_FOUND variable output in orocos_find_package()
* useorocos: set ${PACKAGE}_FOUND variable to true if the package has been found in orocos_find_package()
  This follows cmake standards for similar commands like find_package().
  Also added a FOUND check to orocos_use_package() although it's not really required here.
* Fixed spaces in Requires: list in generated pkg-config files
  string(CONFIGURE ...) concatenates all elements of list variables without spaces. Example:
  Requires: orocos-rtt-gnulinux rtt_rosnodertt_sensor_msgsrtt_geometry_msgsrtt_nav_msgs
* fixed parsing of xpath output in orocos_get_catkin_deps() cmake function
* fixed include_directories in orocos_use_package()
* fixed LIBRARY_OUTPUT_DIRECTORY for components, plugins and typekits if ORO_USE_ROSBUILD is set
* don't auto-link catkin by default
* pkg-config generation missing @ escapes
* Splitting orocos_use_package into use & find, adding more catkin support
* pkg-config generation for install/rosbuild/catkin
  - add pkg-config generation for catkin
  - remove duplicate pkg-config file source
  - replace "@" with "\@" in pkg-config file template to prevent
  substitution in string as per
  http://www.cmake.org/pipermail/cmake/2006-January/007936.html
* Fixing rosbuild/catkin cache variable
* changing orocos_package to ORO_ROSBUILD_PACKAGE_NAME because that's where it's actually used
* Removing unnecessary addition to pkg-config path since orocos won't be built in a rosbuild tree any more
* rosbuild + catkin client support
  - restoring old rosbuild support
  - checking manifest parsing back from package.xml
  - updating rosbuild check to use ROSBUILD_init_called
  - adding catkin-supporting pkg-config file generation
* re-adding old manifest.xml
* Merge pull request #3 from meyerj/rosbuild_support
  Pulling in Johannes's Rosbuild support
* Merge branch 'catkin' into rosbuild_support
* Merge branch 'catkin' of github.com:jhu-lcsr-forks/rtt into catkin
* backing out the addition of tao deps from 39030b6
* Merge pull request #2 from meyerj/fix-orocos-libdir
  Fix orocos libdir
* rtt: search for a rosbuild package in orocos_use_package() and recurse
* rtt: also respect LIBRARY_OUTPUT_PATH cmake variable in UseOROCOS-RTT.cmake as many rosbuild-style packages use it
* rtt: also respect LIBRARY_OUTPUT_PATH cmake variable in UseOROCOS-RTT.cmake as many rosbuild-style packages use it
* working on re-adding rosbuild support for downstream packages
* rtt: removed corba stuff from package.xml
* rtt: fixed LIBRARY_OUTPUT_DIRECTORY for components, plugins and typekits in UseOROCOS-RTT.cmake
* changing package.xml-based auto-depend run_depend to build_depend
* Merge pull request #1 from meyerj/install_package_xml
  Install package.xml
* Install package.xml
* Merge branch 'toolchain-2.6-patched' into catkin
* Merge branch 'fix-getnsec-simtime' into toolchain-2.6-patched
* Adding missing use_clock check to getNSecs
* Merge branch 'toolchain-2.6' into catkin
* Merge branch 'ctaskbrowser-sub-service-ports' into toolchain-2.6
* Merging updates from toolchain-2.6
* Merge branch 'fix-more-operation-args' into toolchain-2.6
* Adding Ruben's patch for more than 3 args
* moving functions / cleaning up
* Adding support for ports in sub-services in corba taskbrowser
* Adding more verbose error messge for unknown types
* adding tao rosdeps
* Removing ROS package import from component loader, setting library output directories to be compatible with catkin devel environments and the orocos search paths. Ideally the output directories would be set to the same thing as AC_INSTALL_DIR, but orocos does not look in an 'orocos' directory for plugins.
* Making build output path structure mirror that of install structure to support in-buildspace 'devel' pattern used by catkin
* explicit library output dir
* reindent
* Removing more rosbuild stuff
* Default to dry setup for Groovy and wet for Hydro or later. Set NO_ROS_BUILD to force wet/catkin.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Changing manifest.xml parsing to package.xml parsing
* Merge branch 'toolchain-2.6' into catkin
* Removing rosbuild gunk
* types: typekit linking&testing using clang and binutils-gold
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: re-check for typegen each cmake run.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: add system library to user libs
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* tests: remove duplicate BOOST_TEST_MAIN macro
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* tests: do not mix included and linked usage of boost unit test framework
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* os: we should use the Instance API of the StartStopManager instead of keeping a local reference, partially fixes bug # 834: Unit tests fail on macosx
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* macosx: fix building with boost > 1.50 and Snow Leopard
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* Fix building with boost 1.53: this header has been deprecated since boost 1.53
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* cleanup CMakeLists from ROS polution
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* catkin: provide catkin compatible package.xml file
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* cmake: make import file optional
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* cmake: ditch ros specific stuff
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* plugin: updated API docs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* os: make void specialisation of rt allocators public
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* deployment: ComponentLoader::import only interprets a package name as filename if it is an loadable library
* cmake: don't force install path in cmake code.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: the n-th fixup of the make eclipse-project target for ROS
  It seems now that the setting of the OUTPUT_PATHS must be done *after*
  rosbuild was invoked in cmake.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: fix eclipse generator detection.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: don't eagerly assume catkin-style builds on fuerte
  We broke fuerte building because of assuming catkin too eagerly.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix crash in quantal and possibly all other OS'es.
  Parser rules on stack got cleaned up before they could be used.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: cleanup/sanitize generation of typekits
  Added DEPENDS argument to the macro and tested lots of different
  options. We stick to one typegen project per package, and the
  headers are best in include/package/...
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix finding ros on Groovy
  Yep, it changed again in Groovy !
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* deployment: fix error reporting when importing packages
  If your package was not using ros, you always got an error.
  I upgraded the code to use Rospack directly instead of roslib.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: define USE_OROCOS_RTT flag to indicate that UseOrocos-RTT conventions are in use.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: fixup missing includes and forward decls.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: improve non-rosbuild configurations
  - We skip rosbuild if fuerte or later
  - Fixup manifest reading in case of non-rosbuild systems
  (the dependencies were ignored)
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update drawing about deployment.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: update docs on orocos_typegen_headers
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: More pkg-config fixing of namespec parsing.
  Signed-off-by: virtual <virtual@server-1210-amd64.(none)>
* cmake: fixup pkgconfig search logic for -lnamespec case
  It did not work with -l:/absolute/path and it assumed -l/absolute/path was correct
  syntax.
  I removed the old case and only respect the correct case.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: fix typekit plugin test by setting suffix correctly.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* base: fix missing include file.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: fixup last missing API decorations.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: fixup missing RTT_API statements.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: fix namespace typos.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: also check for absolute paths coming from .pc file libs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix bug #1012: CMake issues with newer Xenomai custom installs.
  Addressed the various issues and ambiguous error reports one could have
  when selecting the xenomai target.
  Also fixed linking with the mqueue headers in Xenomai environments by
  passing the flags from xeno-config directly.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Revert "Add propagateNeedsSignal function."
  This reverts commit c512431845022a4cf9de099a5eafa5e1347b6129.
  Accidental push of non-tested patch (contained a type in RemoteChannelElement).
* doc: add caveat about deployer renaming
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Add propagateNeedsSignal function.
  Add propagateNeedsSignal function to the ChannelElement interface.
  This function allow an input port to tell if it needs signaling
  upon new data availability.
* fix for bug #979: added missing public keyword.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix bug reported on ML of hanging script operations.
  executeUntil + execute always returned true, even if the
  function had run to an end.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: more release note updates.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: release notes and API doc updates.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: support collecting arguments up to 6
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: document TaskContextFactory.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: add ComponentLoader.hpp to install file.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: package version 2.6.0-0
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* deployment: fixup default component path for ROS debian packages
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Fixup previous patch.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: reorganize code such that local operation objects are lighter code-size
  We save some code duplication by moving some generic functions to template-less base classes.
  From a memory footprint perspective, it remains the same, or even
  increases for RemoteOperationCallers, but decreases the virtual function
  table sizes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: reorganize code such that local operation objects are lighter code-size
  We move some generic functions to template-less base classes.
  From a memory footprint perspective, it remains the same, or even
  increases for RemoteOperationCallers, but decreases the virtual function
  table sizes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: code cleanup and re-ordering in BindStorage
  Let all cases inherit from RStore<void>
  Log errors to Error, and not Debug
  Log errors in ExecutionEngine
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: if IS_ROS_PACKAGE and generating for CDT, force the output paths
  Otherwise, it just won't generate a correct CDT project with most cmake versions.
  :
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: initial 2.6 release notes
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fixed ValueParser for PropertyBag properties that are owned by services
  Signed-off-by: Johannes Meyer <meyer@fsr.tu-darmstadt.de>
* ports: no longer cache the InputPortSource
  This allows us to shorten the lifetime of the InputPortSource
  with respect to the port.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* ports: provide InputPort::getDataSample()
  This is the counterpart of OutputPort::setDataSample() and allows receiving
  parties to initialize internal data structures according to the expected
  size of the data on this port.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: make InputPortSource assignable
  This allows other code to have a reference to the internal data,
  in case this is needed for performance reasons.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: fixup type comparisons by name in various places
  For property composition, a lot of 'bag.getType()' occurences needed to
  be replaced by 'Types()->type(bag.getType())' in order to compare the
  TypeInfo pointers instead of the type names.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: add a real-time variant of getMember.
  It stores a reference to a member of an assignable struct. If this struct
  is not assignable, a reference to a copy of that struct is
  returned (non real-time copy).
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: drastic performance cleanup of getMember
  The implementation was insaneously presumpteous. Not only was for each
  discovery two data sources created for each member, each member lookup
  caused the whole struct to be 'decomposed' into datasources, in order
  to return just one of them. I removed the both cases of datasource
  bloat.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* deployment: remove RTLD_GLOBAL to support overriding of ComponentTypes, fix for bug #1001
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* Set version number to 2.6.0 to allow compile-time checks
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: add roslib to the orocos-rtt rpath
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* deployment: don't throw on 'not found' errors.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: fixup bool pretty printing.
  Don't use use_ostream to determine if the StreamFactory must be set,
  since this disables alternative read()/write() implementations a
  subclass might have implemented.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fix copying files to CMAKE_CFG_INTDIR.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: fixup unit tests by removing static keyword
  The previous patches added 'static', but the unit tests use these functions
  too.
  Even if they're not part of the RTT API.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* deployment: added ComponentLoader::addFactory() method
* deployment: moved the component loader and roslib support from ocl to rtt
  Signed-off-by: Johannes Meyer <meyer@fsr.tu-darmstadt.de>
* types: added missing EmptyTypeInfo::getTypeInfoObject() method
  Signed-off-by: Johannes Meyer <meyer@fsr.tu-darmstadt.de>
* Task can't give name before initialisation.
* useorocos: collect compiler and linker flags in orocos_use_package
  The orocos_use_package(...) function has been converted to a macro,
  which additionally modifies the USE_OROCOS_COMPILE_FLAGS and
  USE_OROCOS_LINKER_FLAGS to allow packages to export arbitrary
  compiler and linker flags to be applied to each dependent orocos
  target. Output variables are added to the internal cache.
  Signed-off-by: Johannes Meyer <meyer@fsr.tu-darmstadt.de>
* types: fix mixed up ifdef guards and doc string.
  Reported on bug #995 - Template instantiations for std::string are missing in RTT typekit
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge commit 'refs/merge-requests/15' of git://gitorious.org/orocos-toolchain/rtt
* Add TaskContext factory for corba transport.
* extras: define ReadOnlyPointer<T>::get to return T const*, to have an interface compatible with boost::shared_ptr
* Merge remote-tracking branch 'orocos/master'
* Revert "truncate duplicate protocol error to warning"
  This reverts commit 4c9ac10b6b7d383b30b321b2c1364b9a2f05e2ba.
* Revert "types: add the DataFlowTypeInfo between the TemplateTypeInfo and PrimitiveTypeInfo"
  This reverts commit 741e23971cba877e093a3da4b0b7026c31a65c80.
* Merge branch 'toolchain-2.5'
* dataflow: implement circular buffer connections.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* ports: applied fixup of signalling ports from Georg Bremer.
  See bug #938 for details.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: make TypeInfoRepository thread-safe
  When importing packages from different lua contexts, the type repos
  would crash very often. Typically when using iTaSC.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* extras: Use char instead of int for FileDescriptorActivity::CMD_xxx values.
  Only the first byte of the FileDescriptorActivity::CMD_xxx values are
  used by the software, so these values should only be a single byte in
  length.  Defining them as 4-byte ints works on little-endian machines
  because the first byte is the least-significant one.  On big-endian
  machines, though, the first byte is the most-significant one, which
  is zero for all three CMD_xx values.  Hence, all three CMD_xxx values
  are interpreted as CMD_BREAK_LOOP on big-endian machines.
* typo fixed (OuputPort -> OutputPort)
* tests: fixup propertyloader unit tests due to API change.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* marsh: enable PropertyLoader to operate on services directly
  Signed-off-by: Johannes Meyer <meyer@fsr.tu-darmstadt.de>
* rtt: delete target property on failure during property composition
* Merge branch 'master-typeinfo-redux'
* types: memleak fix + log cleanups.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* truncate duplicate protocol error to warning
* master: fixup re-enable mech uploading.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripts: re-enable mech doc uploading.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: various fixes for ros environments
  We now better detect if a package is in the ROS package path or not (some false positives were possible)
  We avoid double inclusion of rosbuild.cmake, since this file is not robust for that and
  this leads to an infinite recursion in cmake.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: various fixes for ros environments
  We now better detect if a package is in the ROS package path or not (some false positives were possible)
  We avoid double inclusion of rosbuild.cmake, since this file is not robust for that and
  this leads to an infinite recursion in cmake.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* fixup struct type info
  Signed-off-by: Peter Soetens <peter@intermodalics.eu>
* ports: move ConnFactory out of PortInterface
  It's being replaced by a virtual function to create a remote connection
  to the input port. RemotePorts implements it.
  Signed-off-by: Peter Soetens <peter@intermodalics.eu>
* typeinfo: updated api docs and test bugfix.
  Signed-off-by: Peter Soetens <peter@intermodalics.eu>
* types: persistent TypeInfo refactoring.
  This patch adds delegation to the TypeInfo object
  and separate factory objects which implement the delegated
  functions. As such features can be added to a TypeInfo
  object in an incremental way and the TypeInfo pointer
  is always valid and never changes. Only the feature set
  may change (expand).
  There are five new factories:
  values (attribute, property etc)
  compositions (compose/decompose/convert)
  connections (in/out ports)
  members (accessing a type's internal data)
  streams (streaming to/from text)
  The existing factories remain:
  constructors (convert)
  transports
  Aliase names are now kept by the type itself as well.
  Comparing TypeInfo pointers will now always work.
  The code is backwards compatible *except* if you
  implemented an own *TypeInfo class, then you need
  to change it as such:
  - implement bool installTypeInfo(TypeInfo* ti)
  See Struct/Sequence/Enum/... TypeInfo classes for
  copy/paste examples.
  - If you implemented getMember, inherit from
  MemberFactory in addition to TemplateTypeInfo
  TemplateTypeInfo and its sister-classes are now
  TypeInfoGenerator objects instead of TypeInfo
  objects. The TypeInfo object is created by the
  TypeInfoRepository and the TypeInfoGenerator
  adds features to that TypeInfo object.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: rename TypeBuilder to TypeConstructor.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.5'
  Conflicts:
  rtt/os/xenomai/fosi_internal.cpp
  Conflict about returning 0 or ~0 in rtos_task_get_cpu_affinity for Xenomai.
  Defaulted to the toolchain-2.5 behavior, returning 0.
* config: fix cmake logic for cmake 2.8.8
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
* fixed: collecting status of async operation with 5 arguments
* internal: fix incomplete type error when compiling with clang
  Signed-off-by: Ruben Smits <ruben.smits@intermodalics.eu>
* os: cleanup mk's patch for cap-ng.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* gnulinux capabilities(7) support
  Hi,
  I just noticed that using capabilities(7) to configure SCHED_RT
  permissions did not work, because in os/gnulinux/fost_internal.cpp
  SCHED_RT is squelched to SCHED_OTHER if no rlimits are configured and
  we are not root (although spawning a RT thread would work because of
  the configured capabilities)
  Below an experimental patch that extends gnulinux/fosi_internal to
  check for possible capabilities. With this the deployers
  (deployer-gnulinux, rttlua-gnulinux) can be configured with
  CAP_SYS_NICE to permit spawning threads with RT priorities, ie:
  $ sudo setcap cap_sys_nice=ep rttlua-gnulinux
  The patch uses libcap-ng, and Works Fine Here (TM). What makes it
  experimental is the integration into the build system :-) (maybe sb
  can take a look?)
  Regards
  Markus
  From 0a861cbdf6c2807dde3b436fc6bc35b1d6764aad Mon Sep 17 00:00:00 2001
  From: Markus Klotzbuecher <markus.klotzbuecher@mech.kuleuven.be>
  Date: Mon, 2 Apr 2012 15:05:59 +0200
  Subject: [PATCH] add basic capabilities support on gnulinux
* fix bug #941: FindXenomaiPosix.cmake disregards XENOMAI_POSIX_ROOT_DIR env variable
  The attached patch was corrupt, but the idea was correct.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* mqueue: provide compatibility with boost 1.46 or newer
  For some reason, we do save the item_version_type, but we never load it,
  making the read data corrupt (extra int in input stream). Somehow
  we don't play nice with the boost::serialization functions. Can't find
  out why, so we just catch the item_version_type and then don't save it.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* mqueue: fix serious bug where slow serialization was used on arrays.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: updated some doc images.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update copyright statement.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fixup figure display in pdf version.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* rtt_cheat_sheet: fix typo in addOperation for class member functions
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* xenomai: minor affinity changes + code formatting
  - exit -1 if mlockall fails
  - use T_CPUMASK to be sure we don't pass too much flags to the xeno threads
  - Return 0 instead of ~0 for getting the cpu affinity
  todo: cache affinity and return that number to user
  - removed plenty of tabs and put in spaces
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: remove one unnecessary copy, and cleanup the RemoteChannelElement handling of data sources
* extras: fix return value of ReadOnlyPointer::-> to const
* fosi: don't set cpu affinity if 'all' is specified.
  Signed-off-by: Eli Reekmans <eli.reekmans@intermodalics.eu>
* cmake: fix linking order of Xenomai libraries
  The order was wrong and newer linkers (Ubuntu 11.10) use --as-needed,
  skipping the symbols of one of the libraries.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* activity: initialize default thread with lowest priority instead of '0'
  Otherwise, a warning may be issued because of the hardcoded '0' value
  not matching a priority value.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* StructTypeInfo: commenting out debug output
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
* types: fixing std::string syntax in EnumTypeInfo
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
* in exception(), don't cleanup if the task's initial state is Stopped
* corba: in RemoteChannelElement::read, invalidate the connection if reading the remote connection fails
  This makes the read-pull behaviour the mirror of the write-push
  one.
* exception : propagate exceptions thrown while calling an operation. exception : set the owner taskcontext or the engine executing the operation in the exception state corba : add the exception handling through the corba exception CCallError tests : add tests for exceptions handling
* rtt : remove "using namespace std" from headers to avoid name clash while using third party libraries
* scripting: fix parsing of alias values.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* taskcontext: add loadService operation to every TC.
  This is a utility function which allows to load a service
  into the current taskcontext.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.5'
* os: add support for PID/TID reporting of threads.
  We now log the PID of each created thread. Some thread log
  messages were cleaned up as well.
  Only implemented for gnulinux, the other OSes return zero.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* marsh: fixup marshalling/demarshalling of some primitives
  We still don't support 'short' and 'unsigned short', since these are not yet
  part of the RTT default typekit. The code is still in a broken state, since
  users could use in the XML file 'short' and 'long' interchangingly. A
  warning is displayed to warn them for this mistake.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* properties: fix the introspection such that no properties are dropped
  They are instead passed to introspect(PropertyBase*) such that a base class
  has a chance to handle it. The CPFMarshaller uses this mechanism to handle
  the unknown float and unsigned char types.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: turn of debug info in StructTypeInfo
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
* doc: cleanup thread docs after comments on ml.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: only set OROCOS_SUFFIX if not defined
  Suggested by T Devries.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: add the DataFlowTypeInfo between the TemplateTypeInfo and PrimitiveTypeInfo
  This is a temporary, probably rock-only, solution to reduce compilation
  time and size for cases where the RTT scripting is not needed.
  The DataFlowTypeInfo is a templatetypeinfo without the composition/
  decomposition code.
* Merge remote-tracking branch 'autobuild/master'
* base: fix documentation for TaskState enumerator
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* EnumTypeInfo(string)
* cmake: fixup (again) install link creation for cmake 2.8.0
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: work around faulty cmake symlink checks
  There were reports that if install did not exist, NOT IS_SYMLINK returns
  false, hence skipping the symlink creation to the install directory.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: minor clarification on starting the deployer.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: clarification about use of import/load etc.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* os:xenomai: patch for xenomai 2.6.0
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
* Fix circular inclusion that prevent defining rt_mutex_t
* scripting: fix keyword clashes with user identifiers.
  we're using the keyword_p in a lexeme environment to avoid
  clashing with 'keywordbar' identifiers of user code.
  Signed-off-by: Eli Reekmans <eli.reekmans@intermodalics.eu>
* types: even better checking of type_id functions.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* rtt: fix comparison of std::info_type if info_type pointer is null
* * rtt: do not compare std::type_info address
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix losing samples if the corba dispatcher incoming queue overflows
  The corba dispatching currently works as follows:
  * a channel queues itself in a internal::List object and triggers
  the corba dispatcher
  * the corba dispatcher, *when woken up*, reads the queue, calls
  transferSamples() and removes the processed channel from the
  queue.
  The issue is that, in the lock-free case, internal::List is a
  fixed-size list of max. size 20. It is therefore possible to have
  the following situation:
  port1 bursts with 30 samples
  port2 writes one sample
  if the dispatcher does not get called in-between, the port2 will
  not get dispatched and therefore port2 won't get transferred.
  This patch does not add a channel element in the queue if it is
  already present. It means that the maximum useful list size is
  the number of ports in the task. Further work would include making
  that size configurable, and/or dynamically sizing it to match the
  port count of all bound data flow interfaces.
* operations: check impl pointer before using it
  This pointer may be zero in some cases.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* service: refuse to add an operation without an implementation.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: don't issue a warning if the task was already unbound
* Merge remote-tracking branch 'orocos/toolchain-2.5'
* Revert "extract TemplateTypeInfoBase: TemplateTypeInfo without type introspection"
  This reverts commit 08306bed866c1f097f711bc29842ae136d1dc5ef.
* v2 ReferenceDSB, setReference returns bool success status
  Also call evaluate on argument dsb before taking reference.
* Merge remote-tracking branch 'origin/master' into toolchain-2.5
* types: turn off debug output in PropertyDecomposition
  This debug output is printed upon each Reporter update, which makes it impractible to run applications in loglevel Debug
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
* doc: added ROS section in release notes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* rtt: link orocos-rtt with xenomai posix skin when mqueue transport is enabled
* doc: update release script not to publish to mech account
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fix typo in rtt-changes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: fix minor missing header includes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: update package to 2.5.0-1
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: initialize an array datasource to default values
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: add missing/fix type info objects for primitive types
  See the rtt_rosnode typekits for an example on how these can be used.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: minor updates to release notes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* allow to completely disable export of ports read, write and last in scripting
  This feature is very expensive, and useless in usage where the
  component scripting is not used (e.g., Rock)
  So, allow to disable it. It remains enabled by default.
* extract TemplateTypeInfoBase: TemplateTypeInfo without type introspection
* plugin: More fixes for Boost filesystem v3 API changes
* Merge branch 'toolchain-2.4'
  Conflicts:
  rtt/types/BoostArrayTypeInfo.hpp
* Bump version to 2.5.0
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Fix bug #891: OperationCaller gets blocked on send() of synchronous operations with non-void type with CORBA
  It was not the send() blocking, but the argument checking when
  collection of return values was being prepared.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* fix set but unused warnings
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
* rtt: do not convert type_info names to std::string
* transport corba : fix serialization of stl container of std::string.
  There is a specialization of AnyConversion<std::string>::toCorbaType for TAO implementation to implement the string serialization into a string sequence. This specialization is not choosen in some cases if the element is given by reference. Moreover in tao implementation this element is a kind of smart pointer, so it's intended to be pass by value.
* Initial v2.5.0 release notes
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Fix bug 889: Memory leak in the real-time memory pool when calling remote operations (cleaned up)
  The poa still had a reference to the servant, so just dropping the
  ref in dispose() is not sufficient. You *really* need to inform the
  poa that the servant is no longer needed.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Revert "Fix bug 889: Memory leak in the real-time memory pool when calling remote operations"
  This reverts commit 74495fb545dfa4763960e743ee2381000c15a4d9.
  Release notes editing got in accidentally
* Fix bug 889: Memory leak in the real-time memory pool when calling remote operations
  The poa still had a reference to the servant, so just dropping the
  ref in dispose() is not sufficient. You *really* need to inform the
  poa that the servant is no longer needed.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: look up libraries separately for each target
  The cmake cache was caching one target in a variable instead
  of one variable for each target.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: unset cached library dependencies to allow target switch
  Target switching (OROCOS_TARGET=foo) was still not possible because
  cmake caches the libraries a target library links with. This patch
  clears that cache entry such that each time, the deps are re-calculated.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* xenomai: raise default stack size to 128kb in Xenomai
  32kb is too low for most robotics application components.
  Signed-off-by: Eli Reekmans <eli.reekmans@intermodalics.eu>
* xenomai: suppress cpu affinity warning when ~0 is given.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* xenomai: don't run the mainthread on priority 10
  It makes no sense and it's unsafe.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: don't log errors while building operations, just throw.
  The error is confusing when an OperationCallerC is used, which tries
  to build the operation fully.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: install exe again in ROS packages and improved explanations when .pc file breaks.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fixup creating symlink to install directory.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: don't symlink to install dir since this does not work with remove_directory
  in a next run, the install/ directory will be removed
  Signed-off-by: Eli Reekmans <eli.reekmans@intermodalics.eu>
* typekit: add ORO_SCHED_OTHER/RT to globals.
  Signed-off-by: Eli Reekmans <eli.reekmans@intermodalics.eu>
* types: fix missing headers in BoostArrayTypeInfo
  Signed-off-by: Eli Reekmans <eli.reekmans@intermodalics.eu>
* cmake: fix OROCOS_TARGET environment variable detection.
  Used identical code as in orocos-rtt-config.cmake
  Signed-off-by: Eli Reekmans <eli.reekmans@intermodalics.eu>
* internal: fix missing header in ArrayPartDataSource.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: fix missing include in CArrayTypeInfo
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: fix for Bug 897, add missing headers
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* Fix undefined reference
  to ReferenceDataSource<bool>
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Fix undefined reference
  to ReferenceDataSource<bool>
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* ports: fix race in clearing a connection
  The connection should never be cleared since a sample
  can be lost (race condition). This clearing was done to
  get rid of OldData. The new method passes on copy_old_data
  to the reading and makes sure that only the current connection
  gets copy_old_data, while during scanning, no old data is copied.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Fix bug #886: Plain ports wake up the TC
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Fixes compile errors with ORO_SIGNALLING_PORTS
* gnulinux: clear affinity mask if it's zero.
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* os: only use affinity if non-zero
  The current implementation set affinity to ~0, which meant all cpus.
  But this triggers errors/warnings if less than 32 cpus are supported.
  So we ignore the affinity parameter when set to zero.
  Updated both xenomai and gnulinux implementations.
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* xenomai: don't use RTHAL_NR_CPUS, use hardcoded value
  RTHAL_NR_CPUS is not available in userspace. We limit it to 8
  for now since Xenomai can't set affinity for more than 8
  processors in the 2.5 series.
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* cmake: fix cmake removal of install dir in ROS.
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* Merge commit 'refs/merge-requests/18' of git://gitorious.org/orocos-toolchain/rtt
* gnulinux: cleanup indentation in fosi.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* xenomai: implement cpu affinity support.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'master-ros-refactoring'
* Merge remote branch 'snrkiwi/toolchain-next'
  Conflicts:
  rtt/plugin/PluginLoader.cpp
  tests/plugins_test.cpp
* tests: don't test signalling operations if disabled.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* taskcontext: remove debugging left-overs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'master-ros-refactoring'
* Merge branch 'toolchain-2.4-remove-signal'
  Conflicts:
  rtt/DataFlowInterface.cpp
  rtt/DataFlowInterface.hpp
* signals: allow users to re-enable them in the build system.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Extend ReferenceDataSource with setReference method
* Don't cache TypeInfo, always return global one
* Merge branch 'toolchain-2.4-type-primitives'
* types: rewrite&add (Primitive)SequenceTypeInfo qnd SequenceTypeInfoBase
  This scheme is meant to have a 1:1 compatibility with the 2.4 release such
  that upgrading to the new type info classes is opt-in for all already
  written typekits.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix bug where function may be called twice
  A start() was given in CallFunction, while the function might have
  auto-started itself. In some cases, this lead to executing the
  function twice.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: introduce local/export/global function decorations
  See xml docs for rationale.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* interfaces: check for null pointers when user provides objects.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: use project_name instead of cmake_project_name
  In some cases, CMAKE_PROJECT_NAME expands to 'Project'. PROJECT_NAME
  does not have this problem.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* clang: fixes to build with clang++ 2.9
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: maintain install subdir for ROS backwards compatibility
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix IS_ROS_PACKAGE macros for ros-refactoring
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: use IS_ROS_PACKAGE instead of ROS_ROOT.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: fix typo in install path setting.
  Reported by Joerg.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: cleanup corba transport docs and add an example.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: allow to specify dependencies when generating the .pc file
  It's for correctness if the manifest.xml does not mention the dependency.
  You need it when a public header includes a header of a 3rd party
  package.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* ports: replace signals in ports with callback
  This code removes all Signal code and replaces it with
  a single callback (boost::function<void(PortInterface*)>
  in order to lighten the code in input ports. The biggest
  change is that you can't use getNewDataOnPortEvent() anymore
  but must register your callback when using addEventPort only.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: conditionally remove the signalling code
  Only StateMachine was using this, and it is possible to implement it
  otherwise, by creating the 'event' as a new operation in the interface
  instead of plugging code in the existing C++ operation.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: support INSTALL_PATH for BC.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: rename value_test to rtstring test and check for rt-malloc
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: Refactor selecting one library from a list of libraries
* Added additional findpath for the Pthread Library
  The PThread library is at leased at debian package
  libc6-dev 2.13-7 moved. This Commit adds an additional find_path for the Cmake scripts
* win32: add possibility to modify default component installation path using the new variable ORO_DEFAULT_INSTALL_PREFIX.
  On windows, the CMAKE_INSTALL_PREFIX is forced to the Orocos-RTT path. There's two alternatives to disable this behavior:
  1. Use the ORO_DEFAULT_INSTALL_PREFIX variable to modify the default
  installation path:
  set(ORO_DEFAULT_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
  include(${OROCOS-RTT_USE_FILE_PATH}/UseOROCOS-RTT.cmake)
  2. Force a non-default CMAKE_INSTALL_PREFIX prior to executing cmake:
  cmake -DCMAKE_INSTALL_PREFIX="<your install prefix>" [...]
  In all cases, the Orocos macros will always honor any change to the cached
  CMAKE_INSTALL_PREFIX variable.
* win32: fix orocos-rtt installation path for windows 64 bits.
  On Windows 64 bits, Orocos-RTT is now installed by default into C:/Program Files/orocos (if compiled in 64 bits) or in C:/Program Files (x86)/orocos (if compiled in 32 bits).
* Fix bug #869: Mac OS X regression in types test
  This patch tests and fixes constructing chars on Linux. The
  syntax uses by the testCharType was not supported yet for any
  type. If asked to contruct a Foo from a Foo, the original Foo
  is returned instead of searching through the constructors list.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: only include test suite hack when specifically instructed
  Define ORO_UNIT_TEST_SUITE_HACK to enable this.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: decorate internal functions with RTT_API because we unit-test them
  We got unresolved symbols on win32 if they were not exported.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: create CMAKE_CFG_INTDIR before copying files to it.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: use debug postfix for orocos_executable.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: validate library suffixes in plugins loading to avoid mixing debug and release runtime libraries.
  When both debug and release libraries were present in the same directory, the PluginLoader was loading both configurations, leading to a C++ exception.
* win32: add OROCOS_TARGET suffix to orocos targets on win32.
  On win32, the '-win32' suffix is now added to target output names as is currently the case for most of the other targets.
* Refs #868, plugins: Prevent Mac OS X from double loading dynamic libraries
* typekit: don't concatenate rt-string if rt_malloc is disabled.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'master' into toolchain-2.4
* win32: fix typo in rtos_task_create argument list.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.4' of gitorious.org:/orocos-toolchain/rtt into toolchain-2.4
* win32: fix two compile errors in oro_arch atomics.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* os: Log more data when creating a thread
* tests: Add CPU affinity test for Linux only
* gnulinux: Correct use of CPU mask. Log on failure to set affinity
* macosx: Fixes for Lion's header changes
  fosi.h sets some defines that remove sbrk()'s function declaration in Lion
* Refs #868, plugins: Prevent Mac OS X from double loading dynamic libraries
* types: add support for primitive and array types.
  The rationale is that primitive and array types are never
  put on flow ports. This allows to create smaller typekits
  for these data types. Additionally, the fixed size array
  typekit has been improved too such that it semantically
  creates and manages arrays as the user expects with respect
  to copying and initialisation.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: add support for fixed size arrays in type system.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* marshalling: fix some big memleaks when (de)serializing
  The code did not always cleanup decomposed properties, leaving
  dangling properties lying around.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.4' of gitorious.org:orocos-toolchain/rtt into stable
* corba: fix finding .idl files in Natty and Squeeze.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  http://bugs.orocos.org/show_bug.cgi?id=873
* doc: updated introductions of the component builder manual
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix OROCOS_TARGET environment variable (2)
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* call rosbuild init in ros mode if not done yet.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix OROCOS_TARGET environment variable.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Fixes #867: Ensure dynamic library paths are fully specified on Mac OS X
* doc: fix documentation type in ports docs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  http://bugs.orocos.org/show_bug.cgi?id=870
* macosx: fix hanging thread issue when using simulation thread
  The simulation thread runs in the MainThread, but that one
  was not correctly initialized in macosx, leading to deadlocks
  in the condition variable based code.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update linking to OCL 2.x API.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fix typo in doc release script
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fix typo in doc release script
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fixup version link update logic
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fixup version link update logic
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* docs: make updating link in release-docs smart.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* docs: make updating link in release-docs smart.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: split lib names in .pc files since pkg-check-modules does not pick them up
  The pthread etc. libraries were not picked up by cmake logic from the
  .pc files since they were full library paths instead of path+ -llib.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: split lib names in .pc files since pkg-check-modules does not pick them up
  The pthread etc. libraries were not picked up by cmake logic from the
  .pc files since they were full library paths instead of path+ -llib.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix parser confusion when using constructor with equal name as service
  I had to split out the constructor parsing from the data call parsing,
  offering a similar functionality, but purely for type names.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update release notes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* extras: remove Configurator classes
  These are confusing wrt RTT::ConfigurationInterface and not used/useful
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update release notes for 2.4.0
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: fix warning in locked queue.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.3-testports'
* ports: no need to disconnect the signal in destructor.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* signal: fix cleanup/disconnection logic of a signal
  When a slot was disconnected, it was effectively removed
  from the list of connections of a Signal. As a result, the
  Signal could not notify the connections when it was destroyed.
  The fix is that the connection stays in the signal's internal list
  until it's destroyed. During emit, we check in the connection itself
  if it is connected or not.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: test adding/removing ports.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge commit 'refs/merge-requests/16' of git://gitorious.org/orocos-toolchain/rtt
* doc: add initial release notes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Log error when unable to start a slave activity
* Merge branch 'toolchain-2.3'
  Conflicts:
  rtt/typekit/RealTimeTypekitOperators.cpp
* typekit: split in smaller files to reduce memory footprint.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: add string/rt_string conversion tests.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* rt_string: add conversion constructor from rt_string to string.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix wrong assignment order in expressions.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: Add unit test for wrong assignment order.
  Also fixes the types_test, which was broken due to not
  throwing in the test.assert() functions
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* rt_string: add concatenation operators.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: disable incorrect test and rename test suite.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: tell alternative syntax for parse error.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* rt_string: construct from plain string.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* #789: Add test case for rt_string use in state machines
* #789: Add rt_string constructor
* Add a FindBoost.cmake version that works with cmake >=2.6.0
  Fixes the behaviour when exporting BOOST_ROOT or BOOST_INCLUDEDIR/BOOST_LIBRARY
  allowing multiple boost versions to be installed
* tests: fix compiler warnings.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: fix typo in orocos_component macro for setting the version.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.3'
* properties: beef up unit tests and fix remaining serialization issues
  There were still some sequence/struct combo's that didn't serialize
  properly, due to incorrect logic in refresh/updateProperty/ies.
  These bag functions were refactored to put the decision logic in
  a single function.
  Missing composition functions in Boost/CArrayTypeInfo were added
  too.
  The unit tests were rewritten to catch some of these cases.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.3'
  Conflicts:
  CMakeLists.txt
  debian/changelog
* scripting: provide property to disable the zero period warning.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: force orocos_target if not empty
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* Fixed previous faulty correction.
* Removed lock - needed for ARM.
* types: fix updating of struct containing vectors
  This is a cleanup that moves struct-specific code from TemplateTypeInfo
  to StructTypeInfo (depends on boost::serialization features) and make
  sure that the struct does not recursively decompose, but only its own.
  The refresh action will then see how much further composition/decomposition
  is needed.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: avoid copies in type info code
  value() returns a copy, rvalue() a const reference.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix bug in peerparser that created services
  Called provides( foo ) without checking if foo existed.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: small updates to inkscape graphics.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: minor updates to figures
  Regenerated two .png files.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix OROCOS_TARGET ENV detection.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* extras: work around warn_unused_result
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Add cpu affinity feature.
* Fix the rtos_task_create signature for ecos.
* useorocos: don't lowercase the .pc filename.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: don't lowercase the .pc filename.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* os: fixup outstanding oro_arch transition bugs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tao: also link with lrt on Linux* systems
  This surfaced when linking for Xenomai, which did not depend on -lrt
  since we use the xenomai API, but TAO still requires it.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: bump to v2.3.2
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* make: enable corba/Omniorb for ROS packages.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.3'
* doc: fix long standing XML tag bug in corelib manual.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update link to gitorious.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update NEWS brief statement.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: bump to version 2.4.0
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake/doc: prepare and bump for 2.4.0 release.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: update to new os/oro\_ headers.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: fix boost path bug for boost >= 1.46 too.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge remote branch 'rock-rtt/master'
  Conflicts:
  rtt/os/oro_atomic.h
  rtt/os/oro_system.h
  I removed all oro_arm/ stuff since it is being replaced by
  intrinsics and the new oro_arch API.
* os: rewrite atomic API to use GCC intrinsics.
  All GCC targets now use GCC atomic builtins for atomic operations.
  GCC >= 4.1 is required for most target and GCC >= 4.4 for ARM.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: remove extra parenthesis to support older cmake versions.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: remove FindBoost.cmake again
  Merged in accidentally from rock. We don't need a modified findboost
  anymore since we call find_package(boost) only once.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'master' of git://gitorious.org//orocos-toolchain/rock-rtt
* Typo fixed in Buffer, missing boost lambda header added in OperationInterfacePartFused.
* arm: fix name clashing with boost thread.
  Renamed many macros to avoid name clashing with boost thread.
* Add ARMv6 and ARMv7 support.
* Merge branch 'toolchain-2.3'
  Conflicts:
  rtt/OutputPort.hpp
* logging: rewrite streaming to allow formatting
  The intermediate stringstream on the stack swallowed all
  formatting. We eliminate this by exposing the mutex and the
  internal streams to the Logger's inline functions.
  '
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: minor updates to drawings for manuals.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update docs on conn policy mechanism.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: add .../include/orocos to include dirs variable.
  Since the macros install headers in the orocos/ subdirectory, this is
  where users need to be pointed add when including headers of installed
  packages.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: allow multiple invocations of find_package(OROCOS-RTT)
  This allows to query for plugins/transports at separate places in complex
  cmake projects.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update svg drawings for 2.3 release.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* logger: avoid cow kicking-in and use c_str() for thread safety.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: fix bug #856 regarding .pc include path in ros environments
  Headers may be:
  top-level:
  packagename/header.h
  package in include dir:
  packagename/include/packagename/header.h
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* transports: return shared_ptr in createStream
  This allows this factory function to refcount the
  returned object.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* fix loading plugins by absolute path on boost 1.42
  The issue was twofold:
  * remove_filename() was keeping a trailing slash (which it
  should not do) and therefore "kind" was always "."
  * remove_filename() modifies its receiver, which meant that
  'arg' was the directory without the file.
* mqueue: close queues and slightly improve error messages.
  We left all queues open, even if they should have closed when
  the process terminates (according to the man page). So an
  explicit close is now part of the MQ cleanup.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* ports: re-implement data source reading of ports.
  Without this, some transports were failing to get the sample
  size out of an output port.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge remote branch 'rock-rtt/master'
  Conflicts:
  rtt/internal/DataSource.inl
  rtt/plugin/pluginpath.cpp.in
  rtt/transports/mqueue/MQLib.cpp
  rtt/typekit/RealTimeTypekitOperators.cpp
* ports: make ports non-copyable.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.3' of gitorious.org:/orocos-toolchain/rtt into toolchain-2.3
* useorocos: don't install executables in ROS_ROOT environments
  Otherwise, we get twice the executable in the same package.
  This code will break when a DESTDIR is set in a ROS_ROOT
  environment, since that *does* require the installation.
  We have currently no indication that such system will be used
  in the near future.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: clarifications to how ports work.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: disable removing of pluginpath.cpp for in-tree builds.
  The in-tree build was broken because the newly generated pluginpath.cpp was removed.
* use overload instead of default argument the copy_old_data argument of InputPort::read
  This is makes the addition of copy_old_data backward compatible with
  the operation / scripting interface, which assumes that the signature
  of #read is read(datasource) and not read(datasource, bool)
* tests: only init mempool if OS_RT_MALLOC is enabled.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: carry-on if no manifest.xml file is found.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* typekit: move 'array' into the STD_TYPES section
  Was mistakenly in the RTT types part, it could not be disabled
  by RTT_NO_STD_TYPES.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: add dependency on boost-filesystem
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* base: fix bug #852: Bug in DataObjectLockFree (missed data initialization leading to malloc when using std::vector data)
  As reported, the last element in the lock-free buffer
  was not being initialized with the samle.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: bump version number to 2.3.1
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: bump version number to 2.3.1
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: fix plugin-path when building ros debian packages.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: rtt/Component.hpp is not installed
* fix bug #849: Attribute::get doesn't work anymore over CORBA.
  fix + unit test for attributes and properties.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: remove dead image about buffers vs data objects.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: remove section about NameServer
  This is not something we should throw at users.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fix getting pointer to scripting service.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* document the copy_old_data flag in the port's operation
* add the copy_old_data flag to readNewest as well
* coverage: fix renamed option for enabling coverage.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: add verbose message when package is not a ros package.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: don't abort when package is not a ROS package in orocos_use_package
* Refs #846: Initialize TLSF memory pool in remaining unit tests
* plugins: cleanup plugin loading API furthermore.
  - We don't append the suffix to the plugin path, this is detected at runtime by the loaders
  - RTT considers itself as a special case, since it doesn't live in an 'rtt' subdir (yet)
  - Warn when loadLibrary-like behavior is expected in loadPlugins/loadTypekits. We will
  deprecate this behavior in the future.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: remove stale pluginpath.cpp file if present
  Users hit this when upgrading to 2.3.x.
  The old version of the .cpp file is used, causing plugins not
  being found.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Fixes #846: Initialize TLSF memory pool in each unit test
* cmake: Fix EXTRA_TESTS typo
* Merge commit 'refs/merge-requests/14' of git://gitorious.org/orocos-toolchain/rtt into toolchain-2.3
* cmake: Add option to set CTest timeout
* Fixes #836: Test timeout ignored by ctest
  Add symlink to ctest configuration file in root BINARY_DIR, allowing all
  ctest options to be picked up.
* tests: Only run setup executables if they exist
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* tests: Do not try to kill non-existent process
  If a pid file does not exist, then don't try to kill and just return success.
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* useorocos: Do not use '-z defs' on macosx
  Apple's custom gcc doens't support this option.
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* useorocos: Fix xpath manifest handling for macosx
  xpath on Mac OS X is older version, with different output format
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* cmake: Add code coverage
* compilation errors rtt 2.3.0 boost 1.46
  A new boost version has been released, 1.46.
  The boost/filesystem lib has had a major revision,
  for that small changes need to be made to PluginLoader.cpp
  Furthermore, I get errors because 'assertion' is ambiguous in the Parsers.
  I suppose it has to do with changes to boost/assertion.
  I added namespace specifiers in front of assertion,
  not sure though if this is what you think is appropriate.
  It made the compilation succeed.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix orocos cmake macros
  * the set_target_properties overwrites the previously installed compile and link flags by rosbuild
  * this patch provides two helper macros that will append the flags instead of overwriting them and uses these helper macros in the public orocos macros.
  * Addition to original patch: use _orocos_list_to_string() instead of a rosbuild macro.
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Revert "cmake: fix orocos cmake macros"
  This reverts commit abee3c3af0560994d793ce498d401e4d04175359.
  Until it works in non-ros environments
* component: remove anonymous namespace since it hides
  symbols
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix orocos cmake macros
  * the set_target_properties overwrites the previously installed compile and link flags by rosbuild
  * this patch provides two helper macros that will append the flags instead of overwriting them and uses these helper macros in the public orocos macros.
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* scripting: test + fix loops-in-loops
  For loops did not store parent's increment action in
  nested loops. Solved by using a stack.
  Bunch of tests added to test this case.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: add parsing hex values
  Supports 0x and 0X notation following capital or small-cap notation.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: don't link with the RTT typekit by default.
  All this code needs more testing, so for now it's removed again
  until we have a stable mechanism for linking with typekits
  (and avoiding to link twice to a typekit containing the same
  type info object)
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* properties: fix faulty error message during composition
  Also clarifies the error message in casu.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: handle multiple paths in RTT_COMPONENT_PATH correctly and reset cmake variables before searching for libraries
* cmake: Check for __APPLE_\_ instead of __unix_\_ on Mac OS X, tests dir
* useorocos: prefer looking in the install directory above the package's own directory
  This caused ocl's headers not to be found.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: Check for __APPLE_\_ instead of __unix_\_ on Mac OS X
* typekit: reorder extern template definitions to avoid gcc warnings
  This reorders the definitions to be sure that the compiler sees the DataSource
  externs first, before it is deduced from another instantiation. For example,
  bool, SendStatus and FlowStatus get instantiated during port instantiations of
  type T.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* typekit: always provide the 'extern' modifier
  We don't use the classical extern trick[1] since Types.inc/Types2.inc don't
  use the RTT_TYPEKIT_EXT_TMPL macro *and* we include this header in our own
  project to speed up that already (so we need 'extern' in our own project).
  It's all quite confusing right now
  and not very clean, but it is doing what's supposed to be hapening.
  [1] use 'extern' when external sources include the header and omit 'extern'
  when we're compiling it ourselves.
* typekit: use typekit/Types.hpp when building constructors.
  I had to re-order the includes to avoid the gcc attribute warnings.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* config: fixup wrong viral EXPORT macros on win32.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugin: be more verbose why certain paths are not found.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: make plugin loading in tests work on win32.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos-rtt: fix rpaths for installation directory.
  It needs to be prefixed with / since it does not
  include the installation prefix yet.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: already define the OROCOS_SUFFIX when looking for RTT components.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: default OROCOS_SUFFIX to OROCOS_TARGET
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: update installation directory of libraries.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: put some emphasis (titles) on caveats.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update news for 2.3 release.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update changes document for 2.3 release.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix orocos_target environment variable detection
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* cmake: fixup generation of SetupTests and adapt plugin test.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: Add SetupTests target for copying cpf files.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: use PREFIX hack to create plugins in parent dir.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fixup crashes with service management.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* services: add service to owner when created.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* marshalling: allow char property to be empty.
  This is the same solution as applied with the CPFDemarshaller.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fix crashes in scripting tests
  No shared pointer was taken to the service, leading to
  its early destruction.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix some unused variable warnings.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: update version number
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* xenomai: use sigaction instead of signal for SIGXCPU.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.2'
* doc: update version numbers to accurately model current status
  Boost >= 1.40 and cmake >= 2.6.3
  Also minor cleanups in the CMakeLists.txt code.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* fix bug #809: Property: ERROR when reading in long value
  The Xerces 3 API changed wrt the characters function. This patch also fixes
  an invalid delete[] and replaces it with XMLString::release
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: add rpath settings for the rtt-macros
  This is needed to be able to link with the scripting and marshalling plugins.
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* make: use MAKE variable instead of plain 'make'.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* transports: no longer assume that the given name is the same as ti->getTypeName()
  Multiple typekits might claim the same type info object,
  so this assertion is no longer true.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fetch services from the parent provider
* Skip same type port connection.
* use the pkg-config Requires: mechanism to add dependency of orocos-corba on omniorb
* os: fix race in setPeriod
  We noticed that the thread did not always pickup setPeriod, because
  the thread was executed before the period variable was updated.
  This fixes that by first updating the period and then signalling the
  semaphore.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* services: set owner when new service is provided
  There was a regression in provides(name) which caused bad_weak_ptr when adding ports,
  the owner was not set.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: disable some warnings when building client code
  Disable W4251 and W4190
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* service: revert enable_shared_from_this2 hack for boost < 1.40
  It turns out it's not easy/possible to correctly implement this function
  with boost < 1.40. I reverted in that case to the old behavior and updated
  the log Error message.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* component: fix bc macro, it takes no arguments.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* mqueue: update to new TypeInfo api.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix double delete in data flow channel cleanup
  a _var was released twice.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: always build with intrinsics
  The /Oi option does just that.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: fix major bug for synchronizing with terminating thread.
  There was no 'join' implemented, leading to the thread using a freed
  object. First join with WaitForSingleObject, and then cleanup stuff.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: break TypeInfo API by returning shared_ptr instead of ptr
  Returning a plain pointer may cause early cleanups of the created
  objects (because references are dropped). So the api changes to
  returning a shared_ptr.
  Surfaced when compiling with MSVS.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* base: fix initialisation of oro_atomic_t
  It is mandatory to use the ORO_ATOMIC_SETUP/ ORO_ATOMIC_CLEANUP
  macros in order to allow emulation of atomic instructions.
  Alternatively, the implementation could have used AtomicInt,
  which would have done this automatically.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* locked: fix major bug in LockedQueue::dequeue function.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: bump version number to 2.3.0
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: fix bug in enable_shared_from_this2
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* typekit: minor warning fixes for win32 compiler.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fix win32 compiler warnings.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* extras: fix win32 compiler warnings in ReadOnlyPointer.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: fix enable_shared_from_this wrt weak_ptr API
  The weak_ptr in 1.40 contains a method named _empty() which is not present
  in older versions. So we can't use it to track initialisation of the weak_ptr.
  We use a boolean to store that info. Maybe weak_this\_.expired() would have
  done too, but since they added _empty() and did not use expired(), there
  must be a reason for not using expired().
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: suppress extern C vs C++ API warning.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: fix unused variable warnings
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.2'
* Revert "cmake: bump version number to 2.3.0"
  This reverts commit 257e8b0d363fe61a0cf06551571d516976a9cfa0.
  I don't know what happened here...
* Merge branch 'toolchain-2.2'
* Initial changes document for 2.3 release.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: also install ROS components in target subdir
  We're also installing the libs built by ROS in a target subdir.
  The .pc file needed fixing too and is now installed next to the
  manifest.xml file.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* service: use new boost enable_shared_from_this2 implementation
  This solves our boost::bad_weak_ptr exceptions, at the expense
  of one extra shared_ptr in each Service object. In case boost prior
  to 1.40.0, we use a copy of that implementation from internal.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: Minor fixes for MSVC10
* win32: clear out some warnings and add /EHa for tests
  Some warnings remain that must be fixed by fixing the code.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: use the OROCOS_TARGET environment variable if provided.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update rtt-cheatsheet to v1.1
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: only be verbose if that var is set in cmake.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: initial changes document.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* components: add ORO_CREATE_COMPONENT_LIBRARY macro
  which deprecates the ORO_CREATE_COMPONENT_TYPE macro
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: Fix building both debug/release in win32
  So we're now using batch commands to control the invocation of cmake -E copy...
  There's no other way to do this.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix SHARED typo in orocos_executable
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: revert conditionaly copying of plugins
  Since the EXISTS test is done at cmake/configure time, it
  will always be false. We need another solution.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: revert including of typekit/Types.hpp
  It causes too much run-time linking trouble on the Win32 platform
  (types/ dir(s) must be in PATH). It might be better to re-introduce
  this with an opt-in switch for Linux users.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fixup (again) typekit/plugin install for unit tests.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix up plugin/typekit copying for unit tests.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix typekit/plugin copying in case path contains spaces.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: cmake fixes to get unit tests working on windows-xp.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* core: display log messages with additional information when updateHook() or errorHook() throw
* win32: minor tweak for MSVC
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32 test: missing boost unit test library
* win32 test: missing symbols
* win32: disable MSVC extern template warning.
* types: add RTT_TYPEKIT_API and conditional extern to templates
* mqueue: publish the MQLibPlugin class
  This is needed for people that want to use it outside of
  the plugin loader
* mqueue: fix read/write vs. disconnection race condition in MQ transport
* Merge branch 'toolchain-2.2'
* cmake: bump version number to 2.3.0
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fix typos in typekit manual.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: allow to return empty bags in decomposition
  An empty bag is a valid result of a decomposition. Also added debug
  statements to why decomposition is aborted.
* corba: add missing include in connection policy.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: remove capacity test since it's not defined
  what the result will be
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: fix cmake error in UseOROCOS-RTT.
* win32: fix compile error when boost include directory contains spaces.
* win32: fix linking error of corba-ipc-server test
* Fix various exports for win32.
* Disable boost auto-linking on win32.
* Fix types-test that was assuming that the string capacity was equal to size.
* Fix installation path of DLL on win32.
* Fix linking with ACE and TAO for both debug and release config.
* Fix name clashing with boost 1.44.
* cmake: link with typekit if plugin/transport includes Types.hpp
  The sources that include Types.hpp must also link with the typekit.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix crash on connection creation for OOB if transport is not there
  A return statement was missing
* core: add keepNextWrittenValue
  This asks the port to store the next value passed to write()
  in the port's sample object, so that it can be used as a
  "data sample example" on new connections
* Merge branch 'master-with-jsreng'
  Conflicts:
  config/rtt_macros.cmake
  rtt/scripting/parser-types.hpp
  rtt/transports/corba/CorbaConnPolicy.hpp
  rtt/transports/corba/RTTCorbaConversion.hpp
  tests/types_test.cpp
* types: cleanup old classes from rtt-types-fwd
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: rearrange extern templates in order to please gcc
  It's a tricky job to put all declarations in the correct order
  such that the RTT-EXPORT tag is noticed before the compiler assigns
  a (hidden) visibility.
  These changes are for testing with compiling with -fvisibility=hidden
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: put VDS specialisation in proper namespace.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: remove superfluous implementation for DS<bool>
  It's exact the same as the default implementation
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* extras: remove extern template defs from MultiVector
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* SendHandleC: move members to pimpl
  The idea was to remove the instantiations of DS<bool> and
  DS<SendHandle> but this was not sufficient since other code
  still contains such instantiations. Is now good for pimpl
  purposes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* core: fix thread-safety of OutputPort's last sample / initial sample handling
  This sample is accessed by threads that create connections (read-only),
  the task's thread (read/write) and threads that use getDataSource()
  (namely, the task browser). The sample's holding therefore needs
  to be thread-safe
* Merge branch 'master-extern-template' into master-clang-extern-template
* clang: import operators n std namespace to please clang.
  The lookup does not find them unless they are in std.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* datasource: don't test offsetpart datasource for now
  It contains invalid pointer arithmic, according to clang.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* clang: minor warning fixes
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tao: fix implementation of disconnect in remote ports
  A disconnect function was present, but with the wrong signature,
  so it was never called (caught by clang)
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix implementation of valid in call function
  A wrong virtual override was never called (caught by clang)
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* clang: variour re-arrangements to please clang
  It's pickier at finding functions from different namespaces,
  so most fixes are moving these functions into a namespace.
  Furthermore, MultiVector has been phased out a bit more,
  and StdVectorTypeInfo doesn't compile because clang can't
  find the operator<< of it as declared in TypeStream.hpp
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* clang: minor updates for clang support.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* attributes: use const references in API
  Unnecessary copies were made in the get/set functions of Attribute<T>
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: remove capacity test since it's not defined
  what the result will be
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: detect double type registration, report it and install an alias
  For this to work, the DataSourceTypeInfo handler installation needed
  to be delayed and moved into a new virtual function of TypeInfo.
  It will alias the old name to the new type and then delete the
  old object. There is a little bit bookkeeping going on because of the
  double occurence of the type info pointer both globally and in the
  TypeInfoRepository data map.
  Aliasing required smarter cleanup in the destructor if the TypeInfoRepos.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix missing include of config file.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge remote branch 'orocos/toolchain-2.2'
  Conflicts:
  rtt/InputPort.hpp
  rtt/PropertyBag.cpp
* Merge remote branch 'phamelin/master-win32-ready'
* typekit: allow to exclude vector/string implementations.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: fix install path of DLLs for components, typekit and plugins.
* win32: fix cmake error in UseOROCOS-RTT.
* win32: fix compile error when boost include directory contains spaces.
* win32: fix linking error of corba-ipc-server test
* Fix various exports for win32.
* Disable boost auto-linking on win32.
* Fix types-test that was assuming that the string capacity was equal to size.
* Fix installation path of DLL on win32.
* Fix linking with ACE and TAO for both debug and release config.
* Fix name clashing with boost 1.44.
* typekit: include explicit instantions first
  In order to avoid a gcc compiler warning.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: fix export tag for bad_assignment
  This exception is just part of the API, not to be exported in every
  compilation unit/dll.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: tag the template class defs for export
  Necessary when visibility=hidden becomes the default.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* property: remove custom extern template for properties
  These are now handled by the typekit and the Types.hpp header.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: include extern templates in typekit cpp
  Instead of compiling it separately.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: split Types.hpp into pure RTT and primitive C types
  As such you can include the RTT-specific extern-templates only.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: link with typekit in orocos libraries.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: provide 'extern template' when including RTT.hpp
  You need to link to the rtt-typekit when including this header!
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* git: update .gitignore file list.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: add front page image source.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: add (unused) matrix type info class for types test.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* attribute: add missing return statement.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: detect user-defined uninstall target
  Abort setting it if the user did so before (for example, at the
  top level).
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: always show the CORBA_IMPLEMENTATION option
  It would disappear if only given on the command line, confusing users
  if they don't see it.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Disable boost auto-linking on win32.
* Fix types-test that was assuming that the string capacity was equal to size.
* Fix installation path of DLL on win32.
* Fix linking with ACE and TAO for both debug and release config.
* Fix name clashing with boost 1.44.
* corba: rewrite TAO specific specialisation for sequence<string>.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix compilation fixes after win32 merge
  * Missing config header include
  * ambiguous variable name in AnyConversion function
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge remote branch 'jsreng/master' into master-with-jsreng
  Conflicts:
  rtt/ServiceRequester.cpp
  rtt/os/win32/win32.h
  rtt/scripting/ExpressionParser.cpp
  rtt/scripting/StateGraphParser.cpp
  The conflicts were mainly due to the addition of boost:: in
  front of bind()
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* configuration: implement addProperty(name, prop) to catch adding objects
  Some people prefer to create the Property<T> object like a Port
  and then add that object with addProperty(). The latter would cause
  and unknown_t since it puts the property object inside a property,
  instead of merely adding the object. These functions catch that
  use case.
  New unit tests for configuration interface added.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* typekit: backport StdString type info constructor
  Necessary for typegen on 2.2 branch.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: remove rogue 'virtual' keyword from class def.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* useorocos: fix possible conflict with user's invocation of ros macros
  It's possible that the user calls rosbuild_find_ros_package, which
  would have prevented us from adding that path to the .pc search path.
  We need a custom marker to check if we processed a package or not.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.2'
* useorocos: fix various issues in .pc generation and .pc usage
  The include directories were not set
  The link directories were not correctly generated.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fix unchecked var test in service port test.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fix warning about small margin not being used.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operators: remove the dead 'dotop' code
  This was replaced by 'getMember' in the 2.x series.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* taskcontext: sanely implement stop() and breakUpdateHook()
  Adds a unit test to check stop() behavior in updateHook, and breakUpdateHook()
  itself, which defaults to 'true' from now on.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: if no OROCOS_SUFFIX is set, use /OROCOS_TARGET
  The rationale is to default to multi-target installs.
  It makes less sense on macos-x or win32, but it's the
  same for all targets.
  One can revert to old behavior by setting OROCOS_SUFFIX
  to an empty variable before including UseOrocos.cmake
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* component: fix typos in component creation macros.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Add real-time output string stream.
* cmake: bump version to 2.2.1
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* FileDescriptorActivity: remove unused var w
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
* FileDescriptorActivity: use runner pointer from Activity class instead of local one
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
* compile as release
* bugfix, release sample on clear() operation
  There was a bug that the saved sample from the
  Ringbuffer was not released on the clear
  operation.
* types: allow to find out if a type supports streams
  If it does, it can be printed instead of decomposed into its members
  The TaskBrowser uses this in order to decide on which path to take.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* marsh: add installation of PropertyBagIntrospector header
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* types: add missing include for sequence types
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* remove invalid assert in BufferLockFree
  A recent change increased the size of the memory
  pool. This caused a assert to fail in the case
  that the buffer is full and a sample was written.
  As the assert relied on the fact, that the buffer
  and memory pool size is equal it is wrong and was
  removed.
* Merge branch 'toolchain-2.2-conn-inspection'
* Merge branch 'toolchain-2.2-newlayout'
  Conflicts:
  UseOROCOS-RTT.cmake
* Merge branch 'toolchain-2.2-imports'
* Merge branch 'toolchain-2.2-decomposition'
* Merge commit 'refs/merge-requests/13' of git://gitorious.org/orocos-toolchain/rtt
* attribute: fix compilation and consistency errors
  * contant: did not do a dynamic-cast from argument
  * alias: put RTT_API at class level instead of constructor-only
  * attribute/constant: also clear name if assignment to null
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* bugfix, make BufferLockFree work if bufsize == 1
  If the PopWithout Release feature is used, the whole
  memory pool is used after the first pop and the next
  Push would return false. Increasing the memory pool
  size to bufsize + 1 fixes the problem
* add copy_old_data flag to InputPortInterface
* compilefix: make testcases match new ChannelElement API
* tests: don't enable tests by default
  They take way to long and users don't know very well how to turn them off.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* bugfix: release last sample from buffer if ChannelBufferElement is removed
* added ability to choose weather old data should be copied on read operation
  The read operation on InputPort and ChannelElement was extended by a new
  boolean argument copy_old_data. If this argument is set to true the
  original behavior is kept. If copy_old_data is false, the given sample
  will only be updated if the FlowStatus is equal to RTT::NewData.
  Tests with 8K samples at 1 kHz showed showed a drop of cpu usage by 1/4.
  Note, the default argument for InputPort::read is false, so old code
  should not be affected by this change.
* reduce number of sample copies during data transport
  This patch changes the logic, how the last sample of
  an port is saved. The new logic makes use of the previous
  changed BufferInterface. This patch is aimed at reducing the
  number of copies in the way of a sample, from a write to a read
  operation.
  In the previous implementation 5 copies were needed in the Locked and
  Lock_Free case (reading until OldData is returned).
  With the new implementation there will only be two copies in the Lock_Free
  case and three copies in the Locked case.
  Testing showed that this reduces the CPU load by ~1/4 on a 8K samples
  being send at a kHz.
* Extended BufferInterface by PopWithoutRelease and Release
  The Buffer interface is now extended by two new methods.
  The PopWithoutRelease returns a pointer to the last
  poped sample. This pointer is garanteed to stay valid
  until the next Pop operation, but it needs to be released
  manually by calling release on the Buffer.
* cmake: force remembering the INSTALL_PATH and CMAKE_INSTALL_PREFIX settings.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: cleanup orocos_executable macro
  A version number is meaningless here.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: update find macros to also check for Orocos-RTT
  They assumed that the user wrote find_package(OROCOS-RTT) while lots of us wrote
  find_package(Orocos-RTT). The find logic now checks for both cases.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: option to force using the tiny marshaller instead of xerces.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix find_package example.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* test: fix corba_mqueue_ipc_test
* internal: make DataSource.hpp significantly less dependent on the MPL
  This is a header that is virtually included everywhere, so optimizing
  that a bit leads nice compilation time improvements
* mqueue: make it zero-copy on write and single-copy on read, fix handling of data_sample
  This changes the MQ send/receive logic to remove the intermediate
  ValueDataSource when possible (i.e. on the write path), which makes
  write zero-copy in principle -- there is still, for an unknown reason,
  a buffer between the output port and the MQ. The read path has one copy,
  but is now made RT-friendly by removing a temporary (and therefore, one
  copy).
  Moreover, the data_sample vs. write code paths are now merged. The logic
  that was assuming that at least one write/data_sample would come during
  connection is removed, making the handling of data_sample on par with
  the one in other transports (i.e. one can use MQ without an initial
  data sample at all).
* rtt: in OutputPort<T>, separate behaviour of setDataSample and keepLastWrittenValue
  Having keepLastWrittenValue on entails making one copy of every
  sample written on the port, which is a performance hog on big
  data structures. Moreover, common workflows don't need to keep
  the last written value, but do need to have an initialization
  sample as set with setDataSample (for std::vector + RT)
  So, separate both behaviours so that calling setDataSample does
  not automatically turns on keepLastWrittenValue
* remove some unnecessary recursive includes
* mqueue: return false in mqWrite only if the error is not that the buffer is full
  Losing data on intermediate buffers in the dataflow is a normal
  event in RTT, so don't make that an error.
* mqueue: make mqWrite return false if the marshalling failed
  This is definitely something that should not happen, and allows
  to catch wrong message sizes
* mqueue: pass the actual message size to updateFromBlob, instead of the max message size
  This allows to add consistency checks on the passed buffer (i.e.
  that we used all the data that was available)
* mqueue: if channelReady throws, display the exception for easier debugging
* base: remove /* within a comment
* base: add getRawPointer() and getRawConstPointer() to the DataSource interface
  This will allow smart type systems (a.k.a. typelib) to have completely
  generic implementation of marshalling and friends, without having to
  specialize any template
* scripting: fix wrong order of evaluating sums scripts
  Similar fix to the problem we had before with * and /.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: add support for marshallers to have internal data structures (cookies)
  This is important for orogen/typelib, as the marshaller must allocate
  an intermediate type for the opaques. This commit adds support for
  the marshaller to return a cookie that should be passed by the
  marshaller's user to the various marshaller methods (fillBlob, ...)
  Use the cookie in mqueues
* corba: remove some unneeded object allocations and copies in the dataflow
* internal: remove unused include "types/TypeMarshaller.hpp" in ConnFactory.hpp
* types: minor updates of log messages when double types are registered.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Revert "types: don't install a second type info handler for a type"
  This reverts commit 52574e48e9410637a4372a48db980ab5bd84914c.
  Partial revert. The changes in some log message were not reverted.
  Conflicts:
  rtt/types/TypeInfoRepository.cpp
* corba: fix establishment of remote connections between local ports
  The service patches had removed the registration of local dataflow
  interface servants, which led to having connections created through
  CORBA's createConnection always use a CORBA connection -- which is
  VERY inefficient.
  This patch reestablishes this registration
* cmake: remove manifest.xml when typegen generates it.
  This avoids having two manifest.xml files in one package.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: fix setting text of parsed state machine.
  We need to store the offset before we start parsing each SM.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* rtt: fix compile warning by adding space
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* marsh: add MarshallingService header to installation
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* scripting: avoid unknown_t log error when assigning a SendHandle.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* engine: also broadcast cond when function is done
  Otherwise, waitForFunctions() blocks for ever in a 3rd party thread.
  Discovered by calling exported script functions from the TB.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: clear parse state when doing initBodyParser
  If this is not done, an exception during (function) parsing
  could keep state and mixup the parser in the next run.
  Was triggered by runScript of statement and the parsing of a function.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* log uncaught exception messages for all std::exception, not only for runtime_exception
* scripting: warn for non-periodic programs when the program is loaded
  The original warning was during parsing, which could be bypassed. When
  loading the program we're sure we catch all cases, and can name them.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* properties: implement proper copy semantics for PropertyBag
  We got segfaults because the copy constructor of PropertyBag did not
  take into account owned properties, hence possibly pointing to deleted
  properties if the parent was removed from the stack.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: compose the items of a sequence first before composing the sequence itself
  The problem with the previous implementation was that it did not
  offer the child elements a chance to use their type specific
  composition function, since we decomposed the whole sequence and
  then did an update. By piece-wise composing each element, we
  respect/use the composeType function and the correct code gets
  executed.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* properties: allow to specify recursion and update property bag functions
  We sometimes only want to decompose a property one level deep, the
  additional optional flag allows to set this.
  The unit tests were updated to better test and use compose/decompose
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: return const data source for size/capacity in array type info
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* properties: remove composition code from propertybag functions.
  The property loader now does the composition instead of update/refresh
  properties.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: extended testtypes and test them for marshalling
  It all fails horribly for now. These allow for
  rigourous testing of structs and sequences.
  What is not yet tested is the custom compose/
  decompose implementation functions and the
  effects on the conversion functions (2.1 behavior)
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* properties: add new composition/decomposition functions
  updateProperties() et al. must be rewritten not to do compose/decompose, but
  only try to update what is. The compose/decompose decision is to be made
  by the caller of updateProperties().
  This patch is not ready yet, adds an initial unit test that tests
  compose/decompose of an vector<double>
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: test marshalling of sequence of sequence.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: add new type plugin for tests
  Meant to house more complex types to test type system.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* properties: mark unready when assigned from incompatible type
  the form Property<T> t = new Property<U>() did not yield the same result as
  the form Property<T> t; t = new Property<U>();
  Changed the latter case to also mark t as not ready()
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: return const data source for size/capacity in array type info
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* marshalling: better escaping and reading of 'char' types in xml.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* marshalling: if file does not exist during writePropeties, use store
  There is a bug in the decomposition code such that it does not work
  on empty files. This shortcuts that code by calling store directly.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: standard primitive types decompose into self.
  This avoids the decomposition code to try getMember even
  further.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: add backwards-compatibility with convertType
  This bc code was only present in TypeInfo.cpp, but that got overriden by TemplateTypeInfo,
  rendering the bc code unused. This patch re-adds it for the 2.2.x release.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* avoid non-static global variables
  if shared libraries are dl-opened *and* linked "in a normal way", then
  the global variables get shared -- as it should -- *but* they also get
  deleted as many times as the library got loaded, which leads to multiple
  frees/deletes on the same object at shutdown.
  This affects symbols defined in the main RTT library, and is therefore
  *not* solved by only using the plugin loader.
  A workaround is to never have public global variables with destructors.
  Global variables should instead be defined static in their compilation
  unit and accessed through method calls.
  This patch does so for a few problematic ones. It solves crashes at
  shutdowns that I have been experiencing.
* rtt: provide a Component.hpp header which allows apps to not depend on ocl.
  ocl's Component.hpp will include this header in due time
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* ports: update service docs when port doc is updated.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* when switching to exception() because of an unhandled exception, display a log message
* types: delete unused type info object and fix unit test.
  The enums typetest assumed it could override the TypeInfoObject
  automatically. Same for 'chars' in type discovery test.
  addType() owns the TypeInfo object so can delete it.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: set pkg config path in ROS_ROOT builds
  typegen relies on PKG_CONFIG_PATH to find the RTT, even
  in ros builds.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: minor doxygen fix.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: force the install prefix when using ROS_ROOT
  The UseOrocos.cmake macros rely on the 'package/install' directory.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: don't install a second type info handler for a type
  Registering twice for C++ type T confuses/crashes the RTT.
  The 2.3 solution is to install an alias for this new type name
  that points to the original type info object.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fix wrong link to doxy pages.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* manifest: remove the cflags export
  Users must use the Find+UseOrocos.cmake macros to link with the RTT.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* core: make breakUpdateHook() return true by default as discussed on the ML
* Merge remote branch 'orocos/toolchain-2.2'
* scripts: don't build pdf+html in parallel
  doing so causes errors during the cmake -E copy since two threads try
  to copy the same file to the same place.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripts: use branch name as second arg for release-docs
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripts: prepare to release master docs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripts: add new release script for automated docs
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: create dir first befor copying png files.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doxygen: cleanup of doxygen markup tags.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.2-unittest' into toolchain-2.2
* test: provide boost.test checkpointing.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* test: include boost test headers through unit.hpp file.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* connections: initial inspection code for connections.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: implement loadLibrary functionality
  Allows to load relative/absolute library paths.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: orocos_generate_package macro
  smart .pc file generation and linking with libraries of depends
  packages. General cleanups and fixing.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fall back on xpath if rospack is not available.
  We need to read the depends tags from the manifest.xml file in order
  to find the .pc files.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: add orocos_use_package macro to UseOrocos-RTT.
  The idea is that we parse the manifest.xml file for all dependencies
  and use .pc files of these dependencies to get the include and link
  flags.
  In case you use ROS, the 'traditional' exports will be used too.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* xenomai: indentation fix in fosi.h
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* rtt: adding orocos_executable macro
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
* cmake: minor doc/message additions for UseOrocos
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* MQ: boost version checking for throwing stream_errors
  The stream_error was split in an input_stream_error and an output_stream_error.
  Signed-off-by: Steven Bellens <steven.bellens@mech.kuleuven.be>
* types: print error message when returning null in getMember.
  Silently returning null leads to hard to find bugs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: add orocos_create_pc_file macro
  Generates a .pc file on the fly for each added
  component,plugin,library or typekit defined at the
  current cmake scope.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* os: provide argc/argv api in order to allow lookup of program arguments.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Provide an updated version of CMake 2.8's FindBoost to provide
  a consistent match between headers and libraries.
  Having multiple boost versions installed with one in /usr/ ->former FindBoost
  version finds the correct location of the headers, but uses /usr/lib/
  libraries in any case.
  This version searches first the user defined locations before including system
  default locations into the search.
  Still not dealing properly with EXACT version requests.
* Add getIOR Method to TaskContextServer
* scripting: add support for sequence-of-structs-of-sequence-of...
  Unit test added as well. Might need more refactoring in UT in order
  to reduce compilation times. A types-fixture or so would be useful.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* extras: don't show IRQ/Xenomai warning when building RTT itself.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: compile with -Wall on gnulinux,lxrt,xenomai.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: silence compiler warning.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: minor improvements to RTT find macros.
  * document OROCOS-RTT_PLUGIN_PATH
  * add      OROCOS-RTT_USE_FILE
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: fix wrong return values in connection factory.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: also allow [] to be used in identifiers.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* manifest: fix link library path in export/cpp/lflags.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: be more pickier when looking up types and services.
  The code checked for the object name being equal to this, but it's
  also this when it's a component, or the object is not found.
  So we check for global calls by checking the service instead.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: only kill corba test servers by pid
  Killing all servers on the same hosts confuses the unit tests
  in parallell runs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: copy cheat sheets to xml area.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: remove filter from cheat sheet in order to avoid rasterization.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: generate pluginpath.cpp in build dir.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: install orocos components with OROCOS_SUFFIX dir.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: add OROCOS_SUFFIX to allow multi-target installs
  We allow to install components in lib/orocos-gnulinux/lxrt/xenomai on Linux systems
  by defining the OROCOS_SUFFIX variable.
  Used by Debian packages.
  We might default this in the future for all installations.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: add rpaths to UseOrocos.cmake macros.
  The installation directory itself is added as rpath, and also the
  prefix/lib directory.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: allow to set a version number when using UseOrocos.cmake
  We need at least a version number to have proper Debian packaging
  and to detect linking against the wrong version number.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: also install generic uninstall cmake file.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: split -config.cmake file in generic and target-specific part
  Since the include directories can change on a per-target basis, we needed
  a separate .cmake file for each target.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: add new header to be packaged.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: add missing header in discovery.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: minor extension to operations tests
  To be sure that we don't fool ourselves.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: fixed adding a C function to the operation interface
  As reported on the ML, adding C functions was not working as documented.
  The solution is to provide an addOperation function for C functions and
  redocument the original one to only support C++ functions.
  Also contains a cleanup of dead code in Operation class and unit tests.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: finish up rtt-changes document.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: allow to define INSTALL path for headers.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc:added package layout to rtt cheat sheet.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripts: remove the word 'Lesser' from gpl+link exception notice.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* make: update default Makefile.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* add default Makefile
  Signed-off-by: Ruben Smits <ruben.smits@mech.kuleuven.be>
* Merge branch 'master-fix-opcaller-disconnect'
* cmake: add INSTALL option for each UseOrocos macro.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: generate pdfs for cheat sheets.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fixed bugs in typekit for fixed size arrays.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: fix disconnecting of operationcaller
  There was a bug in both OperationCaller and in CORBA proxying code.
  The IDL had to be extended to support disconnecting individual operations.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: font and cleanup updates to cheat sheet.
* cmake: updated version number to 2.2.0.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge commit 'refs/merge-requests/12' of git://gitorious.org/orocos-toolchain/rtt
* internal: provided backwards compatibility header for carray
  Will be removed in 2.3.0.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: move carray class into types namespace
  Since we expect users to use it, don't put it in internal.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: minor updates to svg files.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: added rtt and orocos cheat sheets.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: keep line number offsets to zero during runScript parsing.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: remove service when program parsing failed and add some more unit tests.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fix corba initialisation example.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: implement connecting remote services
  This final patch allows to connect a remote requestor with a remote service.
  There is a cleanup-time leak of the CorbaOperationCallerFactory, which is not
  removed by the RemoteOperationCaller. It must be investigated if it can be
  safely deleted or if it needs to be cloned.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: mirror C++ class hierarchy of Service in IDL.
  Service inherits from configuration-, operation-, and dataflow-interface.
  The IDL had put the dataflow still in a separate interface.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: initial implementation of operation caller proxies
  We need these in order to do A-B-C connections, where
  B connects two remote A and B component interfaces.
  This patch adds the OperationCallerProxy object that will forward
  all 'setImplementationPart' calls to the remote operation caller's
  service requester object which will then do the real setup.
  This patch allows you to see the requests of a proxy, but can not
  yet make the connection.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* service: return a pointer instead of a reference for getOperationCaller
  Returning a reference is cumbersome for checking '0' returns.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.1'
* cmake: allow package to install in Orocos's install path.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: update NEWS file for 2.2 release.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: minor update to enum type info template.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: prepared rtt-changes document for 2.2 release.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: take user's decomposeType() better into account.
  Not all decomposition code took TypeInfo::decomposeType() into account,
  sometimes leading to not decomposed types.
  As a special addition, decomposeType(source) may return source itself
  in order to stop any further decomposition of the type. This allows
  string, rt_string and possibly other types to avoid decomposition,
  although they do have introspection using getMember(). When decomposeType
  returns something, the getMember() method is not used for decomposition.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: detect&handle connecting two remote ports
  The implementation assumed that at least one port would be local,
  the input port. This is not the case when connecting two remote ports.
  This patch adds that detection and handles it correctly.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: disable TC state checks in testBreakUpdateHook.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: remove unnecessary cmake variable.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.1'
  Conflicts:
  tests/corba_ipc_test.cpp
  tests/corba_mqueue_ipc_test.cpp
  tests/taskstates_test.cpp
  tests/types_test.cpp
  Merged unit test fixes such that automated testing works again.
* tests: change sleeps to usleep and remove one test
  The test assumed a single-core system, such that step() had to be executed before stop()
  could be called (highest priority thread). On multicores, this test fails from time-to-time.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fixup activity construction in event-test
  This caused major system in-responsiveness.
  The wrong constructor was called.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: relax cleanup server test for ipc cases.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: don't test string concatenation in pre-2.2.0 release.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fix multi-thread xml-logging issue with task states tests.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: re-order rt-warnings in order to stress less the BOOST macros
  It beats me why this test suffers from SIGXCPU not being caught
  while the others properly handle it.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.1'
* xenomai: dump rt-warning backtraces to stderr
  It confuses the xml outputting of the unit tests (which cause this trigger
  all the time). We should probably query an environment variable for a
  disable-override.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: add setOperationThread function to change thread policy
  Allows to change the ExecutionThread policy of a previously
  added operation in a Service. For example:
  provides()->setOperationThread("start",OwnThread);
  makes that startHook() will be called in the own thread instead
  of the (default) client thread.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: fix possible race with ready() in assigning implementations to operation callers.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: move the corba server creation/deletion to separate programs
  There are two new programs built: setup_corba and cleanup_corba, which
  (on UNIX systems) create and kill the corba servers we require for the
  ipc tests. This allows you to start the servers manually and run the
  tests multiple times, and even allows to run these tests on non-unix
  systems.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fixup linking with scripting and marshalling.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: catch exceptions in case loading services or plugins throw.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: search the RTT_COMPONENT_PATH before the built-in path.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* services: log error messages when provides() has been used illegally.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge commit 'refs/merge-requests/11' of git://gitorious.org/orocos-toolchain/rtt
* fix documentation: recovered() is now called recover()
* rename flush() into a much bette readNewest()
* plugins: let PluginLoader throw if some severe errors occured
  A corrupted plugin causes an exception to be thrown.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: let plugin loader function return true or false.
  The change is not complete yet. It should throw an exception if
  a certain plugin/library could not be loaded and only return false
  if nothing could be loaded (because there's nothing).
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix typo in cmake macro.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: document that channels returned by buildChannelOutput are functional only after channelReady is called
* cmake: add -z defs during linking of components,plugins,libraries.
  Only when using gcc.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'master-global-service'
* cmake: rename orocos_typekit_headers to orocos_typegen_headers
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* add a TransportPlugin.hpp header which exposes the plugin class
* extras: define FDActivity::clearAllWatches()
  It removes all defined watches. Very useful in cleanupHook()
* define InputPort<T>::flush
  One goal of the port interface is to make the usage of
  data or buffers completely transparent to the module.
  However, to achieve getting "the most uptodate sample" available
  on a port, one would have to do a bit of logic.
  flush(sample) implements this logic
  It reads all the new samples available and returns the last one or,
  if no new sample are available, returns NoData / OldData as expected.
* corba: remove unneeded dependency on scripting
* corba: optimize CorbaTemplateProtocol in cases where the data source is a referencedatasource
  In these cases, we don't need any copying.
* corba: add a simple API to be able to configure the dispatcher's scheduler and priority
* test: in corba tests, call channelReady() before using the connection
  This is required by the connection protocol
* corba: try remote disconnection if local port disconnection fails
  There is an optimization in the CORBA connection handling that
  uses normal non-CORBA connections between local ports. A fix
  recently made sure that CORBA was able to disconnect local
  ports.
  However, there are ways to disable that optimization. So, when
  disconnecting local ports in CORBA, we must try the normal CORBA
  disconnection process if the "local port disconnection" fails.
* core: fix having OldData always return the same sample than the last NewData
  The piece of code that disappeared from the ConnectionManager is
  the one that, in select_if, was clearing the current input port
  when cur_channel is changed.
  This call ensures that there is at most one incoming channel that
  returns OldData at all times. Therefore, unless one other channel
  returns NewData, one that calls #read repeatedly will always get
  the right value. Moreover, NoData will be returned if the
  current channel is disconnected -- which is properly the best
  behaviour in this case.
  Because of this behaviour, select_if is not really a generic method.
  Rename to select_reader_channel as it is really what it is meant for.
* test: the dataflow API requires to call channelReady() on the input half before using a channel
  This was not critical before, but as part of the thread-safe
  connection/disconnection, a channel is added on the input side
  only after channelReady is called.
* allow building the test suite without scripting enabled
* corba: fix selective disconnection of local connections created through CORBA
  createConnection create a normal local connection if both
  ports are in-process. Such connections can't be removed normally
  as they don't hold a CORBA RemoteID. Fix disconnecting them.
* core: disconnect(port) is now common to both inputs and outputs, define in PortInterface
* core: when disconnecting single connections, export the information whether such a connection existed or not
* plugins: make plugin loader thread-safe.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: improve logic for collect/collectIfDone parsing.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: adapt the parser to use the GlobalService.
  There was also a bug such that 'asdfas.start()' was called on the current
  component, instead of being rejected.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* services: Add a global service, which provides a 'requires' method.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: Remove int-uint conversion warnings.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* services: add createService plugin function
  This makes services distinctive from plugins: they are able
  to create a service object for you with the createService
  function.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* engine: sanitize singleton method of GlobalEngine.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fixup UseOrocos-RTT wrt plugins and typekits
  Plugins were built/installed in the wrong location
  Added macro orocos_typekit_headers for feeding to typegen
  and changed macro orocos_typekit to take cpp files.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* idl: minor documentation updates.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: also update (C)SendStatus conversion when calling from C++.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* mingw32: link and compile warning fixes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* xenomai: support xenomai < 2.5.0 when inspecting a mutex.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* manifest: remove rosbuild dep, fix export flags for rospack
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: improve testing of plugin loading by using a project subdir.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge commit 'refs/merge-requests/10' of git://gitorious.org/orocos-toolchain/rtt
* Merge branch 'toolchain-2.1'
* engine: fix stop() such that it will call breakUpdateHook if necessary.
  stop() needs to synchronize with updateHook() in order to have thread-safe execution
  of the stopHook() with respect to the updateHook().
  The stop() mechanism of the underlying thread is used for this, such that no
  secondary synchronization needs to be implemented. I had to relax queue management
  in order to allow this running->stopped->running transition, such that queueing of
  functions or ops is still possible with a stopped engine.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* set version to 2.1.1
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: implement package/project loading
  Plugins are now loaded 'a project at a time' or a 'package at a time'.
  This means whole subdirectories are loaded, with all plugins in them,
  instead of trying to locate individual shared library files. This
  allows us to drop the 'heuristics' which were looking for individual
  files to load (which are named platform dependently).
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'master' into master-jsreng
  Conflicts (boost namespace):
  rtt/scripting/ProgramGraphParser.cpp
  rtt/scripting/StateGraphParser.cpp
* internal: implement DataSourceTypeInfo<T*>::getTypeInfo()
  Implementing getTypeInfo() for ptr types appears to be needed when dealing with ptr types used in other shared libs (typically TaskContext *).
* taskcontext: call trigger after startHook() finishes
  This will cause updateHook() to be called in case of non periodic
  tasks. The user can't call trigger in startHook because the taskstate
  is not yet running, it would have no effect.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* engine: only run updateHook after startHook
  We may only execute updateHook() when the start() function has set
  the task state to running. A target state of running is not sufficient.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: warn when loading script in non-periodic component.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: trim down broken ret_impl for remote operations
  The current implementation or ret_impl() couldn't possibly work because
  the vStore of sendargs has not been initialized in the RemoteOperationCaller
  holding a SendHandleC (only collectargs is). The current code is broken too,
  but at least takes less time to compile and less space in memory.
  Not sure if this is fixable. The prefered solution would be to remove the ret()
  feature altogether, but call() of LocalOperationCaller needs it to return
  results of a call on an OwnThread operation (using ret() on the returned
  SendHandle). So if there is another way to write LocalOperationCaller, the
  feature can be removed.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: fix collect in remote operation caller
  The returned SendHandleC from OperationCallerC was not initialized with
  the collect arguments. Hence users got a 'too few arguments' error when
  trying to collect an 1+ arity remote operatoin.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'toolchain-2.1'
* plugins: lower loglevels of 'not reloading a plugin'
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: correctly implement stack for runScript
  Variables declared on earlier lines were not recognized. This patch
  introduces a stack for each run in which these can be stored.
  More testing for all kinds of syntax as well, I had to loosen
  the function parser in order to get to the statement parsing
  without a fatal exception.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: improve verbosity of unit test.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: complete ScriptParser for all kinds of input.
  Now supports statements, functions, programs and state machines
  in any order.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: unload policy for function graphs and execution engine
  It is now mandatory to specify how a function graph must behave in execute(),
  with respect to triggering an unload action. program scripts are managed by the
  ScriptingService, and should never unload themselves. plain functions are
  not managed and must trigger the unload action by returning false in execute().
  In addition, the ExecutionEngine was modified in order to call unloading()
  in the client thread instead of its own thread in case of a removeFunction
  case.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: initial code for eval and runScript.
  Changes the caller pointer to be an ExecutionEngine instead of a
  TaskContext, such that we can pass the GlobalEngine in case the
  caller is unknown.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: add unit test for compose/decompose
  Currently, no type implements decomposeType(), so it's a quite useless
  test.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: re-introduce the compose/decompose API for types.
  It's API-compatible with RTT 1.x, but due to changes in the surrounding
  functions, not all cases of composition/decomposition have yet been tested.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* properties: provide constructor with just the name.
* doc: document compose/decompose API.
* Merge remote branch 'github/master'
* core: don't warn about lowering priority in SCHED_OTHER if priority == LowestPriority
  The LowestPriority constant should be used to pick the "right"
  priority for non-RT threads. However, on the gnulinux target, it
  is an invalid priority and therefore leads to useless warnings.
  Warn only if the user tries to create a thread in SCHED_OTHER with
  priority != LowestPriority and priority != 0
* corba: fix convertion between SendHandle status and their CORBA version
  The status in SendHandle are -1, 0, and 1 while the CORBA versions
  of it are 0, 1, 2 -- as CORBA IDL does not allow to specify enumeration
  values.
* Merge branch 'v2-next' of git://gitorious.org/~snrkiwi/orocos-toolchain/snrkiwi-rtt
  Conflicts:
  rtt/CMakeLists.txt
  tests/plugins/CMakeLists.txt
  tests/types/CMakeLists.txt
* dataflow: remove old port from interface if being replaced by new instance.
  Adds a unit test to better test port additions in services. Current unit tests
  only tested ports in taskcontexts.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* core: intrusive_ptr is not MT-safe w.r.t. destruction vs. access
  So, explicitely lock copy and reset operations on output and input
  fields in the channel elements.
* core: demote the "connection created" log message from Info to Debug
  It clutters orocos log files unnecessarily, making the rest of Info
  messages hard to find.
* corba: add missing definition of CRemoteChannelElement_i destructor
  This destructor has been added mainly for debugging purposes,
  but comes in really handy when it comes to memory leak debugging
  in the data flow. So, keep it around.
* corba: catch possible CORBA errors when deactivating channel servants
  The ORB might get stopped before all connections are shut down,
  and then the channel element's deactivation raises -- making the
  whole process crash.
* corba: properly deregister channels from channel_list
  In some cases, channels get registered in a channel_list list.
  However, they were not deregistered when disconnected.
  The explicit call to CORBA::release in the new deregisterChannel method call has
  been found by trial-and-error, so it might not be the proper fix.  However, it
  fixes a memory leak that exists without it, where the value returned by _this()
  is not freed.
* core: remove a few sources of race condition during channel disconnection
* core: make ConnectionManager MT-safe
  This is a second try. I first tried to make the original
  implementation MT-safe, but had quite a few issues on the way due to
  how things were implemented, that could not be solved as-is.
  Using lock-free data structures in ConnectionManager was harmful
  as the principle behind these data structures is that operations
  done one the elements of the structure have to be idempotent,
  which is not the case for dataflow operations. One could for
  instance have two write() on the same channel happening because
  the list is being modified at the same time than the port writes
  to it.
  Moreover, the current implementation was using an optimization in
  case of single connections, which was complexifying logic (and
  MT-safety considerations) quite a bit. I considered that it was
  therefore a case of early optimization and dropped it, until we
  get a rock-solid connection manager.
  The new implementation uses std::list and mutex for locking. The
  amount of code during which the mutex is taken is reduced to the
  strict minimum, to limit interactions between connections/disconnections
  and write/read.
* core: InputPort::read should not be able to access partially-built channels
  The problem is that the channel endpoint is attached to the port
  *before* the channel is created.
  It is in principle better to register the channel only when it is
  complete, as it removes MT-safe requirements on the channel building
  process.
* corba,dataflow: do not explicitely reset remote_side to 0
  Since the rest of the channel implementation properly handles
  concurrent disconnection + normal operations, so should the
  CORBA channel element. Setting the remote_side to 0 is not useful
  (the remote_side CORBA proxy will be deleted when the channel
  element is), and leads to crashes if a write/read is done as
  the same time than a disconnection.
* dataflow: manage both input and output with a shared pointer
  This fixes a crash-at-disconnection problem.
  All channel operations are protected with shared pointers. It means
  that when an operation propagates itself along the channel, it always
  takes a smart pointer on the next element.
  However, the 'input' attribute of ChannelElement is a plain pointer.
  In practice, it means that there is a race condition at disconnection
  time, between the disconnect operations that deletes an element and
  other operations that are trying to get a shared_ptr on it. This
  does not exist on the other direction, as we copy a shared_ptr
  into a shared_ptr.
  So, store the input attribute as a shared_ptr, and make sure that
  the disconnect operation resets both pointers to 0.
* core: give information message if we transition to FATAL because of an uncaught exception in the shutdown process
* Revert "operations: add setThread function to change thread policy"
  This reverts commit b749aa33f30864ecf9cab16dc4f8cc48bd3541ae.
  It was untested, broken code.
* Merge branch 'toolchain-2.1'
* cmake: better support for rosbuild in UseOrocos macros.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: add setThread function to change thread policy
  Allows to change the ExecutionThread policy of a previously
  added operation.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: separate orocos_service macro from orocos_plugin macro
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: add default plugin path for plugin loading at startup
  Only the deployer used a default lookup path for plugins and types.
  This patch gives the same feature to the plugin loader, allowing the
  examples etc to find the typekits and plugins, even without the
  deployer.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: avoid passing an uninitialized value into AnyConversion
  We don't pass a reference to an uninitialized value to the update function.
  This triggered run-time errors in MSVS.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: fixup SequenceConstructor mess
  The previous patch didn't really make it, and the SequenceConstructor
  functions were broken too. This patch fixes all aparant issues, and
  removes the custom constructors for 'array' in order to test
  SequenceConstructor in the unit tests.
  That all works now at least.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fix missing include of PluginLoader.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: add default constructors for each sequence type
  We can install constructors already at the time the type is created.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* properties: reverser the order of decomposition method
  We first check if convertType returns something, then we fall back to the
  propertyDecomposition function. This means that convertType now has
  priority over getMember().
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: allow to inspect a const struct type
  The type introspection can only handle assignable datasources.
  We work around this by creating an alias data source to a
  copy of the struct's member. The alias makes sure that we
  won't write the result (not assignable), while the copy is
  safe because it was const in the first place, so the original
  won't change.
  The only clean solution is to merge AssignableDataSource
  with DataSource and have 'assignability' as a property of
  DataSource. This would avoid a lot of duplication of code
  and passing around of datasources just to mimick the right
  behavior.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* dataflow: fix getting sample size for protocols that don't support it.
  We had a plain segfault if the dynamic cast failed.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* add getName to OperationInterfacePart
  This patch allows to use OperationInterfacePart's as a counterpart for
  Luas Operation class.
* fix typo in typekit manual
* doc: improve documentation for writing a typekit.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba : add AnyConversion for std::pair, std::map and std::vector
* corba : add char transport to corbalib
  since char is in the base typekit, char transport must be in corbalib
* corba : collectype must return typename
* corba: fetch services from the parent provider
* scripting: compilation fixes (namespace boost)
* Merge remote branch 'remotes/origin/toolchain-2.1' into master-jsreng
  Conflicts:
  rtt/os/win32/win32.h
  rtt/scripting/ExpressionParser.cpp
  rtt/scripting/ValueParser.cpp
  rtt/transports/corba/TaskContext.idl
* cmake: update UseOrocos-RTT macros for ros and uninstall
  Detects the ros environment, calling rosbuild_init and setting LIBRARY_OUTPUT_PATH
  Adds a 'make uninstall' target macro.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* macosx: Port rtos_mutex to support TLSF
  Only the parts of the rtos_mutex interface used by TLSF are ported.
  Must use opaque type to hide underlying C++ mutex from TLSF C code.
  Creation and destruction of rtos_mutex are NOT realtime.
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* scripting: fix parsing of strings containing whitespace
  The parser's skip_parser skipped leading/trailing whitespace in our string
  constants because the parse rule was not protected by a lexeme_d[] which
  disables the whitespace skipping.
  This bug made statements like set s = "foo is: " + 10; skip the trailing
  space.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: allow exact matching of binary operators.
  Necessary to pick the best match in case an operator is overloaded.
  Also some overloads of '+' have been added for string + number
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: use startstopmanager to cleanup pluginloader.
  I'm tracing the pluginloader since I get strange double
  frees during exit().
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: detect typegen using find_program.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* taskcontext: remove dependency on pluginloader from header
  Split of the call to PluginLoader to a separate function in cpp file.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: install user libs in lib/orocos/project_name
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: remove redundant regular file check.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: Fix nasty bug where pluginloader is created twice
  Probably a bug in gold or gcc. PluginLoader is created twice
  when the minstance static class variable is used. Using a plain
  file variable fixes this problem. Two hours of my life wasted.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix name clash of 'alias' CORBA 3 keyword.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* xenomai: prevent recursive mutex lock in trylock.
  This allows for more posix-ish behaviour.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* misc: silence some gcc compiler warnings.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix missing mqueue link flags issue.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: bump version number to 2.1.0
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: updated new TB look.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: updated changes document.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: Prevent duplicate library warning on macosx
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* cmake: Not use unknown zdefs linker flag on macosx
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* cmake: Properly deal with boost multiple installed libraries occuring in CMake lists
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* cmake: Force mqueue transport to not be used in macosx
* macosx: Correct variable name when creating main task
* doc: update version numbers in NEWS.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: minor release doc update.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* updated release notes and installation instructions for 2.1.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: updated writing typekits with more detail.
* Merging toolchain-2.0 bugfixes.
  Conflicts:
  rtt/base/TaskCore.hpp
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* taskcore: add getTargetState() for better transition semantics
  This fixes the trigger() from start() issue and also allows user
  code to assess the target state the TC is going to.
  Cfr bug #785
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: cleanup taskcore api docs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: add unit tests for trigger() and setPeriod().
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* fixup depending classes of ArrayPartDataSource after API change.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* dataflow: add missing addPort(name,port) functions to DataFlowInterface.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge commit 'refs/merge-requests/7' of git://gitorious.org/orocos-toolchain/rtt
  Conflicts:
  rtt/os/win32/win32.h
* doc: updates to plugin and changes documents.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: also define Orocos-RTT_FOUND.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: initial UseOROCOS-RTT macros.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: cleanups in scripting manual for v2.1.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Allow templated typekit typenames + dot notation
  This patch adds functions to the TypeInfoRepository such
  that 'std.vector<Bar>' lookups are accepted intead of
  the '/std/vector</Bar>' typenames that typegen uses.
  Also the parsers have been adapted to accept this notation
  in favor of the 'slashed' notation.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge toolchain-2.0 fixes before 2.1 release.
* plugins: only load libraries ending in .so,.dll,... during dir scan
  This was necessary to let the symlinks to their work, ie
  point to the most recent version, unless the user overrides
  with a specific version (like foo.so.1.2.3) in which case
  that version is loaded. So the .so|.dll|.dylib extension
  restriction only applies when scanning a whole directory
  for plugins or types (RTT_COMPONENT_PATH subdirs etc).
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@33156 ce417995-dfc9-0310-95a0-acdaff106893
* win32: tweak turning off optimizations in scripting
  Due to a bug in MSVC 2005, the eol skipper's operator() ends
  up with a null reference of the skipeol member.
  Tried several workarounds, could not find one,
  except turning off optimization for this function.
  Port of 1.x branch
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@33151 ce417995-dfc9-0310-95a0-acdaff106893
* activity: do not start periodic activity's thread during construction.
  Since PeriodicActivity will start it's thread automatically during start(),
  there's no need to start the thread during construction. This was also
  necessary such that the SimulationThread was not automatically started
  with the creation of SimulationActivity, since the latter inherits from
  PeriodicActivity.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@33150 ce417995-dfc9-0310-95a0-acdaff106893
* list: use recursive mutex to allow apply-within-apply
  When the RTT is built with OS_NOASM, this list is used by
  the StateMachineProcessor, which uses apply both in
  step() and in finalize(). As such, a stop() within step()
  will call finalize, and the implementation would dead-lock.
  The solution is to use a recursive mutex and warn against
  faultive use of apply (like calling erase/clear within apply()).
  Port from 1.x line.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@33149 ce417995-dfc9-0310-95a0-acdaff106893
* types: do type conversion on [] arg of sequences.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: debugging can cleanup of CArrayTypeInfo.
  Fixed crash in CArrayTypeInfo when wrong [] parameter was given
  Do conversion on [] parameter
  Add safety to ArrayPartDataSource to do bounds checking
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: allow to index read-only sequences.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* os: fixup buggy patch in Thread.cpp
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* os: improve scheduler/period changes of running threads.
  A change in period would cause step() to be executed twice
  after each other.
  A change in the scheduler was not picked up if the thread
  was periodic and running.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tlsf: include missing string.h header.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cleanup: check return values of pipe and write.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: link mqueue transport with 'rt' when building for lxrt
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cleanup: add missing errno.h includes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: improve FindRTAI to find linux tree in more places.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* lxrt: fix fosi warning and compilation errors.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* extras: fix compilation error with some compilers.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: prepare RTT to handle typekit constructors of sequences.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merged with fixes of 2.0.2 release.
  Conflicts:
  CMakeLists.txt
* Version 2.0.2
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: also parse properties in services.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* only search all paths if no specific path was given.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: set install prefix in main CMakeLists.txt file
  As noted on the cmake mailing list, you must use CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT
  in order to set CMAKE_INSTALL_PREFIX. I've removed the
  setting from the orocos-rtt.default.cmake file since
  it didn't work and is tricky to pick up if the user
  has set his own.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: install by default in Program Files/orocos on win32.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* config: fix bug in RTT_EXPORT for win32 api
  The RTT_EXPORT was set to import accidentally while it should
  always be set to export, no matter who includes it.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: fix plugin loader shortnames and improve error reporting.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* test: boost namespace
* Merge branch 'psoetens-toolchain-2.0-fix-corba-send' into master-jsreng
  Conflicts:
  rtt/transports/corba/OperationInterfaceI.cpp
  rtt/transports/corba/RTTCorbaConversion.hpp
* corba: compat with TAO 5.8.0
* internal: Add default constructor to ArgumentDescription
* taskcontext: operation doc() cleanups.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* datasource: fix getType string in create_sequence.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: also test event ports with callbacks.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* taskcontext: fix segfault in addEventPort
  Tiny typo causing a tiny segmentation fault.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: use CMAKE_LD_FLAGS_ADD instead of hard-coded link flags.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: linking/config fixes for mingw32 builds.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* nameserver: fix scope issue of iterator.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* taskcontext: fix api docs of addEventPort.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: warn about not using the orocos-ocl.cmake file for cross-compiling.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: fix boost detection bugs as reported on ml.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* properties: fix bug where C++ used different data as scripting
  The wrong constructor of Property was invoked during addProperty<T>(name, value).
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix remaining issue during TC objref creation.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: add missing include dirs for orocos-rtt-config.cmake file.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: set master branch version to 2.0.90
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* merge fixes on 2.0 branch and corba memory cleanups.
* cmake: add missing include dirs for orocos-rtt-config.cmake file.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: throw no_asynchronous_operation_exception in FunctionFactory
  Until send is implemented, the factory throws this documented exception.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: implement setAutoCollect feature
  This allows the user of a SendHandleC to determine if that object
  should collect upon destruction or that it can safely free resources.
  This flag is shared between all copies of the same SendHandleC.
  Resources can be cleaned up safely during remote invocations,
  but need to be kept until the op completes for local invocations.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: major memory leak cleanup in various places.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: implement dispose() for CSendHandle.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: minor memleak fixes in corba tests.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: add plain simple corba test + new cmake macro.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: provide Release() functions to free memory
  They are typically only used at application cleanup.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tlsf: use safer init detection flag.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* os: free globals and typekitrepos.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* datasources: free actions in ActionAlias destructors.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* services: free attributes in destructor.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* squash
* corba: use forceActivity instead of setActivity in proxy setup.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* taskcontext: add forceActivity method to bypass isRunning() check.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* taskcontext: fix memleak in destructor.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: correctly override activity in proxies.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix memleaks and orb destruction in TaskContextProxy.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: temporarily lift blocking collect from OperationKeeper
  There is still a bug in there which deadlocks the destructor of OperationKeeper.
  It blocks in the remote Global EE which never receives a message. Strangely
  enough, also the is_executed flag is still false, so the blocking seems
  legitimate. So we are checking the wrong flag, or the UnitTest effectively tests a deadlock,
  and it's a UT bug.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: fix use of OperationCaller: specify caller's engine.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: extend callback test with logging of nesting.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix whitespace error.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix bugs in anyconversion for TaskContext*.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: better error reporting for unsupported types when calling operations.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: initial patch for passing peer pointers in operations.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: give transports a chance to register their fallback protocol.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: add dispose() method to CSendHandle interface.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: throw exceptions instead of asserting.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* internal: only block in ~SendHandleC when last ref is dropped
  This is done using a special OperationKeeper struct that blocks
  on the operation when the last SendHandleC wants to destroy it.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: fix crash when cleaning up operation caller after send().
  In the OperationCallerC/SendHandleC combo, the arguments are stored in DataSources,
  which are kept (indirectly) by the OperationCallerC. In case this object is
  prematurely destroyed, the operation will segfault because of freed arguments.
  The solution is to let SendHandleC also have a refcount to the operation's
  data source and block in the destructor until it completed or failed.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: initial callback-test server code.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: let corba test servers load typekits.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: fix bug in remote collect, which ignored the 'blocking' flag
  A typo: datasouce.get() which should have been datasource->get() :-(
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: call evaluate() on data sources in fallback protocol.
  Since void returns are implemented using the fallback protocol, they need
  to evaluate the datasource, as if they were reading it. If not,
  a remote operation would not be executed.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: encode shared_ptr in operation signature for DS case
  The shared_ptr is now explicitly encoded in the operationDS variants
  such that it does not clash with normal pointers. This was necessary
  to allow TaskContext* pointers in operations to allow callbacks.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* services: fix endless loop in service destructor.
  The while construct seems very fishy. It's unclear why it
  worked before. It triggered an endless loop (logically).
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fix typegen command line example.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fix missing tag in xml docs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: package version 2.0.1-1
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Version 2.0.1
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Revert "From bug 681: Add missing install files for debian."
  This reverts commit ff3a883087c05cb5612579d22e5afe567f259895.
  Conflicts:
  debian/liborocos-rtt-common-dev.install
* Merge branch 'rtt-2.0-mainline'
* fwd: update forward decl headers.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* dataflow: document connection factory.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* dataflow: fix bug in creation of output streams
  A typo caused that only the first element of the created stream was used.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Removed-xerces-depdom-dependency
  FindXerces.cmake no longer looks for xerces-depdom, because it is not used by orocos-rtt, and because in Xerces 3.x this library ceased to exist.
* mqueue: fix serialization of array types.
  make_array() returns a const& to a boost::serialization::array object,
  which is unusable for loading (due to the const). A specialisation
  catches this case and forwards it with a &boost::serialization::array
  object.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: updates to manuals wrt RTT 2.0.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: set version to 2.0.0
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Version 2.0.0
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* license: add default license to all files.
  Consult 'git blame' to see effictive lecense holders for each line of code.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripts: fix update-headers script wrt new directory structure.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: fix id issue with fig-hello-world and missing images.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: update .install files and no longer package static archives.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: give corba test more time to settle on incoming data.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* mqueue: move mqueue implementation from template to lib.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: Also allow '.' in typenames (Experimental)
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugin: fix include typo in Plugin.hpp
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian:fix which headers/paths get included in -dev package.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* mqueue: fix link bug with Xenomai.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* debian: fix dependencies wrt boost-dev.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Relax cmake version again to 2.6.2
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: add notes about new transports.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: fix missing namespace in EnumTypeInfo class.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugins: fix wrong include statement in Plugin.hpp
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: Fix typo in release notes.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* boost: avoid nameclash with C++0x implementation in vs2010 (mainly bind and shared_ptr)
* win32: missing include
* corba: do not use keywork for variable name (compatibility TAO 5.8.0)
* corba : fix two calls to remote method
* cmake : do not override TAO\_*_HINTS if TAO_ROOT is found
* win32 : missing symbol
* win32: don't export inlined functions
* cmake: set version number to 2.0.99
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba : fix two calls to remote method
* doc: update news and readme for v2.0
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: orocos-rtt-changes updated for 2.x
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: doxygen comment cleanups.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'master' into master-jsreng
* scripting: relax constraints on typenames (experimental)
  Added "/<>" to valid characters in typenames + removed the alpha_p
  constraint on the first character of a typename.
  This is allowing a very broad set of typenames, it might be narrowed
  again to alpha_p + / + ...? lateron when the dust settles.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: also set OROCOS-RTT_PATH in config file (replaces OROCOS_INSTALL) (fixup)
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* corba: split rtt typekit specific any conversions to separate file.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: also set OROCOS-RTT_PATH in config file (replaces OROCOS_INSTALL)
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: minor install cleanups for 2.0.0 release
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: bump version to 1.99.5
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: treat component/plugin/type paths differently and seperately.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Initial working version of find script
  - Added support for finding plugins and transports
  - Variable naming has been made more consistent with the rest of RTT
  - Added package use file
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Added generation of package configuration files to RTT project
* Added initial cmake package configuration file support.
* corba: fix value to any conversion of data sources in the transport
  update/createAny *must* evaluate() its datasource. Otherwise, value()
  may return an uninitialized value. The method factory on the
  other hand must provide dummy data sources to checkArguments() such that
  the real data sources are not yet evaluate()d during produce().
* types: add rt_string type and typekit.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: install oro_noasm files.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* operations: lower max_arity of fusion to reduce compilation times.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* marsh: add storeProperties to service.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: manually merge new FindACE/TAO macros to take into account optimized/debug libs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: added NOMINMAX for windows.h to avoid name clash
* cmake: correct .pc generation for optimized/debug libs.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: fix erroneaous CloseHandle() in dlsym wrapper
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Fix wrong include of rtt-config.h
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: add eol_skip_functor to API.
* cmake: fixup include dirs during build.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* tests: lower period to 1ms->4ms for tests in order not to churn win32 platforms.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  Conflicts:
  tests/tasks_multiple_test.cpp
* plugins: fix path parsing on win32 platforms.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: cleanup dlfcn and win32 headers.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: decorate dlfcn functions with RTT_API.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* api: export IntrusiveStorage as api symbol.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* api: export CommonParser in dll.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* misc: fix all remaining compilation warnings on win32.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  Conflicts:
  rtt/Logger.cpp
  rtt/scripting/Parser.cpp
  src/RealTimeToolkit.cpp
  src/Types.cpp
  src/os/PeriodicThread.cpp
  src/os/win32/fosi.h
  src/scripting/CMakeLists.txt
  src/scripting/ValueChangeParser.cpp
* win32: Added _WIN32_WINNT definition to use TryEnterCriticalSection.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* plugin: add RTT_EXPORT to plugin functions.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* win32: do not warn for nbr 4250.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* cmake: remove dead code from cmake file.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* marsh: raise precision of marshalling double precision numbers.
* cmake: fixup linking and definitions of symbols after win32 port.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  Conflicts:
  config/FindTAO.cmake
* cmake: Cleanup find_package(Boost) trickery. Only call it once for all deps.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
  Conflicts:
  config/check_depend.cmake
  tests/CMakeLists.txt
* cmake: remove custom debug lib suffix in favor of cmake 'postfix' property.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Revert "cmake: define CMAKE_DEBUG_LIB_SUFFIX as 'd' on win32 targets."
  This reverts commit 14f6f10696eba830849350628b0e02a3232b9a91.
  Conflicts:
  tests/types/CMakeLists.txt
* cmake: hack the hack for FindBoost.cmake.
* cmake: also install oro_noasm headers.
* tests: create fixtures library and split .cpp files.
* Merge commit 'refs/merge-requests/7' of git://gitorious.org/orocos-toolchain/rtt into rtt-2.0-mainline
  Conflicts:
  rtt/internal/DataSourceStorage.hpp
  tests/method_test.cpp
  Minor conflicts due to Method->OperationCaller renaming on master.
  It was necessary to set BOOST_FUSION_UNFUSED_MAX_ARITY since it only defaults to 6 and
  we need 7.
* remote: fix remote method implementation wrt (const) refs for 5,6,7 args.
* remote: fix remote method implementation wrt (const) refs.
  The pointer to the data can only be filled in after the method
  has been invoked. So we require 'Late' data sources that allow
  to set this pointer after the data source has been constructed,
  but before the target method reads them out.
  There is likely a similar issues with return values, which has
  not been fixed or tested yet with this patch.
* os: WaitPolicy -> WaitPeriodPolicy
* corba: removed Services.idl and related files
* Revert "corba: Rename Service.idl -> ServiceProvider.idl to avoid nameclash between ServiceS.cpp and Services.cpp for case insensitive OSes (like windows)"
  This reverts commit f7e5756f0da24b02b7fa01f37d44768568197196 and d7806cf7e33b7c2848d29aa905db1900ff41b5c0.
* doc: update doxygen doc of PropertyBag.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* doc: cleanups to introduction in component writing.
* doc: new figure to show component deployment.
* internal: also fix getArgumentList() for DS style operations.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* scripting: do not try to remove a service if it's not there in parent.
* scripting: minor rename of private function.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'master' of gitorious.org:orocos-toolchain/rtt into rtt-2.0-mainline
* tests: silenced failing property test.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* dataflow: move dataflow interface into service and remove updateHook(ports).
* types: make failure of update() an Error log message
* corba: small documentation update in the IDL
* corba: expose a way to recover from the Exception state
* renames: corrected all includes of moved headers.
* Merge commit 'refs/merge-requests/8' of gitorious.org:orocos-toolchain/rtt into rtt-2.0-mainline
  Conflicts:
  rtt/internal/RemoteOperationCaller.hpp
* corba: fix value to any conversion of data sources in the transport
  update/createAny *must* evaluate() its datasource. Otherwise, value()
  may return an uninitialized value. The method factory on the
  other hand must provide dummy data sources to checkArguments() such that
  the real data sources are not yet evaluate()d during produce().
* doc: fix documentation of RemoteMethod.
* remote: fix remote method implementation wrt (const) refs.
  The pointer to the data can only be filled in after the method
  has been invoked. So we require 'Late' data sources that allow
  to set this pointer after the data source has been constructed,
  but before the target method reads them out.
  There is likely a similar issues with return values, which has
  not been fixed or tested yet with this patch.
* Merge interface namespace into main namespace
* Rename OperationRepository to OperationInterface
* Rename some AttributeRepository to ConfigurationInterface which slipped through
* Rename some ServiceProvider to Service which slipped through
* corba: Forgot files in renaming Service -> ServiceProvider
* Rename Method to OperationCaller
* types: use find() instead of at()
* corba: Rename Service.idl -> ServiceProvider.idl to avoid nameclash between ServiceS.cpp and Services.cpp for case insensitive OSes (like windows)
* internal: BindStorage: AStore<T const &> must not be returned when collect or return is called.
* os: Added setWaitPolicy()
* fosi: added rtos_set_wait_policy for RTOSes (do nothing) and MacOSX
* os: Added setWaitPolicy() method
* fosi: introduced wait policy for enabling "relative" timestep padding
* method: methods with 5 args: missing specializations
* methods: add methods with 6 and 7 arguments.
* scripting: disable optimizations on Release Builds for win32 (fixes crashes in boost.spirit)
* plugin: strip the extension from last result
* internal: namespace clash with boost::lambda on win32
* cmake: missing debug suffix
* cmake: add copy for debug version on win32
* win32: missing symbol
* Merge commit 'refs/merge-requests/4' of git://gitorious.org/orocos-toolchain/rtt into rtt-2.0-mainline
* corba: prefix the state enums with 'C' so that Exception does not clash with the IDL keyword
* Merge commit 'refs/merge-requests/6' of git://gitorious.org/orocos-toolchain/rtt into rtt-2.0-mainline
  Conflicts:
  rtt/base/PortInterface.cpp
  Had to re-add the 'addSynchronousOperation' fix in PortInterface.cpp
* Rename AttributeRepository to ConfigurationInterface
* Rename ServiceProvider to Service
* corba: add the missing Exception state in the list of states in CTaskContext
  That state has unfortunately to be named ExceptionState since
  Exception clashes with the exception keyword (IDL is case-insensitive)
* corba: expose the transport plugin
  This is so that one can load the plugin manually, instead of
  having to rely on the RTT plugin loader.
* plugin: accept absolute paths in loadPlugin and loadTypekit
* operations: add synchronous operation factories
  This patch makes it possible to register an operation as synchronous.
  The port services use this in order to install a reduced version of
  their read/write/last operations, which are only meant for in-component
  thread, ie synchronous, usage.
  Synchronous operations are not exported throught the CORBA layer.
  This solution is here to reduce compilation time of typekits mainly,
  and partly because reading/writing ports should only be done by the
  component itself.
  If we find a better solution, this approach may be deprecated.
  In-process asynchronous usage of the operation will still be tolerated,
  since it's only the Service interface that is limited, not the Operation
  object itself.
  Initial patch suggested by Sylvain Joyeux and worked out by Peter Soetens.
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* types: correct log messages in SequenceTypeInfo.
* marsh: add unit test for loading and storing properties
  Fixes updateProperties such that it does composition of newly created
  properties.
* marsh: add storeProperties function to dump props to file without reading it first.
* tests:standardize name of files generated during tests
  Allows us to clean them up before a next test-run is done.
* Merge branch 'master-gitorious' into rtt-2.0-mainline
* Merge branch 'rtt-2.0-mainline-enum2' into master-gitorious
* Merge branch 'rtt-2.0-mainline-operation-fixing' into master-gitorious
* corba: small code clarity check
  Use the positive check "#ifdef CORBA_IS_OMNIORB" instead of the negative
  "#ifndef CORBA_IS_TAO" as the second one is more confusing.
* test: fix test case for FileDescriptorActivity
  The main change is that start() is now called at first, as the RTT does for the
  task context.
* properties: cleanup some warning messages.
  PropertyBagVisitor has no means to know if it's a warn/error situation
  if it can't decompose/convert a property. PropertyIntrospection does.
* types: drop getAssignable from TypeInfo interface.
  Replace by dsb->isAssignable(). getAssignable was just doing a narrow.
* properties: add support for updating/refreshing enum-like types
  This implementation is probably going the wrong way and most of the
  logic update/decompose/convert logic should reside in the type info class.
  However, it passes the unit tests.
  Food for post-2.0.
* Merge branch 'rtt-2.0-mainline-operation-fixing' into rtt-2.0-mainline
* Fix getArgumentList bug.
* methods: document and fix copy semantics of Method.
  Always take a deep copy and fix the cloneI() implementation of RemoteMethod.
* operations: finish create_sequence helpers.
* engine: fix reported memory leak in destructor.
* operations: improve code size of create_sequence by using helper
  Avoids a combinatorial explosion of template classes, ie
  for each signature, all functions are regenerated.
* tests: add test to check API of AtomicMWSRQueue.
* aqueue: fixes and cleanups in isEmpty and isFull.
* aqueue: fix dequeue where it writes its argument when it must not.
  Code that relied on the argument not being written failed
  when calling dequeue with a non-null argument.
* engine: fix race in EE where AQueue's isEmpty returns false, while data is not yet ready.
* tests: do not link service_test with marsh/scripting plugins.
* types: move getType() into DataSourceTypeInfo and improve operation error message when wrong arg is given.
  Since a DataSource can only be of bare type T, we need
  DataSourceTypeInfo to create the getType() string containing
  the const/ref qualifiers.
  Operations use this class to create wrong arguments exceptions.
* aqueue: fix race in clearing the read pointer.
* methods: make clone of Operation implementation in order to set the caller EE.
  Setting the caller EE on the original is plain wrong and would
  get overwritten by the next user right away.
* method: added new unit test for method and ref args.
* types: finish enum typeinfo implementation.
  A new function 'convertType' was necessary at the TypeInfo API in order
  to give the enum a chance to convert itself to/from int or string.
* types: handle enum a little bit better. Still broken.
* marsh: move PropertyBagIntrospector header impl to cpp file.
* core: fix small typo in PropertyIntrospection
* types: add extra check in introspection in case it's not known and not convertible.
* types: misc doc/log cleanups in TypeInfo templates.
* tests: refactored types unit tests to be easier on the RAM.
* types: added initial enum type info template.
* build: do provide .so symlinks for plugins
* tests: add missing include.
* internal: add getOrp() and getName() to MethodC as well.
  cloneI() of RemoteMethod needs this in order to make proper deep copies.
* build: make really sure that local directories are considered first in the include directory list
* Merge remote branch 'autobuild/master'
* dist: add vim swapfiles to the ignore
* extras: make FileDescriptorActivity compatible with RTT2
  In RTT2, activities are started right away. It means that they *must*
  be configurable at runtime, something FileDescriptorActivity was not.
  In the process, make the use of watch() and unwatch() totally
  thread-safe.
* define getActivity<T> to get a dynamic-cast'ed activity
  The reason is that some activities require specific configuration
  (e.g. FileDescriptorActivity) and the user therefore has to get
  access to the cast-ed activity. This method makes it much cleaner
* extras: document ReadOnlyPointer
* readonlypointer: do delete the value in the optimized path of reset()
* os: make SingleThread exception-safe around loop()
  It now properly sets inloop to false if an exception is thrown from the
  activity's loop()
* FileDescriptorActivity: when reading the communication pipe, check that read() returns 1
* FileDescriptorActivity: issue a warning if a timeout occur
* FDActivity: do not assume that NonPeriodicActivity::stop() waits for loop() to return
  If stop() is called from within a hook (as for instance because fatal() is
  called in updateHook()), then NonPeriodicActivity::stop() will NOT wait for
  loop() to return.
  This was causing an infinite loop as FileDescriptorActivity::stop() was closing
  the communication pipe, and then FileDescriptorActivity::loop() never stopped.
  Close the pipe in loop() to fix that.
* core: fix misuse of grow()
  When the connection management was implemented, I thought that grow() was adding
  one more element to the lock-free list. It actually does not: it only grows the
  expected size of the list.
  I think grow() is dangerous, and therefore replaced its use by reserve() with
  a total size. This fixes crashes when more than 10 connections were created on
  the same port.
* corba: display informative CORBA-related errors
* properties: use more decent fix for evaluating the data source before using it in a property.
* properties: add unit tests for PropertyLoader
  Tests saving/configuring/loading of all/some properties
  Tests saving/configuring of unknown properties.
  Not all tests pass yet due to bugs in the property decomposition code.
* cmake: don't depend on scripting/marshalling in method_test.
* operations: fix crash during call() of an OwnThread operation with out args
  The unit tests failed to capture this case because the Method
  constructor did not pass the ExecutionThread policy to LocalMethod.
  The bug was due to an untemplated call to send_impl, which took
  its arguments by value instead of by reference.
* scripts: remove dead coverage code.
* add a small manifest
* atomic: fix curiously recurring bug in clear().
* Extend SendHandleC with OperationRepositoryPart
* transports: rename transport libraries to rtt-transport-<transporttype>
* internal: fix bug in getArgumentList that does not return the last argument of an operation.
* cmake: rename 'target.in' to 'target-config.h.in'
* typekit: fix rtt-typekit-config include.
* typekit: install rtt/typekit/rtt-typekit-config.h
* internal: fix missing includes.
* tests: do not use RTT typekit header.
* internal: fixup missing includes.
* base: fixup missing includes in header.
* typekit: cleanup rtt typekit header.
* types: fixup missing namespace qualifiers in headers.
* scripting: fixup missing includes in headers.
* internal: Fix compilation issue in locked queue.
* cmake: remove corba debug message.
* tests: fix typo in debug filename of typekit_plugin test lib.
* doc: document extern C plugin issue and adding event ports.
* mpool: improve unit tests by using more 'require' instead of 'check'.
* tspool: fix destructor check and improve unit tests.
  The BufferLockFree clears its contents such that the elements are given back
  to the tspool. The check in the destructor of TsPool was wrong and did not
  work with unordered returned blocks.
  A non thread-safe size() member function was added to ease checking during unit tests.
* Use MWSR queue implementation in BufferLockFree.
* taskcontext: use MWSR queue for messages and function queues.
* taskcontext: use MWSR queue for tracking port events.
* internal: implement multi-writer/single-reader atomic queue
  Seems to perform according to unit tests. Can hold 65000
  elements due to use of union. Will be used by almost/all
  objects that use AtomicQueue right now.
* taskcontext: use Queue intead of AtomicQueue.
* Revert "plugins: get the right substring for shortname"
  This reverts commit 20de4c4caeadb1dc94a108b254da72171ad3c327.
* plugins: minor fixing of log() output.
* extras: silence 'valid' test of broken ReadOnlyPointer.
* mqueue: fix disconnection of input port in case stream setup failed.
  Also adds the same test for an output port.
* internal: fix compiler warning during Release builds.
* internal: fix compiler warning wrt signedness
* buffers: fixup TsPool and BufferLockFree and update unit tests
* buffers: remove lockfront from AtomicQueue api.
* buffers: switch to TsPool memory pool implementation.
* ports: move ConnPolicy implementation into cpp.
* attributes: move loadValues implementation to cpp file.
* buffers: drop *counted versions of enqueue/dequeue.
* buffers: refactor BufferInterface and drop EventDrivenActivity
  ReadInterface, WriteInterface and the (Non)Blocking policies are all
  gone. The former are merged into BufferInterface which now inherits
  directly from BufferBase. The latter no longer fit in the current
  architecture. front() has been dropped in the light of hard to
  implement in lock-free and multi-threaded settings. It was also
  unused in the current data flow
  EventDrivenActivity, which depended on the blocking policies has
  been removed from extras.
* properties: deprecate the introspection API.
* corba: provide better log messages when attributes can't be built.
* cmake: define CMAKE_DEBUG_LIB_SUFFIX as 'd' on win32 targets.
* beta4: update release and README files.
* Merge branch 'rtt-2.0-mainline' of git://github.com/jsreng/orocos-rtt into rtt-2.0-mainline
* services: define shared pointer also for MarshallingService and ScriptingService classes.
* os: fix bug in reading return value of StartStopManager causing deployer to quit.
* properties: fix type decomposition logic
  * strings should not be decomposed, although they can be
  * evaluate a part first before putting it in a property.
  The later would otherwise cause hard to trace segfaults since
  rvalue() returns a null pointer.
* scripting: move ConditionInterface into scripting and cleanups
  Also CommandFunctors is moved into scripting, the include of
  rtt-scripting-config was fixed too.
* cmake: Correct include directories for marsh/scripting.
* types: fix  missing namespace.
* internal: cleanup command functors.
* internal: remove old command implementations.
* taskcontext: no longer include scripting plugin headers.
  These headers were unused.
* Bump version number to 1.99.4 (beta4)
* base: remove DispatchInterface header.
* base: remove CommandInterface header.
* properties: remove property commands.
* internal: remove unused header.
* types: updated doxygen documentation.
* datasource: remove unused DataSourceAdaptor header.
* types: renamed getPart to getMember
  Was too confusing wrt OperationRepositoryPart.
* fosi: remove log() statements in normal code path of Thread class.
  Only on errors and during creation/destruction/modification
  changes are printed. This to allow more use from real-time
  contexts.
* lxrt: fix potential memory allocation in fosi.
* extras: fix valid() of read only pointer.
* xenomai: fix potential memory allocation.
* datasources: improve storage+return of return value
  This avoids that an unnecessary copy is made when the user calls
  evaluate() + rvalue(). It also allows to store const and const&
  correctly, ie without making a copy when being returned from the
  RStore.
* datasources: fix bug in reading fused arguments.
  The datasource argument was never evaluated, so rvalue()
  returned the default value. This broke all cases where
  another fused datasource was the argument of a fused datasource.
  Extended unit test to test both cases at beginning of program.
* ports: fix crash due to double deletion of connection ID.
* datasource: read a fused functor before writing it.
  If a functor returns a reference and the users wants to write its data
  source using set(), it must first be invoked in order to get the
  address where to write to. So a set() = get() + write.
* methods: add is_strict_reference for better reference detection logic.
* xenomai: allow priority=0 for xenomai >=2.5.0
* methods: specialize FusedFunctorDataSource in case of reference returns
  reference returns of fused functors are assignable data sources.
* types: log when a part of a struct can not be given.
* mqueue: fix missing include header.
* update property_test to new DataSource API.
* datasource: update DataSourceGenerator to new API.
* ports: fix compilation issue with new DS API.
* mqueue: adapt to new DataSource API.
* corba: adapt to new DataSource API.
* fix compilation issues with addOperation refactoring.
* internal: adapt to new fusion sequence API.
* scripting: adapt to new DataSource API.
* corba: update Corba transport to new datasource API.
* datasource: remove deprecated serverProtocol() function.
  Old 1.x artefact.
* fix compilation of RealTimeTypekitTypes.
* fix compilation of OperationRepositoryPartHelper.
* transports: remove obsolete references to narrow, proxy and server.
  Unused RTT 1.x CORBA specific methods have been removed.
* operations: refactored type independent code out of template factory class.
  A small change with noticable reduction in code size.
* services: refactor duplicate code out of addOperation.
* interface: move constructor of ArgumentDescription to cpp file.
* ports: refactor type independent code out of template classes
  The ConnFactory contained too much type independent code in
  its factory functions. These have been moved to template-less
  functions. TypeMarshaller lost its template status too.
* datasources: Adapt factories to new DataSource API.
* datasource: fix datasource storage containers wrt template types
  The created (Const)ReferenceDataSource instances must have value_type
  types as template arguments.
* datasource: implement rvalue() in most data sources.
* datasource: remove all occurences of AdaptAssignableDataSource.
* datasource: remove most occurences of AdaptDataSource.
* datasource: move AssignableDataSource::rvalue() up to DataSource.
* datasource: DataObjectInterface is no longer a DataSource.
  This allows to remove the 'null' clause on AssignableDataSource::rvalue() and set().
  It's a first step in slimming down the DataSource bloat.
* cmake: only compile plugin dir if plugins enabled.
* properties: add two new tests to detect errors in marshalling.
* properties: set new value to datasource directly in update/copy.
* plugins: improve logging of plugin scanning process + ignore symlinks.
* types: do not warn when a read-only is not decomposed.
  It is desirable that a read-only part of a type is not
  decomposed into a property. So we don't warn about it.
* plugins: get the right substring for shortname
* win32: use the right thread Id
* marsh: fix include directive bug.
* scripting: fix wrong include directive.
* methods: add methods with 5 arguments
* win32: rewrote semaphore functions
* cmake: add date_time
* cmake: revert DEBUG_OUTPUT_NAME 'd' prefix until the issue is fully fixed
  All stuff stops working after adding the 'd' (.pc files, plugin loading,...)
* cmake: install rtt-config files and correct its include directives.
* ports: minor compilation error fix.
* services: put OperationRepositoryPart in it's own header
  + new header for OperationRepositoryPartFused.
* Merge commit 'jsreng/rtt-2.0-mainline' into rtt-2.0-mainline
* mqueue: boost version check fix.
* Revert "scripting: temporarily break dependency toward scripting module"
  This reverts commit 51b89cb8f9e35456c6bde02d9b428fdc1e4f6b5d.
* doc: Fix api docs of OperationRepositoryPart.
* taskcore: fixed missing virtual in getTaskState.
  Required for getTaskState() in TaskContextProxy instances.
  + easthetic virtual decorations in TaskContext code.
* method: don't use lambda::boost here
* win32: visual doesn't like empty defines
* tests: add setenv for win32
* marsh: correct includes
* types: use boost::lambda::
* cmake: use ${CMAKE_COMMAND} instead of cmake
* cmake: postfix debug dll name
* cmake: use explicit prefix for win32 DLL
* win32: separate definition and declaration
* cmake: restore RTT\_${NAME_OF_LIB}_DLL_EXPORT symbol for win32 DLL
* cmake: missing flags
* merge with peter's branch
* cmake: added boost.serialization dependency
* types: missing symbols
* typekit: replace RTT_API by RTT_TYPEKIT_API
* scripting: replace RTT_API by RTT_SCRIPTING_API
* win32: missing symbols
* marsh: replace RTT_API by RTT_MARSH_API
* win32 : missing symbol
* win32: missing symbols
* scripting: temporarily break dependency toward scripting module
* types: don't try to compose a propertybag if the types don't match.
* properties: do not refresh bag if typed and types differ.
* types: fixed boost api detection in archive loading code.
  Change occured in boost 1.41.0, need boost/version.hpp to check
  version number.
* cmake: install plugin libraries with .so symlinks.
* cmake: rework library/plugin definitions + add_rtt_plugin/typekit macro
  * plugin and typekit/transport libraries are now created using a macro.
  * renamed all occurences of *_dynamic-TARGET to *-TARGET_dynamic.
  Same for _plugin and _static occurences.
  This gives the targets saner names.
* mqueue: minor api doc addition.
* types: cleanup typekit/transport loading
  TypekitPlugin and TransportPlugin objects become owned by the TypekitRepository.
  Transports also need to provide a 'typekit' name for which they are intended.
  Transports are names as in CORBA://rtt-types.
* plugins: dll-tag PluginLoader class and minor rewording in log messages.
* tests: only test testReturnExportFunction when remoting is on.
* cmake: default ORO_REMOTING to ON.
  Both scripting and CORBA require this feature in
  order to expose methods to the C++ code.
* os: Fix Condition implementation when using boost::thread.
  Revert to the less performant condition_variable_any which can work
  with any mutex type (we use mutex_timed) instead of the more performant
  condition_variable class. Needs work on Mutex and MutexLock to make
  boost::thread::condition_variable work out of the box.
* types: boost >= 1.42 compatibility
* win32: syntax
* win32: added dl* function wrapper
* win32: added setenv
* win32: missing symbols
* doc: fixed doc of TaskCore::isRunning().
* tests: add missing property_loading.cpf file to unit tests.
* types: fix compilation issue in type decomposition on boost 1.42 and newer.
* cmake: create rtt/plugins directory such that unit tests can work.
* cmake: must specify archive for import libs on windows
* Merge with peter's branch
* doc: updated docs regarding TaskState.
* doc: added better docs for '.' operator.
* doc: cleanup of images.
* taskcontext: update state change semantics
  According to the discussion on orocos-dev, an 'Exception' state
  was added which is entered if any *Hook throws and FatalError
  is only entered upon fatal() or throwing in exceptionHook().
* scripting: add unit tests for event transitions + test cleanups.
* operations: named operations may be added to interface.
* scripting: fix SM loading wrt event transitions and add tracing.
* internal: implement set() for sequences.
* tests: fix valgrind warning about uninitialized variable.
* scripting: re-add the event transition logic and unit test (broken)
  The code's there, but the unit test fails.
  allows syntax: transition myop(args) {...} select S
  where myop is an operation of the component.
* methods: set default implementation for 'empty' operations.
  This allows these ops to be added to the provides interface,
  such that op->signals() can be called later on, also if no
  implementation is given.
* methods: add the produceSignal method to all operation part factories.
  This method was implemented for the OperationRepositoryPartFused, but
  not present in the part interface or the other derived classes.
* tests: remove obsoleted header.
* properties: fix occurence of removed class in Property constructor code.
* corba: remove obsolete header.
* rtt-fwd: minor updates.
* plugins: fixed plugin installation after build.
* scripts: update fwd generator script with new dir structure.
* typekit: moved typekit files in typekit plugin library
  The default RTT typekit is now a separate plugin.
* plugins: install scripting&marshalling in lib/orocos/plugins.
* corba: update typekit registration functions to new API.
* plugin: rename RTT_PLUGIN_PATH to RTT_COMPONENT_PATH
  This allows to share the same env variable with deployment,
  and is also more accurate in name.
* taskcontext: add some null pointer checks in peer functions.
* cmake: Bump version number to 1.99.3
* plugin: update class doc of PluginLoader.
* plugin: move plugin init function to PluginLoader.cpp
* doc: further typekit and plugins proof-reading and fixes.
* plugin: store value of RTT_PLUGIN_PATH in PluginLoader + fix test runners to set this path.
* doc: cleanup of scripting manual +remove 'set' and file renames.
* doc: rework and rename toolkit plugin manual
  New style typekits.
* doc: initial documentation for plugins.
* plugins: search for plugins when application starts.
* plugins: load a provider into a TaskContext if it is not there yet.
  Calls PluginLoader in getProvider<T> in case the provider is not there yet.
  Use task->provides()->hasService(s) to only test for presence of a service.
* cmake: also install plugins into build directory + inform the unit tests of this.
* plugins: allow to query names of loaded plugins, types, services.
* scripting: cleanup of value creation parser for TaskBrowser.
* cmake: install plugins in lib/plugins directories.
* doc: API documentation improvements.
* plugins: cleanup log() output.
* types: renamed Typekit to TypekitRepository
  And moved TransportPlugin to the types directory.
  This makes the naming + file locations more consistent.
  Also the macro for creating a typekit has been moved into TypekitPlugin.hpp
* plugins: PluginLoader + macros.
  Turns marshalling and scripting into service plugins and adds initial
  PluginLoader, macros + tests.
* types: renamed Toolkit headers to Typekit headers.
* types: rename *Toolkit classes to *Typekit.
* types: refactored type info headers and use new property/type decomposition by default
  This change puts each TypeInfo specialisation in its own header and
  implements the default composition behaviour using type decomposition.
* properties: rewrote composition/decomposition infrastructure to make use of new type decomposition
  * Decomposition functions are no longer necessary, implement serialize()
  * Composition functions are only necessary for reading 'legacy' structures,
  for example RTT 1.x 'array'.
* types: re-enable reduced support for bools
  No reference to a bools member can be taken.
* doc: minor doxygen cleanup.
* typekit: add conversion for bool<->int in light of future bools replacement.
* types: first implementation of generic property decomposition code.
* types: further testing and fixing of structs of sequences.
  * Added boost::array type info template
  * Renamed TemplateCArrayInfo to CArrayTypeInfo
  * Unit test for vector<struct>
* types: removed bulky BuildType since new type introspection is in place.
* git: updated .gitignore files to exclude dev-dirt.
* doc: archiving generated images + new state diagram.
* types: removed dead code and updated VectorTemplateComposition with SequenceTypeInfo.
* types: renames for consistency in new TypeInfo classes
  Have now TypeInfo as template-less base class, TemplateTypeInfo as generic type info
  and SequenceTypeInfo (C++), CArrayTypeInfo (C) and StructTypeInfo (C/C++) specialisations.
* tests: renamed updateCommand to updateAction.
* corba: minor code docs.
* scripting: update the unit tests to use the new assertion semantics
  The tests's assert() statements now throw instead of returning false,
  analogous to what the scripting expects.
  Also refactored program and states tests to re-use the operations_fixture.
* scripting: Fix strange bug in PeerParser::locator
  It appeared to work previously, but the error_status<> returned length
  is now being ignored by spirit. The only work around I found was to
  progress the scanner manually. Needs a Q&A on the spirit ML.
* scripting: change program error status from 'bool' returns to 'caught' exceptions
  functions that return false are now ignored by the scripting error handling.
  A function must throw something in order to get the program/state machine into
  the error state.
* scripting: move variable assignment into expression parser
  This patch moves assignment logic from ValueChangeParser to ExpressionParser,
  reducing a lot of code. Each assignment now returns an expression, instead of
  an Action, allowing chained assignments.
* types: test and implement container type info
  Tested std::vector and std::string. In order to fix operator[], an assignable ActionAlias
  was necessary. Also converting a known type to an assignable variant is now part of TypeInfo.
* internal: add ActionAliasAssignableDataSource + fix ActionAliasDataSource
  needs careful implementation of evaluate() in order not to trigger a read/copy
  of get() if not necessary.
* internal: properly process DataSource::shared_ptr in DataSourceGenerator.
* internal: fix potential bug returning 'old value' in DataSourceAdaptors.
* types: implement and test TemplateContainerInfo.
  Uses newFusedFunctorDataSource to bind capacity/size/[] functions.
* types: separate TemplateConstructor in separate header file.
* Fix DataSourceGenerator when passing data source pointers.
* types: move GetSignature into separate file.
  Needs to be investigated if it can't be replaced by boost::function_types<Funct>::type
* types: initial code for accessing parts of std/STL containers.
* types: refine type info with getPart variant and implement CArrayInfo
  TemplateCArrayInfo returns parts of C-style arrays.
  Also extended DataSourceBase API to read index from data source.
* types: Implement TemplateStructInfo for decomposing user structs
  Uses the boost::serialization API + type_discovery
* types: Improved archive for data decomposition
  * Decomposition of c-style arrays using carray/boost::serialization::array and ArrayPartDataSource
  * unit tests for archive and data sources
  To be done: extend template type info to use this and unify with the 'old' index/contianer data sources.
* types: add assertions in defunct development code.
* types: compile fixes for new types refactored code.
* types: remove double def of TypeBuilder destructor.
* types: initial part reading/writing data sources.
* types: split types implementation into separate .cpp files.
* types: introduce getPart() data source introspection.
* services: fix typo getProperty(name) of ServiceProvider.
* doc: improve addPort documentation.
* ports: also stop component when removing an event port + doc it.
* doc: improve addProperty documentation.
* Allow input/output port to be default constructible.
  The name can be set when using addPort(name, port).
* ports: New addPort(name, port) function to be in line with other addX functions.
  This function was added such that a port no longer needs a name during construction.
* property: Add the new addProperty(name,value) function to PropertyBag too.
* taskcontext: fix typo in getProperty(name)
* Merge branch 'rtt2.0' of git://github.com/doudou/orocos-rtt into rtt-2.0-mainline
* macosx: Fix nasty semaphore timed wait bugs
  * Correctly translate kernel return codes to error codes expected by calling layer
  * Deal with _signed\_ nsec value correctly.
  * Add extra assert checks
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* gnulinux: Add assert check for invalid time val
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* corba: Erase partially built ControlTaskServer if required naming service missing
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* tlsf: Port to Mac OS X
  Pick up sbrk() and MAP_ANON correctly
  Turn off LOCKS as no Orocos support for rt_mutex_t in C files (needs Boost locks)
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* macosx: Make all data and functions static to prevent multiple copies when linking
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* cmake: Add boost-thread dependent library to pkgconfig file for Mac OS X
  Signed-off-by: Stephen Roderick <kiwi.net@mac.com>
* small boost 1.42 compatibility fix
* mqueue: Link transport with the boost serialization library.
* win32: Added condition variables
* win32: missing symbols
* rtt: missing include
* os: boost 1.43 compatibility
* Merge branch 'rtt-2.0-mainline-psoetens' into rtt-2.0-mainline
* gnulinux: use stack size if set by user.
* Fix bug #763: duplicated code in oro_limits.h
  The content of oro_limits.h is duplicated. This patch fixes it.
  The problem is the same in both 1.x.x and 2.x.x branches.
* Update debian package building to 2.0
* corba: added updateAny in AnyConversion to resolve omniorb vs TAO Any copying differences.
  This is more efficient than first allocating an Any on the heap,
  then copying it and then destroying it again.
  Tested with TAO & OMNIORB.
* Merge branch 'for-peter' of git://github.com/doudou/orocos-rtt into rtt-2.0-mainline
* types: fix copy-on-write race against std::string implementation
  I have to write this down in case this bites us again in the future:
  * Orocos scripting assumes that a string of size 'N' will not decrease
  its capacity when it is assigned a string of size '< N'.
  * Same for a std::vector
  The testTypes unit test checks if this assumption is true. Of course,
  it isn't in some cases. This patch works around one more such case.
  We already worked around asigning two strings by overloading the
  ValueDataSource::set() in case of string. Now we also had to overload
  it's constructor in case of string.
  The problem is that string uses a copy-on-write implementation that
  discards previous capacity in favour of the newly written string,
  and allocates a capacity equal to that string's size. Hence above
  assumption fails. The only way to counter that is to 'pre-allocate'
  a new string for *each* string in scripting such that it is certainly
  not a copy-on-write (cow) target. Since we use 'clone()' a lot in scripting,
  each clone() was a possible 'shallow string clone' which could trigger
  a future 'cow'. The only work around is to make sure that clone() makes
  a deep copy instead of a shallow one of the string. This is done by
  passing the string::c_str() in the constructor of ValueDataSource, which
  forces a 'deep' copy. The same trick had been applied in ::set() earlier.
  In order to have the above work, the buildVariable() implementation for
  std::string had to be adapted to fill the 'preallocated' string with
  spaces instead of '\0' because the c_str() of '\0' is the empty string,
  which is not what we want to use in the constructor of ValueDataSource :/
* tests: relax timing constraints in corba ipc test.
  Got too much false negative tests because of delays in responses from server.
* scripting: don't rely on usleep timing in ScriptingTestSuite/TestGetProvider.
* corba: fix channel's servant activation and refcounting
  There was a big memory leak as servant were not properly refcounted.
  Using the canonical servant activation sequence fixed it.
* extras: define ReadOnlyPointer<T>::try_write_access
* extras: make the control flow clearer in ReadOnlyPointer<T>::write_access()
* extras: do not call reset() in write_access()
  write_access() checks if we are sole owner, and based on that returns either a
  copy or directly the buffer. It called reset() to release the pointer
  automatically once we got read/write access to the data.
  This behaviour is actually quite counter-intuitive, as repeated calls to
  read_write() will return first a data pointer and then NULL. So, change it so
  that the call to reset(), if desired, is done explicitely
* extras: in ReadOnlyPointer::reset(), don't reallocate the internal structure if we are the only owners
* corba: to-any conversion can raise as well, properly catch the exception
* corba: OmniORB compatibility fixes
* corba: add ACE_THROW definition on OmniORB
* cmake: do not fail if libxenomai is not found but libnative is.
* xenomai: fix grave bug in rtos_task_is_self.
* tests: remove small ticks conversion test because of ever-failing due to RTOS limitations.
* xenomai: also detect and link with libxenomai if found.
* cmake: require boost 1.36 or later.
* cmake: work around cmake bug for older cmake versions (like in Lenny).
* cmake: fixes in Boost_THREAD detection plus fix .pc file for all targets.
* xenomai: Fix rt_mutex_acquire_until detection macros.
  From: Peter Soetens <peter@thesourceworks.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@31673 ce417995-dfc9-0310-95a0-acdaff106893
* cmake: Add boost-thread dependent library to pkgconfig file for Mac OS X
  From: Stephen Roderick <kiwi.net@mac.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@31672 ce417995-dfc9-0310-95a0-acdaff106893
* cmake: remove program_options dependency. Only find Boost thread for macosx.
  From: Peter Soetens <peter@thesourceworks.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@31671 ce417995-dfc9-0310-95a0-acdaff106893
* tlsf: fix typo in cmake logic for win32: default to tlsf off.
  From: Peter Soetens <peter@thesourceworks.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@31670 ce417995-dfc9-0310-95a0-acdaff106893
* Fix multi-threaded parser use bug.
  The parsers used some static/global variables that caused multi-threaded
  parsing to fail. This was solved for all cases, and a shared CommonParser
  object (on the stack) tracks eol skipping for each parser.
* Bump to 1.99.2 for Beta-2 release.
* services: note in ServiceProvider impl that alternative queries exist.
* scripting: typo/compile error fixes in FunctionFactory.
* methods: do not point to null in AStore
  Pointing a (const) reference to null leads to code that segfaults.
* services: correct error message in MethodC.
* methods: let bad_assignment inherit from std::exception and check for it in Method construction.
  When using RemoteMethod, an unknown type may lead to a bad_assignment exception.
  This needs to be catches such that it does not leak to user code.
* corba: fix remaining CORBA ipc test suites.
* doc: update corba transport documentation.
* dataflow: fix bug in addEventPort, not waking up the component.
  Also document this interface a bit better.
* corba: implement method send and collect.
  All corba-test ut's work now.
* tests: document test suites.
* services: fix MethodC and SendHandleC implementations
  Sending was never tested, this fixes sending.
* ws: whitespace fix.
* services: Add invalid send handle factory exception.
* corba: implement MethodC calling of remote operation.
* services: Extend interface of OperationRepositoryPart to allow argument type inspection.
* internal: fix implementation of create_sequence::GetTypeInfo.
* collect: also expose collect signature as mpl list.
* services: misc documentation updates and includes cleanups.
* methods: Add check function and better error reporting to MethodC.
* types: fix namespace of Types() implementation.
* corba: fix unit test for method/operations.
  Use taskcontext from fixture and check any before using it.
* corba: Fix proxying of nested services.
* corba: remove any conversion for PropertyBag.
* internal: warn when MethodC gets wrong initialization.
* mqueue: unit test API fixes in mqueue+corba tests.
* corba: test and fix taskcontext servants and proxies.
* services: fixed last issues in AttributeRepository.
* corba: no longer transport PropertyBag.
* corba: fix initialisation bugs in data source proxies.
* services: no longer create PropertyBag on the heap in attribute repos.
* services: fix bug in provides() not setting parent pointer.
* types: add non-verbose hasProtocol() function to type info.
* properties: add helper functions to list, store, remove properties using path specs.
* properties: check for null pointer in operator<<.
* properties: print error when assigning newly constructed property to wrong source.
* tests: header fixes in mqueue tests.
* tests: add void/void method to operations fixture.
* corba: update tests to new CORBA API.
* transports: cleanup of DataSource/transport API
  Removed server()/proxy() code. This is no longer needed.
* services: renames of getRequestNames and getServiceNames
  Renamed to getRequesterNames() and getProviderNames().
* tests: add tests for listProperties and re-furbish tests.
* properties: add listProperties function
  Recursively retrieves all names in a bag.
  Uses format bag.subbag.item.
* corba: initial servant and proxy implementations.
* corba: initial servant implementations.
* corba: removing scripting access code.
* corba: cleanup idl files.
* mqueue: move binary data archiver into mqueue transport instead of marshalling.
* mqueue: remove assertions that may happen in real world code.
* ports: do not remove event handlers when disconnecting a port.
* tests: cleanup mqueue tests.
* test: cleanup function unit tests and method tests.
* methods: check for null assignments and add logger messages.
* functions: fix command execution bug in ActionAliasDataSource.
* remoting: test and implement remote method calling from C++.
* remoting: change blocking bool parameter in operation repository to a data source.
* methods: Fix disposing of LocalMethod.
* remoting: initial SendHandleC implementation (broken).
* operations: also provide the collection arity in operation repository.
* remoting: further invoke/collect/return refactoring.
* Missing return classes for remoting.
* Initial code for method remoting.
* datasource: fix broken factory functions.
* doc: put CTaskContext in CompIDL group.
* doc: parse IDL files again in Doxygen.
* corba: fix bug #759: ControlTaskServer::CleanupServer causing segfault.
  Remove self from servers map when construction fails.
  From: Peter Soetens <peter@thesourceworks.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@31472 ce417995-dfc9-0310-95a0-acdaff106893
* internal: create factory functions for DataSources on stack.
* corba: proposed new IDL interface for TaskContext.
* corba: missing symbols
* properties: update PropertyBag to respect addProperty/getProperty coding style.
  This patch renames PropertyBag::getProperty<T>(name) to PropertyBag::getProperty(name)
  and adds PropertyBag::getPropertyType<T>(name) for the old behavior.
  Also PropertyBag::addProperty(PropertyBase*) became addProperty(PropertyBase&) while
  ownProperty(PropertyBase*) stays the same.
* news: update news of this beta release.
* doc: major cleanup of obsoleted documents.
* doc: fix xml errors in program parser manual.
* doc: update CoreLib API documentation.
* doc: remove NameServer from CoreLib doc group.
* marsh: add missing cstring include.
* rtt: document Handle classes better.
* cleanup: remove obsoleted files and cleanup includes of various files.
* cmake: fix include paths for changed targets directory.
* xenomai: build fixes in fosi layer.
* marsh: fix cmakedefine for PLUGINS_ENABLE_MARSHALLING
* fwd: remove DataSourceCommand class from scripting.
* taskcontext: fix preprocessor check.
* Set version number to 1.99.1 (2.0.0-beta1).
* tests: minor tweaks to mqueue. port signalling still broken.
* operation: Support signalling a callback function.
* tests: add test for signals with reference arguments.
* tests: cleanups of tests, further using ADD_UNIT_TEST macro.
* cmake: rename ENABLE_SCRIPTING, ENABLE_MARSHALLING to PLUGINS_ENABLE_X.
* signal: Define shared_ptr for Signal class.
* signal: Allow signals to have reference arguments.
* internal: move scripting::DataSourceCommand to internal.
* fwd: updated all forwarding headers.
* Fix copyrights in data flow code.
* Fix copyrights and remove duplicate file.
* Merge branch 'rtt-2.0-services' into rtt-2.0-mainline-merge
  Conflicts:
  doc/xml/orocos-program-parser.xml
  src/Method.hpp
  All files have moved from src/ to rtt/ in order to facilitate documentation
  and non-install builds.
  The transports have not yet been ported to the new services infrastructure.
* Merge branch 'rtt-2.0-mainline' of git://github.com/jsreng/orocos-rtt into rtt-2.0-mainline-merge
* doc: typo and images updates in taskcontext manual.
* doc: tune pdf xsl parameters.
* tests: minor fixes in taskstates test.
* taskcontext: only stop activity if present.
* tlsf: turn on/off tlsf for specific targets. Map to malloc/free if not present.
* doc: improve for/while loops in scripting docs.
* cmake: fix wrong file names in marsh.
* taskcontext: fixed some 'minor' memory leaks.
* methods: introduce real-time allocator.
* doc: improve calling functions and return values doc.
* tests: drop ; from return statements in scripts.
* scripting: Fix parse 'eos' bug when return statement returns nothing.
* scripting: allow exported functions to be called.
  This is a partial implementation that only supports calling.
  No sending/collecting done yet.
* engine: improve waiting for messages and functions.
* types: Add ActionAliasDataSource for executing an action and returning a DataSource.
* operations: return shared pointers in produce functions.
* gnulinux: initialise main thread's task struct.
* extras: Let SimulationActivity/Thread return MainThread::Instance() in thread().
* engine: result of enqueue is a boolean.
* scripting: implement initial return value semantics.
* scripting: renamed Program/StateMachineTask->*Service.
* doc: update documentation with access->service renaming.
* services: renamed *Access classes to *Service.
* marsh: renamed Marshaller to MarshallerInterface
  In order to avoid conflict/confusion with Marshalling class.
* doc: update docs to API changes in addX and getX.
* ports: pass port objects by reference instead of by pointer in addPort().
* attributes: pass attribute objects by reference instead of by pointer in addAttribute().
* interface: No longer require the template argument for getOperation, getAttribute etc.
* tests: bunch of unit test updates and additions related to methods and services.
* methods: use global engine if no caller set.
* tests: remove dead test code.
* scripting: update for new location of ProgramInterface.
* base: moved ProgramInterface into scripting.
* engine: test and check for errors and exceptions in update and error hooks.
* tests: remove infinite loop.
* methods: check for implementation before setting the caller.
* tests: only compile remoting code if ORO_REMOTING is on.
* tests: fix exception in method test.
* remote: Initial remote method code, work in progress.
* tests: split off buffers tests and test AtomicQueue better.
* internal: fixed AtomicQueue in case of read/write race.
* doc: Fix incorrect documentation
  The online Orocos Component Manual incorrectly documents use of "size()"
  and "capacity()" operators for arrays and strings. The parantheses aren't actually needed ...
  Stephen
* ports: go back to add-port-by-pointer addPort() signature.
* corba: Added CleanupServer to give deployment a function to cleanup corba servers.
* method: Add functions to set the method from member functions or function objects
* doc: added code snippet for setting attributes/properties.
* doc: Fixed bug about property's rvalue()/value().
  From: Peter Soetens <peter@thesourceworks.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@31410 ce417995-dfc9-0310-95a0-acdaff106893
* dataflow: re-implemented event ports allowing user callbacks too.
* engine: do not force taskstate to stopped when stopping engine.
* signal: add disconnect method for all handlers.
* tests: remove obsolete generictask test 3.
* tests: re-added ports and attributes tests.
* tests: re-added event_test and taskstates_test (aka generictask_test3).
* dataflow: Modify adding ports, port documentation and pointer vs reference in API.
* properties: Add doc() function to Property class.
* taskcontext: uniform add/get of interface primitives and provide quick-access functions in TaskContext class.
* tests: use addAttribute instead of addAlias.
* doc: update main documentation page.
* doc: Run doxygen on source+build directory again.
* attributes: Cleanup and add getProperty utility function.
* doc: improve documentation of services API.
* taskcontext: remove reconnect() and re-order and document class API.
* doc: slight naming update in execution engine figure.
* doc: Added fop.xconf for controlling fonts and embedding in pdfs.
* doc: added pictures of data flow connections and services.
* services: refactored services into shared objects
  The TaskContext now owns services by a shared reference.Accessing
  the services is now done with the provides() or requires() member
  functions. Convenience functions to quickly add attributes/operations/properties
  etc are to be provided.
* methods: extend MethodBinder to support 10 arguments.
* tests: add unit tests for property loading
  Also adds the unit.hpp header containing most unit test setup code.
* doc: updated faulty namespaces in docs.
* taskcore: do not allow transition <Stopped to Running.
* tests: Quote TEST_LIBRARIES to be sure the the macro gets the argument.
* tests: fix testSend, use collectIfDone().
* tests: Fix AddUnitTest macro.
* scripting: fix collectIfDone in scripts.
* doc: major images and manuals rework for RTT 2.0
* internal: Fix race in AtomicQueue between reader and writer.
* internal: add assert in MemoryPool.
* tests: refactor buffers tests into smaller units.
* os: Fix bug in Thread::setPeriod which would not wake up periodic thread.
* taskcontext: also connect top level requires with provides.
* events: fix compiler warning from dead code.
* scripting: Trying to get keyword parsing right
  The problem is that something like: setPeriod(3) will be picked up by the
  ValueChangeParser as the begining of a set x = y statement. We want keywords
  to be bounded by word boundaries, but it ain't happening yet.
  For some reason, the eps_p(p) parser always fails.
* types: Split RealTimeToolkit in multiple smaller files.
* marsh: fix namespace of PropertyLoader to marsh.
* internal: Fix for older compilers (gcc 4.1): use pointer-to-foo to disambiguate overloaded function.
* services: Fix for older compilers (gcc 4.1): don't use reference as second in std::map.
* taskcontext: Added setPeriod method.
* doc: slight reordering of sections in taskcontxt manual.
* Update scripting reference to RTT 2.0 syntax.
* doc: updated method/operation sections and services.
* doc: minor doxygen update.
* doc: RTT 2.0 manual review
* activities: Add setPeriod to interface and implement for all subclasses.
* attributes: fix compile error in operator=
* internal: Remove debugging statements.
* types: Added SendStatus to type system.
* scripting: Added parseValueStatement and caller concept in parsers.
* scripting: Allow to specify the caller of the parsers in addition to the local context.
  This is required for taskbrowser-like behaviour where we parse instructions
  in the context of a component, but execute them in the context of the TaskBrowser.
* taskcontext: fix bugs in activity setting and isActive due to previous patch.
* taskcontext: document in-code implications of overriding updateHook.
* taskcore: reduce general state machine to resemble good ol' times.
  Being active is now a property of the EE and should always be the case.
  Warning state and erorr/warning counts are gone again.
  doTrigger/doUpdate are renamed to trigger/update.
  very old update/shutdown/startup methods are gone too.
* lockfree: adapt other lock-free algorithms to drop the number of threads restriction.
* lockfree: Implement any-thread lock-free queue with a max of 65000 elements.
* taskcontext: implement lock-free event delivery between dataOnPort and updateHook.
* methods: fix crash in Method if assigned from empty implementation.
* tests: Add Marshalling unit test.
* marshalling: Fix Marshalling requester, init the method names.
* interface: Add getService call to ServiceProvider, detect asking for 'this'.
* taskcontext: rename getService<T> to getProvider<T> to avoid confusion.
* scripting: add missing methods to ScriptingAccess, cleanup Scripting requester.
* scripting: minor style cleanups.
* marshalling: Added Marshalling service and requester
  Moved MarshallingAccess, PropertyLoader into marsh and created
  Marshalling ServiceRequester.
* scripting: silence compile warnings in StateMachine code.
* scripting: Added Scripting ServiceRequester for method access interface to ScriptingAccess service.
* tests: update AddUnitTest macro.
* types: Fix compiler warning.
* taskcontext: added getService for C++-style access to loaded services.
* methods: upgraded Method for use with ServiceRequester.
  Base class added and implementation cleaned up.
* internal: minor include cleanups.
* methods: fix serious if( i = 1 ) bug in CreateSequence.
* mqueue: Add missing include.
* scripting: Minor esthetical cleanups.
* services: Added getLocalOperation and a rename.
  Renamed getOperations() to getOperationNames().
* fwd: updated interface forwards.
* attributes: added support for aliasing C++ object variables.
  Also renamed getAttributes to getAttributeNames.
* methods: added operator= to SendHandle.
* services: Added ServiceRequester implementation.
* methods: fix compiler warnings.
* services: implement getServiceNames()
* services: move ExecutionThread enum into RTT namespace.
* scripting: Also deactivate statemachine when error in transition program.
* scripting: remove parser debug statement.
* scripting: fix transitions on port events.
  When multiple transition statements were listening for the same port,
  only one would get the 'NewData' condition, the others would never see
  NewData and never fire.
* scripting: Added tracing framework for State Machines + fixes.
  An important fix is the checking of global transitions and checking
  of transitions after a transition to self.
* interface: Moved FactoryExceptions into interface namespace.
* tests: state and program script tests cleanups.
  Also add a ProgramToProgram script test.
* scripting: load transitions scripts too.
* services: move/rename OperationFactory to interface::OperationRepository.
  The OperationFactoryParts were renamed to OperationRepositoryPart.
  It still throws internal:: exceptions, which need to be moved into interface too.
* Disable taskcontext tests for now.
* scripting: Implemented send/collect in scripts
  Unit test added in program_test. Hacky in ExpressionParser,
  but does what is expected. When a SendHandle is seen in a script,
  a dummy is installed in the AttributeRepository, which gets filled
  in by the real SendHandle, once the send() invocation has been seen.
  sh.collect(args) had to influence parsing of named values, such that
  when a keyword was seen (ie '.collect') the text was passed to the
  DataCallParser, which handles the collect then.
* services: Another sweep at implementing send/collect completer.
  New unit test to test data source functors that invoke send/collect.
  Send updated() to referenced data sources after invoke.
  Caller must be given in functor factory functions.
  Added ownership management for Operations and their methds.
* base: make all methods of ExecutableInterface public and unfriend EE.
* attributes: add setName to AttributeBase.
* interface: Implement missing removeAttribute function.
* attributes: make Alias class template-less.
* scripting: inform SM programs that they are loaded when SM is loaded.
* scripting: fix bug in activate/deactivate code of SM if initial state contains an error.
* datasources: fix copy/cache in reference-to-assignable.
  Previous versions of this AssignableDataSourceAdaptor worked on a
  cached value, in order to let remote (CORBA) assignable
  data sources to know when From& set(void) was used, and updated()
  forwarded that use when the ref was updated.
  This caching is however not needed, updated() only needs to be forwarded.
* tests: remove unused header files, all is in cpp now.
* methods: Add global ExecutionEngine for executing 'unwanted' method calls.
* scripting: adapt scripting unit tests and start fixing bugs
  Also adds the getParent/getOwner relation for ServiceProvider in order
  to allow ParsedStateMachines to check if their service must be removed
  and also add a service temporarily to the TC during parsing.
  Scripting is working for < 50% and memleaking a lot. Unit tests compile
  and run without segfaults.
* methods: Remove weak_ptr from DS method implementations.
  Since shared_ptr is natively supported by the boost::bind/invoke functions and
  forcing in weak_ptr was causing bloat for a feature we actually don't want
  (only for 1.x BC scripting), this patch standardises in keeping the pointer
  to the script in a shared_ptr. Some other means will have to be invented to
  force a cleanup.
* tests: fixup method tests using MethodC.call.
* tests: fixup types tests activity handling.
* tests: minor additions to operation_test.
* cmake: don't strip debug info in this development branch.
* types: cleanup constructor and conversion functions.
* methods: Use shared_ptr in create_sequence to avoid crashes.
* services: avoid recursive destruction of child service.
* methods: fix MethodC implementation, rename execute() to call().
* methods: Use own RStore in fused functor to store result of method call.
* types: Reimplement constructor templates using fused functors.
* tests: fix loading of programs in types_test.
* methods: temporary commit for fixing scripting.
* cmake: remove stale CMakeCache.txt file.
* methods: add constructors to Operation for improved 1.x BC.
* scripting: implement description() and getArgumentList() functions.
* methods: re-implement the description() and getArgumentList() functions in method factories.
* scripting: change RTT 1.x event parsing to RTT 2.0 input port reading.
* scripting: Fixed ConditionCompare implementation.
* scripting: Port most of scripting code to new ServiceProvider API
  Some code still broken:
  * event handling in state machines
  * some asserts remain to be solved
* services: allow mass-copy of attributes using set/getValues(std::vect)
* services: move recursive service providing into ServiceProvider.
  The scripting state machines need to be able to define recursive
  services (parent-child relation) in order to expose the child
  state machines. Therefore, this code is moved from TaskContext
  to ServiceProvider. It's not very pretty, it's a flaw in how
  the scripting SM were designed that we give into.
* methods: re-ordered arguments of addOperationDS to match order of addOperation.
* scripting: Adapt to new ServiceProvider & Operation interface.
* methods: implement datasource-with-object-pointer semantics
  Required for scripting, where the pointer to the receiving program/state machine
  script is stored in a datasource itself. Since these are referenced with shared_ptr,
  the DataSource holds a weak_ptr. The implementation (BindStorage) locks this
  pointer when it's present.
* methods: Removal of old OperationInterface, replaced by ServiceProvider
  This is a first patch that factors in ServiceProvider into the TaskContext.
  It allows to register operations, retrieve them and call() them using methods.
  Scripting is not yet supported, although registration of normal operations is.
  Also call-back/signals() handling and 3rd party EE are not yet implemented.
* scripting: only build if ENABLE_SCRIPTING is on.
* methods: Initial Operation and ServiceProvider implementations.
* methods: Implemented asynchronous collect functions.
  An asynchronous Method invocation requires the ExecutionEngine
  of the owner/executor and of the caller, for receiving the callback.
  This patch implements call/send/collect/collectIfDone/ret for
  arity 0->4 + return value.
  This is only the basic C++ mechanism, we further need the Operation
  class, new registration code and support in scripting and corba.
  Also there is not yet support for a '3rd party' thread/EE that
  executes the method in case neither component nor client wishes
  to do so. Most of this stuff all belongs in the new Operation class.
* os: Added rtos_task_is_self() to ThreadInterface::isSelf()
* os: Added rtos_task_is_self() to most targets.
  This function was added to make the choice of which waiting policy to
  use in the ExecutionEngine when waiting for messages.
  If the EE's thread itself waits for messages, it may process them,
  another thread may not.
* methods: initial wait for messages implementation.
* os: Added Condition class.
* os: Added condition variable support for gnulinux, lxrt, xenomai.
* methods: Refactored ExecutionEngine
  All scripting code has been moved into scripting
  All Processors are gone
  ScriptingAccess is the sole facade to get to the scripting objects.
* methods: renamed ExecutableInterface to DisposableInterface.
  Also renamed the execute() function to executeAndDispose().
* methods: overall cleanups.
* methods: Implement synchronous methods in new framework
  This patch makes synchronous method calls work again at the C++ level using the
  new boost::fusion based framework for storing arguments and return values.
* methods: created collection signature api with dummy implementations.
* methods: renamed CollectSignature to CollectType
  We'll need a CollectSignature class analogous to InvokerSignature.
* methods: add initial collect class hierarchy
  This splits some existing files into multiple smaller files and
  sets up a parallel hierarchy for collection of asynchronous invocation
  results.Breaks compilation.
* rtt-2.0: let LocalMessage clone MessageStorage instances for MP
  A new interface ExecutableInterface which executes and destroys
  objects serves for passing messages to the MP.
  The rtclone() is not yet RT, nor is
  the 'delete this'. It's a proof of concept for now.
* Add Message and MessageProcessor implementations.
* Minor cleanups/additions in LocalMessage and MessageStorage.
* rtt2.0: Started creating the RTT::Message class.
  It's a mix of command and method. This is staging/WIP material.
* services: First trial at code for collecting results from asynchr. invocation.
* tests: disable tests for commands and events.
* events: Ripped out asynchronous event handling and EventService
  This patch removes any occurence of asynchronous RTT::Event handling code.
  Some locations could not be fixed without a MessageProcessor, so these have the
  code removed and an assert(false) put in. Broken are:
  * newDataOnPortEvent
  * event processing in StateMachine
  * state machine transition event parsing
  The new primitive to use in place is RTT::internal::Signal for in-thread
  function dispatching.
  Some Event code is still left in because it will be re-used for integrating Signal
  with the Method/Operation interface. These classes will be gradually removed/renamed
  or refactored.
* boost: Removed old function_types and ported them to Boost 1.35 API.
* commands: Rip the command implementation out of RTT.
* tests: Minor fixes in operations unit test.
* cmake: Add project root as include path.
* Applied patch from bug #733: Rolled up patch to get RTT to compile and install
* Moved tlsf to rtt/os directory.
* Document BindStorage and MethodBinder.
* tlsf: add C++ allocator using rt_malloc and rt_free
  This just calls the tlsf malloc and free functions.
* tlsf: integrate with rtt build system
* static inline some functions to avoid double definition conflicts
  when compiled in more than one .c file
* Imported raw tlsf library into rtt/os/tlsf.
  Upstream version: TLSF-2.4.4.tbz2
* Initial operation unit test.
* cmake: Fix paths after src->rtt rename.
* build: renamed main src dir to rtt.
* win32: avoid warning on "specified function can potentially not return a value".
* cmake: Add oro_msvc to the global include list
* cmake: use debug libraries in debug configuration
* corba: Missing symbols
* win32: includes windows stuffs as soon as possible (Winsock include madness) to avoid ACE conflicts
* corba: Compilation fixes
* dev: iterator can be invalid after erase()
* cmake: Syntax
* win32: Use high resolution timer for usleep()
* win32: Improve rtos_nanosleep() accuracy
* win32: Use CriticalSection based mutexes
* win32: restore high precision timer
* xenomai: switch to mutex acquire/release from Xenomai 2.3.0 on.
* win32: Use generic intrinsics (x86, IPF, x64)
* Merge from psoetens repo
* internal: Add typename to ListLocked::delete_if to make gcc happy.
* cmake: not MSVC80
* win32: Export symbols
* win32: Added Lockfree functions for MSVC using intrinsics.
* cmake: Syntax
* win32: Avoid name clash between namespace "interface" and the #define interface of MS COM (objbase.h)
* internal: Use "struct" to avoid redefinition
* win32: MSVC specific preprocessor directive
* win32: Export missing symbols
* internal: Added delete_if() method
* win32: Simple POSIX wrapper
* win32: Compilation fix
* xenomai: Hide "specific" XENOMAI include
* cmake: Hide lockfree structures with OROBLD_OS_NO_ASM
* misc: Missing header
* cmake: Remove ASM source files in each subdirectory
* cmake: Fix build for win32
  * Fix compilation flags
  * Disable C4996 warning (about "deprecated" CRT)
  * Enable /bigobj option (needed for heavy templated source files)
  * Enable parallel build under MSVC (significant build speedup on MP machines)
* tests: Disable specactivities-test for non-unix and Xenomai targets.
* tests: work around killall not finding corba-ipc-server.
* tests: Allowing an off-by-two of 8 means 25% tolerance.
* tests: cleanup activity tests and replace usleep by rtos_nanosleep.
* xenomai: Do not cleanup main_task since this triggers a segv in rt_task_delete.
* corba: Add omniorb-xenomai hack for shadowing threads that accept connections.
* corba: ammend previous patch, fix dataflow header too.
* corba: Fix some exception signatures in data flow interface.
* corba: forcefully cleanup corba dispatcher in unit tests.
  The cleanest solution would be to implement a ref counting mechanism
  similar/identical to the Mqueue Dispatcher.
* tests: further cleanups for when using test-runner-corba.
* tests: allow off-by-one error in Xenomai time conversions.
* tests: do not test features that Xenomai fosi does not support (hard/soft scheduler).
* extras: Make sure SimulationThread is stopped in destructor.
* tests: Create separate test-runner for corba, such that we have a chance passing arguments to unit tests.
* tests: Work around hanging Xenomai unit tests.
* xenomai: Fix compile error in fosi layer.
* xenomai: switch to new mutex acquire/release API unless Xenomai >= 2.4.50
* corba: Add missing include.
* test: added unit tests to test true inter-process corba/mqueue communication.
* transports: fix crash when querying for unknown transport.
* corba: minor typo fix.
* corba: Add CreateFromFile helper method to create proxy from file.ior.
* dataflow: add scripting 'last()' method to output ports.
* dataflow: refcount the input port data source to avoid crashes.
* tests: automatically start/kill corba-ipc-server.
* tests: also check for NoData case when reading a remote channel.
* corba: lay foundations of individual port disconnections in corba remote port proxies.
* tests: Removed compiler warnings when comparing C++ with CORBA enums.
* corba: avoid BAD_PARAM exception by returning a value in the out parameter.
* corba: throw in channelInput creation instead of returning nil.
* corba: Added unit tests that truely go inter-process.
* tests: move some checks out of the threads since boost utf is not thread-safe wrt logging.
* tests: remove newlines from message output.
* corba: also link with AnyTypeCode/Valuetype in xenomai and lxrt.
* thread: fix forced exit of thread if stop() failed.
* tests: fix build dependencies of mqueue test and libraries.
* properties: Fix bug #737: Autosave adds unnecessary element when writing arrays
  The error was in the XML demarshallers that did not reset the name when a
  new element was encountered. This caused reuse of the previous name (or
  parent) and confusion when updating the XML files.
  Both TinyXML and Xerces parsers were affected.
* Initial tests for corba with ipc.
* properties: fix bug in removeProperty in case it is owned by the bag.
* properties: fix bug #737: Autosave adds unnecessary element when writing arrays.
* tests: fix property test when reading test cpf file fails.
* types: do not print decomposition error log messages for standard types.
* internal: only update data sources if data is available.
  update and updateCommand use evaluate() to check if data is available
  assignment is only done when it returns true, otherwise, the update
  returns false.
* mqueue: Check real-timeness of mqueue transport.
* dataflow: Add unit test for multi-output-single-input case.
* dataflow: fix disconnection of endpoints such that recursion is avoided.
* list: fix initialisation of initial size.
* dataflow: fix multi-connection input ports.
* fosi: Add rtos_enable/disable_rt_warning()
  This patch adds the interface and implementation of enabling
  and disabling RTOS warnings when we're voilating the real-time
  domain. Currently, only Xenomai implements these hooks, the
  other OS abstractions leave them empty.
* cmake: Add error if xeno-config is not found and fix reading posix flags.
* tests: fix some unit tests that play with schedulers.
* cmake: fix typo in setting omniorb4 client libraries.
* dataflow: Added more disconnect code when connections fail.
* dataflow: add log message when connection init fails.
* corba: fix unexpected throw when using omniorb.
* cmake: better reporting of missing omniorb components.
* dataflow: do not disconnect whole output port when a single new connection fails.
* mqueue: make char transportable.
* corba: Add unit test for testing buffered halfs.
* cmake: fix generation of corba .pc files when libs are in non-standard places.
* dataflow: fix channel cleanup if channelReady fails.
* thread: fix endless recurse in case of calling start() in initialize.
* xenomai: Fix lookup of ldflags for posix wrappers.
* Merge branch 'rtt-2.0-mainline'
* debian: do not ignore *install files.
* Merge branch 'rtt-2.0-mainline'
* debian: fix Depends of the common-dev package.
* cmake: re-introduce fixes wrt cmake -E copy.
* Merge branch 'rtt-2.0-mainline'
  This was done to synchronize master with the 2.0 mainline, such that master
  points again to a meaningfull place. master will keep tracking the 2.0 mainline.
  Conflicts:
  .gitignore
  CMakeLists.txt
  config/FindOmniORB.cmake
  config/check_depend.cmake
  debian/changelog
  debian/liborocos-rtt-common-dev.install
  src/CMakeLists.txt
  src/os/gnulinux/fosi.c
  src/targets/CMakeLists.txt
  src/transports/corba/ApplicationServer.cpp
  src/transports/corba/CMakeLists.txt
* cmake: require minimal 2.6.0 again.
* debian: require cmake >=2.6.2
* win32: fix compile error in fosi.
* debian: add dependency to liborocos-rtt-@TARGET@@LIBVER@-dev
* Fix signatures of sleep and usleep on win32 in case mingw is used.
* debinan: Fix create-control.sh in case of multiple targets.
* Generate the transports docs also seperately.
* Require cmake 2.6.2 or higher.
* Fix unit test in response to fix for bug #734.
* fix false error in states unit test.
* Fix bug #734: Adaption of DataSource to const reference
  Signed-off-by: Peter Soetens <peter@thesourceworks.com>
* Merge branch 'rtt-2.0-mainline-from-sylvain' into rtt-2.0-mainline
* fix false error in function unit test.
* doc: Minor updates/clarifications for installation and plugins.
* engine: Fix bug #731: wrong mTaskState handling for children in RTT::ExecutionEngine::startContexts().
* corba: Add Omniorb as user link lib.
* corba: Add TAO too as user link lib.
* types: Fix missing return value.
* Merge remote branch 'peter/rtt-2.0-mainline' into rtt2.0
  Conflicts:
  src/transports/corba/DataFlowI.h
* marsh: fix header issue when using Xerces with newer gcc versions.
  Signed-off-by: Peter <peter@thesourceworks.com>
* cmake: fixes build order for mqueue transport lib with unit tests.
  Signed-off-by: Peter <peter@thesourceworks.com>
* os: add missing include to cstdio.
* cmake: don't use new FindBoost.cmake macro with cmake versions < 2.6.2
* cmake: re-add the ENABLE_TESTS option.
* Enable CTest and testing based on our ENABLE flag
* tests: add test for unloading scripts that call functions in endless loops.
* scripting: minor code cleanups & docs.
* Fix bug #721: Destroying running function seg-faults ProgramProcessor later
  CommandExecFunction did not call removeFunction, which was the gravest mistake.
  Removing functions in the PP was not protected by a lock, which would cause
  trouble from time to time.
  The lock is purely there to force synchronisation with removeFunction.
  Removal may not happen during processing of the function itself.
* scripting: Fix bug #726: state machine crashes when calling stop() in transition check.
* events: cleanup dead code from Handle.
* misc: fix operator= during self-assignment.
* cmake: build by default with RelWithDebInfo CMAKE_BUILD_TYPE
* extras: rename the badly named ReadWriterPointer.hpp into ReadOnlyPointer
* fix wrong -I in orocos-rtt-corba.pc due to transports moved in transports/
* fix typedef for CommandInterface
* corba: fix standalone inclusion of CorbaLib.h
* corba: fix wrong path in include
* Merge branch 'new_data_flow' into rtt2.0
  Conflicts:
  src/FileDescriptorActivity.hpp
  src/PortInterface.cpp
  src/Ports.hpp
  src/ReadWritePointer.hpp
  src/base/DataSourceBase.hpp
  src/corba/DataFlowI.cpp
  src/corba/RemotePorts.cpp
  src/extras/FileDescriptorActivity.cpp
  src/internal/DataSource.cpp
  src/os/gnulinux/fosi.h
  src/transports/corba/CorbaLib.cpp
  src/transports/corba/CorbaTemplateProtocol.hpp
  src/types/TypeInfo.hpp
  src/types/TypeInfoName.hpp
  src/types/TypeTransporter.hpp
* cmake: Force CMAKE_BUILD_TYPE=Release if not set by user.
* mqueue: Include MQLib.hpp in the template protocol header.
* doc: Improved documentation for data flow, mqueue and minor updates.
* doc: fix corba docs with new headers and namespaces.
* tests: Minor cleanups in taskthread unit test.
* scripting: Fix parse error (missing ')') in function foo() definitions.
* tests: provide --help option for unit tests.
* corba: Add ACE_THROW_SPEC needed for older TAO (pre-1.5) versions.
* dataflow: Fix enum order of CNoData, COldData and CNewData.
* mingw: Fix use of --enable-auto-import and add missing ld flags in tests.
* scripts: Minor tweaks to do-fwd.pl tool
* tao: fixes for pre 1.5 TAO releases.
* tests: fix segfault in dispatch-test in case the parser throws at us.
* corba: Do not create threads in ControlTaskProxy.
* cmake: Further tweaking of boost detection.
  I also needed to fix a bug or two in the FindBoost.cmake module,
  such that I included the correct one until upstream fixed this.
* mqueue: document and fix boost dependencies of mqueue transport.
* boost: Do not use recent .reset() function of boost::intrusive_ptr.
* HACK: shut up warning about "void" getting into the corba fallback handler
* fix 'init' flag on transport-based connections
  The initialization of a new connection was done in connectTo, and therefore was
  not performed in anything but the direct non-transported connections (as for
  instance CORBA).
  Move it into addConnection so that it is properly done.
* doc: document real-timeness for ListLockFree
* cmake: fix Valuetype vs ValueType with TAO.
* cmake: Fix picking up boost include dirs.
* corba: Re-add CORBA_USER_LINK_LIBS and XTRA_TAO_LIBS after fixing bug #695.
* Add additional TAO-required CORBA library to link Orocos-RTT on Mac OS X
* Make Corba an independant CMake package
* Add TAO AnyTypeCode as extra library for macosx
* [PATCH] Support option to require CORBA name service in control task proxy and server
* [PATCH] Install Orocos Types IDL file for use with KDL
* [doc] Clean up the state machine script example.
* Give default activity the name of the TC. Suggested by K. Gadeyne, this patch generalizes his idea.
* [corba] Cleanup of unnecessary rtt-config inclusions in corba code.
* [toolkit] Fix wrong Import statement in ORO_TOOLKIT_PLUGIN.
* [extras] Add default ctor and reset method to ReadOnlyPointer.
* [scripts] Output class info in class-dump.txt instead of class-fwd.txt
* [scripts] Fix bug for not processing tests directory.
* [scripts] Fix minor bug for parsing class names.
* [fwd] Re-generate forward declarations.
* Bump mainline version to 1.91.0 to indicate dataflow+interproc merge.
* check that the channel element returned by the transport is not NULL
  This may happen in weird cases, and having an exception instead of a SIGSEGV is
  always better ...
* don't use DataSourceTypeInfo<T>, it does not work across solib boundaries
* [omniorb] Use the 'use_quotes' flag when generating stubs.
* [cmake] Properly restore the FindOmniORB macro again.
* [dataflow] Fix wrong include in header.
* [corba] Fix broken omniorb4 compilation and linking.
* Relax unit tests in LXRT corner case. Also disable overrun detection test.
* [mqueue] Add reference counting to MQ Dispatcher.
* [dataflow] Remove dead function.
* Correct the priority check for macosx target
* Updated all headers and sources without license with the correct license and copyright holders.
* Updated header generation script.
* Merge branch 'rtt-2.0-interproc' into rtt-2.0-mainline
  Conflicts:
  config/check_depend.cmake
  debian/.gitignore
  tests/CMakeLists.txt
* [corba] Fix RemoteOutputPort, adds getDataSource().
  Make ConnPolicy transportable over CORBA.
* [property] Add compose(source_bag) to the PropertyBase interface.
  It's a shorter writing than going through the datasource layer and doing tricks.
* [dataflow] Expose the datasource of keepLastWrittenValue in OutputPort.
* [types] Warn if user wants to (de)compose type without composition added.
* [dataflow] Made ConnPolicy an Orocos script and XML type
  DATA,BUFFER,... were made globals as well, although they could
  move into the DeploymentComponent.
  The enumeration order of locking_policy changed as well, UNSYNC is
  now first.
* add TypeInfo::buildOutputHalf
  This allows to reduce the amount of instanciated code in transport plugins, as
  the connection-related code will be generated only once.
  This is safe as the use of transport requires that the corresponding TypeInfo
  are present.
* [doc] Initial RTT 2.0 dataflow documentation.
* [scripting] Adds a globals repository such that global constants can be defined, such as enumeration values.
  The scripting has been adapted to look up these globals for reading or writing.
  Any toolkit can add these globals. If you don't want a global to be writable, add it as Constant,
  otherwise, add it as Attribute.
  In addition, the FlowStatus script type was added, with globals NoData, OldData and NewData.
  It is also convertible to bool, but an explicit bool() cast is needed in most cases.
  Unit tests added for GlobalsRepository and FlowStatus script type.
* Fix crash/bug in scripting where constructors are called in infinite recursion.
  May have cause really weird crashes during parsing on various platforms.
* Fix bug #664: order of operations in the taskbrowser.
  Multiplication took precedence over division, while both are equal.
  Adds unit test.
* Fix: building RTT with mingw. Based on suggestions on Orocos-dev ML.
* [cmake] Fix pthread and boost thread versions detection.
  Also updated the installation manual to set the dependencies better.
  Closes: #709, #712
* [pkgconfig] fix the @RTT_USER_LINK_LIBS@ by specifying XENOMAI_LIBRARIES instead of 'native'.
* dataflow: Create one corba dispatcher per component.
  For each component writing data into a corba connection, a dispatcher is
  created. This offers the same thread-safeness guarantees as plain dataflow
  since only two threads will read a channel: the sender's thread and the dispatcher.
  Also the dispatcher can rely on the fact that only one other thread will access
  its structures, being the component writer thread.
  The ConnFactory remote connection building function needed to be adapted in
  order to allow for passing the sender port which we use to lookup the
  parent component.
  In case no parent component is present (unlikely), a default dispatcher is used.
  In that case, the user is responsible to not use more than one thread for writing
  to these orphaned ports.
* dataflow: implement unsynchronized data flow (ConnPolicy::UNSYNC).
* dataflow: ConnPolicy cleanups and documentation.
* dataflow: rethink buffer placement in connections and add corba dispatching.
  This patch makes the default corba data flow channel real-time safe
  but relies on a corba dispatcher for this. It is a non-rt worker thread that
  does the data flow transfers over CORBA.
  The ConnFactory had to change such that the transports decide where the buffering
  is done, and not the ConnFactory.
  The dispatcher code is still a bit buggy wrt multi-threading, the lock-free
  list assumes only 2 concurrent accesses. We need to find a dispatcher for each
  component that does corba data flow.
* mqueue: reorder channel elements such that OOB don't go through CORBA.
* dataflow: fix bug in stream creation, premature cleanup of channeloutput.
* dataflow: don't return shared_ptr of object that you don't refcount yourself.
* dataflow: cleanups in transports and factories.
  Renamed createChannel to createStream (ie what it does) and allow
  non-streaming protocols to decline the creation.
* Move ConnPolicy from internal to RTT namespace.
* dataflow: rename InputHalf to ChannelInput and OutputHalf to ChannelOutput.
* dataflow: Added connection management through connection ids
  * Each managed connection now must have an ID which we can later use
  to disconnect it again.
  * The corba IDL interface has been further cleaned up and tested.
  * Creating pure streams from corba IDL is now also present.
* Changes for glibc 2.10
  This fixes warnings about duplicated #definition of _XOPEN_SOURCE, which
  glibc 2.10 already #defines by default.
* corba: display error messages on corba failure
* doc: Fixed install instructions after angry user feedback.
* dataflow: Allow multi-connection inputs.
  This factors out the connection management into a separate class.
  This allows both input and output ports to use connection management.
  Also the DataFlow IDL interface had to be adapted to support this
  mode of operation and many other changes were required in the data flow
  classes.
  It seems the PortID will need to replaced by ConnectionID to allow
  streams to be managed as well.
* add a ROS-like manifest.xml file
* Only define _XOPEN_SOURCE if not set yet.
* Fix in IRQActivity when running in Xenomai.
* Fixes for mqueue transport library with Xenomai.
* mqueue: Added mqueue serialization template classes.
  This patch fixes and tests the serialization code for complex data in
  mqueues. The binary_data_archive is basically working, but not in
  great shape (discussed on boost-users ml).
  Tested for sending/receiving a double and a std::vector<double>.
* dataflow: fix return values when creating streams fails.
* dataflow: inform port when connection output endpoint is destroyed.
* dataflow: fix calling of data_sample() in setDataSample().
* transports: Remove the *blob functions from DataSource and relocate them
  in the proper transport object.
  There was no need to clutter the DataSource interface with the 'blob'
  functions for converting data to transportable objects and back.
  The create/updateBlob functions have been renamed to createAny/updateFromAny
  for corba (which really works with anys), while keeping their name in
  mqueue transports (which really works with blobs).
* Add script for generating the rtt-fwd headers.
* git: ignore some more files.
* tests: Misc fixes required for accounting the changed read semantics in data flow.
* dataflow: correctly implement evaluate/get/value for InputPortDataSource.
* serialization: move+rename boost serialization archive into src/marsh/.
* dataflow: detect construction of illegal message queue.
* dataflow: Fix implementation of clear() in buffers.
* dataflow: Change return value of read() from bool to 'FlowStatus'.
  The three return states are now NoData, NewData, OldData.
  The channel itself caches the OldData case, returning the last read if no new data arrived.
  We could make the caching behaviour a (default) connection policy though.
* serialization: Added initial real-time object serializer using boost::serialization.
* This patch adds initialisation of the connection using a data sample and
  checking of connection validity for out-of-band connections.
  The idea is that when a chain of channel elements is created, the
  output port is asked to send a data 'example' through the connection
  and the input port is asked to check if its channel elements are ready.
  Because of these two 'messages' going in both directions, we can initialise
  and validate both ends of the data connection for real-time communication.
  The data sample allows the channel elements to allocate enough memory
  to hold its (dynamic) size, while the input check allows out-of-band
  transports to setup their data receiving (knowing that output is up
  and sent a sample).
  * Storing the last output value in an output port is now turned on by default.
  * Initializing a data connection with the last output value of the port
  is now turned on by default.
* tests: Fix boost version test.
* scripting: Fix wrong order of header include.
* do not build locked container tests for boost < 1.36
* debian: fix build deps for boost in control file.
* cmake: fix .pc file for xenomai.
* cmake: fix generation of .pc files for include dirs and user link libraries with CORBA.
* Deal with boost >= v1.38 spirit namespace renaming ... tested with v1.40.
* Log error messages when Timer is wrongly used.
* Let Timer derive publicly from RunnableInterface.
* doc: Updated installation manual with recent cmake and win32 changes.
* cmake: fixes in orocos-rtt.default.cmake example.
* Add .gitignore for debian.
* Remove most legacy implementations of rtos_printf, except for LXRT.
* tests: fix usage of BOOST_REQUIRE_CLOSE: cast to double.
* mqueue: Finish up creation logic for out-of-band transports.
  The policy.name_id is now properly passed and modified during creation and forms a unique id on the local system.
* base: Add breakUpdateHook() for allowing to stop taskcontexts which are looping in updateHook().
* extras: minor fixups in IRQ and FileDescriptor Activities.
* debian: fixups in common header install list.
* debian: add parallell build options.
* base: fix wrong init ordering in constructor.
* corba: misc header cleanup in ApplicationServer.
* Set debian version number to 1.91.0-1
* debian: Update install lists with relocated headers.
* debian: remove removed file from .install.
* os: silence compiler warning.
* doc: document ORB timeout setting.
* corba: Improve timeout spec in InitORB to allow sub-second precision.
* Fix rules 'major' detection for 1.10.0 version number and add
  -Wl,-z,defs to gnulinux link flags.
* cmake: add RTT_USER_LINK_LIBS to .pc file.
  RTT fosi headers include some inline 3rd party library calls, which the user must then link with too.
  Notably libpthread and librt are such cases in gnulinux.
* fix resizing of transport array in TypeInfo::addProtocol
  The old code was resizing unconditionally, which is obviously breaking transport
  registration if the highest-numbered transport is registered first. Fix that by
  checking if resizing is required at all.
* ee: fix wrong implementation of hasWork() (used by SequentialActivity).
* cmake: various cleanups.
  * enable OS_NO_ASM by default on Windows/MSVS
  * remove deprecated ENABLE_TESTS
  * remove duplicate definition of OROCOS_TARGET
* cmake: document orocos-rtt.default.cmake much better and pick sane defaults.
* cmake: Fix ACE_ROOT/TAO_ROOT env detection in the .cmake scripts.
* corba cmake: fix cmake dependency bugs for the corba library.
* attributes: fix wrong use of std::transform in AttributeRepository.
* cmake: Fix wrong endif statement in FindOmniORB.cmake.
* corba: Added minor doc&assert in RemoteChannelElement.
* Revert some of the _remove_ref() additions, since they caused double frees.
* corba: minor cosmetic logger additions.
* corba: fix unit test for corba connections to actually use through-corba.
* corba: only create local connections if policy.transport == 0.
* corba: Major cleanup in servant memory management in order to avoid
  server-side leaks.
  * Use the _remove_ref() and RefCountedServantBase technique to allow
  the POA to manage the servent object's lifetime.
  * Also, ControlTaskServer::server() no longer returns a duplicated
  object reference. You need to _duplicate it if you want to store it.
* ports: Add createStream for setting up connection-less data flow
  transports and added a unit test for mqueues.
* tests: minor cleanups in port connection tests
* tests: minor cleanups.
* base: fix input port include of Event.hpp
* base: Add missing virtual destructor to RunnableInterface.
* os: Add os::Thread synchronisation during construction.
  Such that the thread is effectively created when the Thread constructor
  returns.
* mqueue: add missing std include headers.
* dataflow: Fix memleak when input port is destroyed before output port.
* Add code and tests for out-of-band data flow.
  This patch adds several changes in one go:
  * Added the mqueue transport library which marshals data into posix
  message queues. It can marshal pod types automatically, for complexer
  types (std::vector,string,...) a specialisation is required (not yet added).
  * Allows to setup out-of-band data flow without using CORBA. This can
  be done by setting the transport parameter to a different value than
  0 and the ORO_CORBA_PROTOCOL_ID in the ConnPolicy object.
  It currently works only in-process though.
  * Allows to setup out-of-band data flow with using CORBA. Same
  procedure as above, works across processes.
  Details:
  * signal() dropped its 'const' qualifier to allow channel elements to
  change internal state when being signalled.
  * ConnFactory and OutputPort have been slightly refactored to contain
  all connection creation code in the factory and also to accomodate
  for oob data-flow setup.
  * ConnPolicy objects are used to pass the connection name to and from
  both endpoints (member name_id), such that oob transports can reuse
  this id to re-find each other (name_id is for example hostname:port).
  This changed some methods from ConnPolicy const&  to ConnPolicy&
  and also changed the IDL.
  * The MQueue Dispatcher is now process-wide instead of proxy-wide.
  This makes it a bottleneck in the long term. Also, it wakes up
  every 50ms to see if new mqueues need to be monitored. A better
  mechanism should be in place.
  * I'm not happy with the overall design of the connection-setup
  code, but it works for now. A strategy pattern is needed to clean
  it up, instead of the endless if() statements checking in which
  situation we are (and hoping that we covered all cases).
  The connection creation code path is *very* tricky.
* Make connection/disconnection of channel elements more robust by clearing the right pointers at the right time.
* Fix uninitialised pointer in PortInterface.
* Add documentation to some classes.
* Added getParent() method to allow back-tracking from data flow to TaskContext object.
* Minor tweaking of taskthread_test. Discovered race in Linux's pthread implementation.
* Fix bug in Activity::loop not calling step() once by default.
* Additions for gcc-4.4
* Allow to specify a transport in IDL CConnPolicy
  + add transport to conversion functions.
* Document some more corba classes.
* Put RemoteChannelElement in its own .hpp file.
* Allow the connection policy to specify a transport.
* Add bi-directional data flow connection creation for remote CORBA ports.
* Minor error message fix in connectPorts.
* Do not create connection to already connected input port.
* Cleanup the ORO_main and __os functions to be a bit more informative when exceptions happen.
* Set message-length to zero when using gcc, such that eclipse has a better shot at parsing the output.
* Explicitly include header such that cmake can build correct dependencies.
* Fix wrong ENDIF in FindOmniORB.
* Fix wrongly backported fix for checking scheduler in tasks_test.
* Fixes to tasks_test to reduce logger verbosity and skip tests that will fail if scheduler could not be set.
* Detect overruns in gnulinux.
* Remove double call to ENABLE_TESTING().
* Disable max overruns by default (set to -1).
* Detect thread overruns on macosx.
* Remove obsolete code from gnulinux fosi.c
* Only add bit variable if thread scope is enabled.
* Add CDash support.
  This makes that the unit tests are built with make all when tests are enabled
  and also sets the dependencies corrected.
  patch suggested by S. Roderick.
* Rename all corba IDL interfaces, struct, enums and typedefs to have a 'C' in front of them in order to distinguish them from their not generated counterparts.
* Cleanup and document InputPort/OutputPort API.
  The channels list is dropped from OutputPortInterface, since it contained
  the same information as the connections list.
* Fix typo in TaskContext::connectTo
* Force enable boost.thread for macosx.
* Add Port.hpp convenience header.
* Remove stale rt_exception header.
* Remove stale rtctype implementation.
  Fixes bug #696: Reimplementation of ctype functions causes
  program crash if other OSS package uses them in static constuctors.
* Fix unused variable warning.
* Merge commit 'github/new_data_flow' into new_data_flow
* return value in non-void method
* ROPointer: provide default constructor and a reset() method
* Make const functions non-const when they modify data members
* Fix TAO include problem when using omniORB
* Fix bug #684: Trunk fails to build on mac as pthread_mutex_timedlock() not available. As discussed on the ML, allow to fallback on Boost.Thread using the ORO_OS_USE_BOOST_THREAD flag.
* Turn off verbose makefiles
* Remove obsolete mutex implementation for macosx target
* Fix bad ENDIF in FindOmniORB
* Fix/extend connectTo() such that it can work with the given default connection policies.
* Fix comment in order to not confuse the fwd generation script :-).
* Minor tweaks to check-headers.sh script.
* Install missing Marshaller.hpp file.
* Minor tweaks in forward declaration header generation.
* Update forward declarations of os::Timer class.
* fix: Let tiny xml headers use marsh namespace instead of detail.
* Move Timer.hpp from extras to os.
* Remove manually added code from generated rtt-os-fwd.hpp file.
* Fix inclusion of boost/function_types in ConnectionC.hpp
* Fix inclusion of boost/function_types in EventCallBack.hpp
* Fix uncorrected inclusion of rtt-config.h for a bunch of headers (2).
* Fix uncorrected inclusion of rtt-config.h for a bunch of headers.
* Also install .inl file in rtt/base.
* Fixup documentation of namespaces and Doxyfile for new structure.
* Fix inclusion of Boost Function Types headers for installed systems.
* Fix wrongly added namespaces in fosi_internal.cpp implementations.
* Set version number to 1.91.0 to reflect major API re-organisation.
* Update fwd.hpp headers with new auto-generated versions.
* Rename signal_base to SignalBase and connection_base to ConnectionBase.
  The names of the header files are changed as well.
* Major RTT namespace overhaul.
  This patch introduces a bunch of new namespaces, one for each subdirectory of the RTT.
  They are: os, base, interface, internal, types, plugin, scripting, marsh, corba, dev and extras.
  A special, catch-all namespace 'detail' exists as well which the user can use to instead of
  these namespaces, given that the user includes 'rtt-fwd.hpp' or (preferably) 'rtt-detail-fwd.hpp'.
  The namespaces make more explicit the purpose of a given class or function. For examples,
  users should never be confronted with classes from 'internal', and if they want to define new
  types, only need the 'types' namespace. Often however, the RTT::base namespace will be required
  as well.
  Caveats: RTT::Corba was renamed to RTT::corba. RTT::OS was renamed to RTT::os.
* Allow to optionally list files in check-headers.
* Removed dead fosi_internal.hpp header from os subdir.
* Moved ConditionInterface from scripting to base.
* Replace CommandInterface with ActionInterface.
* Add auto-generated forwarding headers for rtt and all sub-namespaces.
* Moved property introspection classes into base.
* Removed obsolete CommandFunctor.hpp file.
* Moved private PortID definitions to implementation files and fixed wrong includes in corba/.
* Remove dead code from Handle header.
* Split Types.hpp in multiple header files.
* Remove SingleThread, PeriodicThread and OS::RunnableInterface.
* Split PropertyBagVisitor to a separate .hpp file.
* Rename free function types() to Types() in order to avoid conflict with types namespace.
* Fix typo in namespace decls in rtt-fwd.hpp
* Cleanup and fix ChannelElement classes after splitting the headers.
* Moved CommandRepository from internal to interface.
* Cleanup namespace declarations in RTT.hpp
* Added sub-namespaces and catch-all detail to rtt-fwd.hpp
* Adapt includes to new location of Input/Output port classes.
* Refactored the header layout of the Ports and Channels headers.
  About each class is now in a separate header, which has been put
  in the correct subdirectory.
* Remove wrong reference to RunnableInterface in ThreadInterface.
* Added CMakeLists.txt file for new base/ directory.
* Split DataObjectInterfaces.hpp into separate files.
  Also added the RTT::DataObject class to use the underlying Locked/LockFree implementation depending on OROBLD_OS_NOASM.
* Manually apply patch Fix-TAO_Messaging-detection-and-only-use-it-if-it-is-found.
* Fix includes for the migration of headers to base/.
* Fix headers to use the new base/ subdir.
* [move] Moved core RTT base classes in a base/ subdirectory.
* Minor cleanups in tasks tests to reduce output of false error messages.
* Lowered exception recovery log message from Fatal to Critical.
* Fixed various issues with rtt-config, .pc and target installation
* Cleaned up the src/marsh directory. Removed remaining reporting specific files.
* Fix unit tests for re-ordered rtt headers.
* Further refinement of includes-rewriting
* Remove header dependency on CompletionProcessor for EventService.hpp
* Add extra constructor to Activity to improve backwards compatibility with
  NonPeriodicActivity.
* Fixes in CMakeLists files after moves for compilation and installing headers.
* Rewrote all necessary include statements for headers and implementation files.
* Re-added boost function_types until WP3 resolves them.
* Moved AssignCommand into internal.
* Fix error propagation in exported script functions: preserve function state when it is unloaded and propagate the error status in the command's valid() function.
* Fix function script unit tests. The error state was reset before it was tested.
* Fix function execution when the TaskContext is non-periodic.
* Fix bug #689 -  New RTT buffer locked functionality fails to compile on Ubuntu Jaunty.
* extras: intrusive_ptr helpers must be defined in the same namespace as the object
  Otherwise, name-specific lookup won't work and the compiler will complain that
  the functions don't exist.
* Work in progress for the 2.0 refactoring branch.
* Put Ports.hpp back into the rtt/ main directory/namespace.
* Merge branch 'rtt-2.0-mainline' into rtt-2.0-refactoring-merge-df
  No real conflicts except some files that were removed or files that
  showed up in the old/wrong location.
  Conflicts:
* Merge branch 'rtt-2.0-mainline-merge-df' into rtt-2.0-mainline
  Conflicts:
  .gitignore
  src/ConnectionInterface.hpp
  src/PortInterface.hpp
  src/corba/CMakeLists.txt
  src/corba/CorbaConnection.hpp
  src/corba/CorbaDataObjectProxy.hpp
  src/corba/CorbaPort.hpp
  src/corba/DataFlowI.cpp
  tests/CMakeLists.txt
  tests/corba_test.hpp
* Remove NonPeriodicActivity. Use Activity instead.
* Merge branch 'rtt-2.0-mainline' into rtt-2.0-refactoring-merge-df
  Conflicts:
  src/NonPeriodicActivity.hpp
  src/marsh/EmptyMarshaller.hpp
  src/marsh/Orocos1Demarshaller.hpp
  src/marsh/SimpleDemarshaller.hpp
* Fix bug in debian control file: depend on various flavours of boost.
* Fix typo of previous patch in CMakeLists.txt
* Fix cmake build dir bugs reported by R. Smits.
* Apply parallel build patch from bug 681.
* From bug 681: Add missing install files for debian.
* Fix typo in building of static corba library.
* Fix bug #684: Trunk fails to build on mac as pthread_mutex_timedlock() not available.
  As discussed on the ML, allow to fallback on Boost.Thread using the ORO_OS_USE_BOOST_THREAD flag.
* Fix TAO_Messaging detection and only use it if it is found.
* Remove unused data flow functions from transport layer.
* Allow to control reserved buffers in LockFree storage.
  The default of MAX_THREADS has been reduced to 2, because in
  the new data flow design, only two threads can access a buffer.
  The name argument of data objects has been removed.
  They can't have a name of their own, the port is where the name is stored.
* ports: cleanup port/channel API
  This commit finally cleans up the port/channel API:
  * it makes sure only the "input"/"output" types are used, be
  it about ports or channels. Any reference to reader/writer
  or source/sink should have been removed
  The difference between ports, channels and connections is now clearly made.
  * ports are the input/output interfaces to tasks
  * channels are the transport of data between ports
  * connections are a particular way to build channels, that
  is also the default RTT-supported way to create channels
  between ports.
  Additionally, it makes public API elements that makes easier to
  integrate different types of channels than the connection ones.
* including a smart pointer for explicit data sharing semantics
  The goal of this pointer is to allow efficient passing of big data structures
  through ports. Right now, that would require at least 3 copies of the data. With
  this pointer, one can push a sample on a port, and have the readers create a
  copy only when
  - they need it
  - there is at least one other component that could use the given sample
  That would be very useful for instance in the context of image processing.
* core: implement TaskContext::isPortUpdated
  This is a more readable way to check if a certain port has triggered the call to
  updateHook(). The port has to be added with addEventPort, obviously.
* FileDescriptorActivity: log failure errors
  The activity now logs to Error when a failure happens
* FileDescriptorActivity: improve documentation
* FileDescriptorActivity: add detailed class description
  The class description now has examples of how to use it in
  TaskContext::updateHook() and errorHook().
* add FileDescriptorActivity::hasTimeout()
  There is an implementation of a timeout for a while now, but there was no way
  for the TaskContext to know if there was a timeout or not. Add hasTimeout() so
  that the TaskContext can test it.
* validate fd in FileDescriptorActivity::watch
  It was previously possible to give a negative FD to watch(), which was later
  making the whole process crash. It is now validated, and watch() emits an ERROR
  log message when it happens and will cleanly fail in start().
* Remove unused proxy object.
* transports: introduce the reuseBlob call
  This allows to reuse a marshalling buffer, instead of having to allocate a new
  one for each marshalling.
  The interface is specified so that, if reusing is not possible (as for CORBA
  Any's AFAIK), it is actually possible to delete the old blob and create a new
  one.
* Set version number or rtt-2.0-mainline to 1.90.0.
* Merge branch 'rtt-2.0-mainline'
* Merge branch 'corba-connection-timeout' into rtt-2.0-mainline
  Conflicts:
  config/FindTAO.cmake
* Merge branch 'rtt-2.0-mainline'
  This merges the build system cleanup, win32 port, and all WP1 tasks,
  except the namespace/directory structure re-ordering.
  Conflicts:
  .gitignore
  config/FindOmniORB.cmake
  debian/changelog
  src/EdgeCondition.hpp
  src/VertexNode.hpp
  src/corba/CMakeLists.txt
* Merge branch 'rtt-2.0-mainline-msvs' into rtt-2.0-mainline
* Ignore more build directories and eclipse project directories.
* Fix link and compilation errors on gnu due to win32 port.
* Disable unit test on win32 platform (MSVC 8). It causes a segmentation fault with a corrupted stack during parsing of the for() construct. Needs a look with MSVC 9 or 10 to see if the source can be traced better.
* Relax capacity requirements for strings in order to work on win32 platforms.
* Initialise end-iterator in parser/scanner invocation in case it would be read or used by Spirit.
* Convert line endings to unix.
* Silence compiler warning by converting int return value to boolean expression when calling cp->process()
* Add DumpObject to RTT_API.
* Fix memleak in property test.
* Cleanups and memleak fixes in activity/threading tests.
* Fix bug #592: Memory leak in RTT::ConnectionC class
  Embed the EventCallBack object in a boost::shared_ptr when doing the bind
  such that the object is deleted when the connection is deleted.
* Disable exception, overrun and thread config tests for win32.
  Until the fosi_internal layer of win32 is cleaned up, these tests won't pass.
* Implement copy constructors in AtomicInt such that the NO_ASM version correctly initialises the underlying mutex during a copy.
* Remove debug statement in win32 rtos_task_delete.
* Give compiler chance to emit Analog/DigitalInput/Output functions in io.cpp file.
* Further RTT_API cleanups and decorations.
* Set separate flags for mingw32 and msvc in win32 target.
* Also decorate TAO generated classes with RTT_CORBA_API.
* Remove Nameserver registration from events because this causes crashes on msvc.
* Fix set_target_properties
  the properties must be key/value pairs, so quote the value.
* Fix for tao_idl: use RTT_API export decoration in generqted code.
* Added missing cstdio headers.
* Also check for/link with AnyTypeCode on win32 platforms.
* Rename RTT_API decoration to RTT_CORBA_API for corba lib of RTT.
* Add RTT_API decoration to rint.
* Fix ordering of TAO headers on win32: make sure to include tao/ace headers before our fosi.h gets included.
* Add missing include for rtt-config.h
* Make loadCorbaLib() an RTT_API function.
* Add RTT_API decoration to ExpressionProxy.
* Add/fix various missing RTT_API declarations.
* Fix error in unit test init function prototype.
* Do not use the dynamic unit test boost libraries (yet)
* Fix typo in corba target installation cmake rule.
* Adapt FindACE/TAO to also find 'd'ebug versions on win32.
* DLL export decorations for most classes and functions.
* MSVS-2005 specific fixes which turn valid C++ constructs into code it can actually compile.
* define __inline_\_ for non-gnu compilers.
* Run doxygen on the CMAKE_INSTALL_PREFIX/include directory instead of on the source directory. This fixes the inconsistent file paths in the generated documentation.
* Use new INSTALL targets for cmake.
* Fix rules and create-control scripts. Debian packaging works now again.
* Add missing files in common-dev debian package install listing.
* Various fixes in check_depend and unit tests for win32 builds.
* Removed unused left-overs of pre-new_data_flow data object proxies.
* Merge branch 'merge-df' into rtt-2.0-mainline-merge-df
  Conflicts:
  config/FindOmniORB.cmake
  debian/changelog
  src/BufferPort.hpp
  src/ConnectionFactory.hpp
  src/ConnectionInterface.cpp
  src/ConnectionInterface.hpp
  src/DataPort.hpp
  src/EdgeCondition.hpp
  src/PortInterface.hpp
  src/TypeInfoName.hpp
  src/Types.hpp
  src/VertexNode.hpp
  src/corba/CMakeLists.txt
  src/corba/ControlTaskProxy.cpp
  src/corba/CorbaBufferProxy.hpp
  src/corba/CorbaConnection.cpp
  src/corba/CorbaConnection.hpp
  src/corba/CorbaLib.cpp
  tests/CMakeLists.txt
  tests/corba_test.cpp
  tests/corba_test.hpp
  tests/generictask_test_3.cpp
  tests/generictask_test_3.hpp
* Fixed merge conflict: remove testPorts and testEventPorts from unit test list.
* Fix compiler warning in gnulinux/fosi.c
* Add return statement in OutputPortInterface::removeConnection.
* Fix minor compilation issues on TAO.
* Further improved FindXerces.cmake file
  - No longer depend on the LibFindMacros
* Fix idl code generation for Omniorb, since MSVS port required extra, TAO specific includes.
  Probably the #include <tao/orb.idl> includes are wrong and the tao_idl is wrongly configured on Windows. So this might disappear again when that problem is fixed as it should.
* Fix bug 675:  Docs not build on Mac
  Use cmake -E copy instead of cp -a
* Merge branch 'new_data_flow' of git://github.com/doudou/orocos-rtt into merge-df
  Conflicts:
  src/BufferPort.hpp
  src/DataPort.hpp
  src/TaskContext.cpp
  tests/corba_test.cpp
  tests/generictask_test_3.cpp
  tests/generictask_test_3.hpp
* Refined moving around files for the interface/internal scenario (2).
* Added more ignore files to git.
* Updated debian changelog.
* Added example bisect-run script for orocos-rtt.
* Added rtos_mutex_lock_until for win32 API.
* Simplified mutex locking in win32: they are recursive by default.
* Fix avalanche of compile errors due to header re-ordering.
* Debian control & rules files generation cleanups.
* Cleanup of debian package generation. Make the targets configurable.
* Updated NEWS and debian/changelog file.
* Remove rtt-1.4 debian install files
* Moved around some documentation
  Documented RTT::Activity in favor of deprecated NonPeriodicActivity
  Moved PeriodicActivity to the -dev section of corelib.
* Updated the check-headers script.
* Fixed wrongly ordered includes in DataFlow classes.
* Cleaned up orocos-rtt.default.cmake file.
* Various portable patches to compile the code on MSVC2005
  The only fuzzy part about this patch is the typeof replacement
  MSVC2005 doesn't support it and some hand-coded constructs needed to
  be put in place. But it works on gnu as well.
  This patch was slightly adapted and trimmed from the original
  patch of Simon.
* Windows win32 API port of Orocos-RTT
  This patch uses the native win32 API for running the RTT.
  Not all unit tests pass yet. Mingw compiles this code best,
  Visual Studio is still chocking om some files in the scripting
  directory.
  * it is based solely on mingw32, no msys or cygwin.
  * it use native windows threads. No need for pthreads.
  * only ports RTT, and currently without support for Corba
  * it uses the fixes that Peter made regarding 'weak' symbol handling.
  * 4 out of 8 tests work. (ported CPPUnit to BOOST tests since CPPUnit
  * requires the obnoxious automake )
  * Priorities are supported on thread level, though creating new
  * processes could help get better "realtime" support.
  * CMake is used to generate the project: cmake -G"MinGW Makefiles" .
  Patch by Jimmy Jorgensen.
  See https://www.fmtc.be/bugzilla/orocos/show_bug.cgi?id=605
* Implement a more relyable type lookup system in Type system
  This patch was required for the Windows port or any platform
  where library symbols do not behave like the .so symbol resolution
  behaves.
* Replace uint by unsigned int in ValueParser
  Patch by Jimmy Jorgensen
* Support default cmake settings in orocos-rtt.cmake file
  Patch by Jimmy Jorgensen
* Fix missing header in test and cleanup overrun test.
* Minor implicit assumption fixes in unit tests.
* Fixed up the spurious Failed to create... void CORBA errors.
  void is now an 'officially registred' type for both local and CORBA
  typed communication.
* Fixed #ifdefs for TaskContext default activity selection.
* Pass stack size in Xenomai fosi layer.
* Add flags to control default activity in TaskContext.
  Add the cmake/macro flags ORO_ACT_DEFAULT_ACTIVITY (default to ON)
  and ORO_ACT_DEFAULT_SEQUENTIAL (default to OFF).
  If both are turned off, no activity is installed in the TaskContext.
* Fix/Change TaskContext::getActivity
  Return the activity of the execution engine if it is different from the default activity in the TaskContext.
  Return a plain pointer instead of a shared_ptr in getActivity.
* Improved version of FindXerces.cmake
* Various cleanups in tasks_test.
* Reduce test time of testThreadLog.
* Cleanup event_test and run stress tests only on gnulinux.
* Cleanup buffers_test and run stress tests only on gnulinux.
* Various small fixes and cleanups in time progress tests.
* Cleanup test-runner.
  Calling __os_exit() at the right time (or the right times) is still an issue.
* Fix minor scheduler/priority issues in fosi_internal layer of Xenomai.
* Fix wrongly computed timeout in Xenomai rtos_mutex_lock_until.
* LXRT fosi fixes: wait until thread is created. Also check for null pointers, because RTAI doesn't.
* Fix runaway thread (when periodic mode is stopped) in Thread object.
* Extend and reformat fosi_internal_interface documentation.
* Use MutexTimedLock in SingleThread stop() code.
* Add oro_main unit test.
* Fix: use _rec\_ versions of lock/unlock fosi API in MutexRecursive
* Fixed FOSI layer for LXRT: add rtos_mutex_lock_until declarations
* Remove rtos_task_get_period from FOSI API.
  The *Thread classes keep track of period themselves and most
  RTOS's don't provide it anyway.
* Remove error messages from rtos_task_set_scheduler
  Because it will be _tried\_ by the Thread class.
* Fix thread's period checking code for non-gnulinux platforms
  Also try to set the scheduler immediately in setScheduler.
* Added include dirs to INCLUDE_DIRECTORIES
* Added initial RTT::OS::Thread and RTT::Activity classes.
  This required some changes in the fosi_internal layer, the rtos_task_create
  got an extra argument to specify stack size. The classes are only unit tested
  on gnulinux and are as such still experimental.
* Added MutexTimedLock class and Mutex::timedlock function.
* Added rtos_mutex_lock_until and rtos_mutex_rec_lock_until to fosi
  Adapted gnulinux, lxrt and macosx.
* Wide range of fixes to let the RTT compile with OS_NO_ASM.
  For Queue, List, Buffer the choice is made between a lock-free
  or lock-based implementation at compile time.
  No mechanism is yet in place to switch at run-time, so it's an
  all-or-nothing patch, mainly meant to raise portability, not
  flexibility.
* Fix various small language errors that might trigger compiler warnings
  or errors when certain compiler flags are used.
* Guard GNU specific extensions with __GNUC\_\_
  They are extern template specialisations that should probably
  go into the toolkit infrastructure anyway.
* Fix #if statement in signal_base.
* Add header guards to Queue.hpp
* Add locked list alternative.
  This implementation replaces the ListLockFree when OS_NO_ASM is selected.
  It uses a plain mutex for thread-safety, a std::stack for storing
  reserved items and the boost::intrusive::list for the implementation
  of the list algorithm.
* Change implementation of BufferLocked to use deque instead of vector.
  The vector might re-allocate when erase() is being used.
* Add the OS_NOASM build option.
  This to indicate no assembly code should be
  used, such as atomic integer operations or compare and swap.
  Lock-based alternatives will be used when this flag is turned on.
* Removed empty and unused cmake files.
* Fix sporadic crashes in function_test: was using SingleThread
  in threaded mode while calling run(1000).
* Add compile time error when neither CORBA_IS_TAO nor CORBA_IS_OMNIORB is defined in rtt-corba-config.h.
* Use BUILD_TESTING or ENABLE_TESTS for deciding on unit test build.
* Mark TAO_15 TAO_ORBSVCS as advanced.
* Fix omission of CORBA_IS_TAO|OMNIORB which broke CORBA build.
* Further non-functional cleanups of the cmake code
  * All dependencies are checked in check_depend and global_setup is removed.
  * Use CMake 2.6 CMakeDependentOption
  * Remove some dead files (os.cmake, image_install.cmake)
* This patch fixes TAO and OmniORB build variable setting and detection.
  Should now work across platforms, the orocos-rtt-corba.pc file is also
  fixed. The FindACE macro was added from a third party,
  FindTAO adapted to better written FindTAO script of third party.
  Thanks to Adolfo Rodríguez Tsouroukdissian and Greg Poole for the code.
* This patch finishes most of the cmake rework. The only issue left
  is the orocos-rtt-corba.pc file when TAO/OMNIORB is not installed
  in a default location. The solution is to rewrite or find a new
  FindTAO and FindOmniorb script.
  You *must* delete your old CMakeCache.txt when testing this out,
  or you'll get rubbish.
* Fix bug in TemplateTypeInfo: do not delete overriden type info object.
  From: Peter Soetens <peter@thesourceworks.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30188 ce417995-dfc9-0310-95a0-acdaff106893
* Added BOOST_NO_HASH when including adjacency_list to avoid compiler warnings
  From: Peter Soetens <peter@thesourceworks.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30187 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes bug #640:providing RTT with type vector<ANYTYPE>
  Applied patch from T. De Laet and R. Smits to add scripting support
  for std::vector<T> types.
  From: Peter Soetens <peter@tripple-foo.(none)>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30186 ce417995-dfc9-0310-95a0-acdaff106893
* First take at cmake cleanup and refactoring
  * Removed old/dead/suspicious cmake code
  * Put all dependency checking in FindX.cmake macros
  This breaks CORBA and .pc file generation
* Removed some junk and gnu-specific sections from the top level cmake file.
  * The 'RTT' build type has been removed, since its not portably defined.
  * Also the cpack stuff had to go, since we don't support it anyway.
* Apply patch from Adolfo Rodriguez to fix Boost/Xerces detection and add LibFindMacros
* Applied patch for bug 657: OCL taskbrowser will not link when using OmniORB
  Fixes FindOmniORB and the contents of the .pc file for CORBA.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30178 ce417995-dfc9-0310-95a0-acdaff106893
* ports: cleanup port/channel API
  This commit finally cleans up the port/channel API:
  * it makes sure only the "input"/"output" types are used, be
  it about ports or channels. Any reference to reader/writer
  or source/sink should have been removed
  The difference between ports, channels and connections is now clearly made.
  * ports are the input/output interfaces to tasks
  * channels are the transport of data between ports
  * connections are a particular way to build channels, that
  is also the default RTT-supported way to create channels
  between ports.
  Additionally, it makes public API elements that makes easier to
  integrate different types of channels than the connection ones.
* including a smart pointer for explicit data sharing semantics
  The goal of this pointer is to allow efficient passing of big data structures
  through ports. Right now, that would require at least 3 copies of the data. With
  this pointer, one can push a sample on a port, and have the readers create a
  copy only when
  - they need it
  - there is at least one other component that could use the given sample
  That would be very useful for instance in the context of image processing.
* Remove indexing of idl headers with Doxygen, because this conflicts with the RTT/C++ headers and classes.
  For example, DataFlowInterface is wrongly referenced.
* Moved boost unit tests in place of cppunit tests.
* Removed old cppunit tests directory.
* Merge branch 'boost-tests' into rtt-2.0-mainline
* Expose copy on dot-operation bug in parser unit test.
* Document copy-mechanism in AssignableDataSourceAdaptor
  This was added during the CORBA work, but the consequences may have been overlooked.
* Fix size hint not being reset during parsing.
* Fix command sending unit tests: fix crash and false negative
* Fixed BC warnings from stdc++ headers by not including hash_set.
  By defining BOOST_NO_HASH before including the boost graph headers.
* Apply patch from bug #653: GnuLinux port mixes incompatible clock_monotonic and clock_realtime
  Use CLOCK_REALTIME instead of CLOCK_MONOTONIC to be compatible with other posix functions requireing a time argument.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30171 ce417995-dfc9-0310-95a0-acdaff106893
* display what() for exceptions caught in SingleThread
  Until now, SingleThread was displaying a generic message when an
  uncaught exception was detected. This commit makes it display what() in
  case the exception is a subclass of std::exception
* corba: create local connection in createConnection
  createConnection will now detect than the two involved imports are from
  the local process, and will then not set up a CORBA-using connection but
  a direct connection, thus saving a lot of processing power.
* define status() that was missing in RemoteCommand
* FileDescriptorActivity: fix potential bug when clearing the command pipe
* FileDescriptorActivity: properly initialize m_timeout on all constructors
* FileDescriptorActivity: update to support multiple FDs
  This commit updates the FileDescriptorActivity so that it supports
  watching multiple file descriptors. In the process, I got rid of the
  Provider pattern. Having to dynamic_cast the activity from the task
  context is not such a big deal, and that cleans up the code
  tremendously.
* fix compile-time warning for IRQActivity compiled on non-Xenomai target
* corba: in CORBA's createConnection, don't
  This side of the fence is to be used by a CORBA-aware client,
  which should therefore be able to interpret and act on CORBA
  exceptions.
  We should therefore not filter out corba exceptions, as they
  are useful to our CORBA client. Note that it is different from
  8ae41a09f23ca8e385d5e41c7ff6ccaf77dc214c, where the CORBA
  exceptions where leaking to non-CORBA user code.
* don't let CORBA exceptions leak into the pure C++ layer
  When creating a port connection, the CORBA exceptions should
  result in a 'false' return value. Before this commit, they
  were leaking into the user code.
* implement a status() method for commands
  The problem with the current interface is that the actual
  command state is very hard to get, as it requires a
  deep knowledge of how things are getting.
  Moreover, on the CORBA layer side, it requires multiple calls.
  The new interface provides directly the command's state.
  Moreover, it helps getting things streamlined by making
  sure each command implementation follows the command state's
  specification.
* add a diagnostics message when ChannelElement::write() returns false
  If that happens, the corresponding channel will be deleted from the
  channel list. Display a message to notify this fact.
* provide read/write methods based on DataSource objects for ports
  This adds a way to write an outputport and read an inputport
  to/from a corresponding datasource.
* more (read,write) => (input,output) renaming
  This renames the readPort and writePort of TypeInfo that
  had been left alone until now.
* have ChannelElement::signal have the identical return semantics than write
  This commit changes the interface of ChannelElement::signal()
  so that it returns a boolean. The semantics of that return value
  is the same than for write().
  Specifically, a false return value indicates that the underlying
  communication layer requests that the channel gets removed, for
  instance because of communication errors.
  In no way does it put a requirement on the reliability of the layer.
  A return value of true does *not* indicate that the signal (or
  the sample in case of write) got through.
* add createReference in TypeInfo
  This creates the typed version of ReferenceDataSource.
* corba: fix test suite after input,output=>writer,reader renaming
* corba: adding missing duplicate
  I don't know how to catch this with Orocos' test suite. It seems
  to be caught only when two different processes are talking to
  each other.
* fix comparison of CORBA references
  == will return false for two different reference object
  that point towards the same remote object. The nominal use
  is _is_equivalent.
* allow to change the logger output file through the ORO_LOGFILE envvar
* doc: Changed CORBA proxy code to setup server thread as well.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30128 ce417995-dfc9-0310-95a0-acdaff106893
* corba: rename the IDL PortType enum from reader/writer to input/output
* corba: install IDL files as well
  This is so that other packages can use these IDL interfaces
* corba: duplicate Expression server object instead of AssignableExpression.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30119 ce417995-dfc9-0310-95a0-acdaff106893
* Fix crash in corba proxy code because of wrong cast.
  This patch fixes that crash.
  The convention is that all casts to/from (void*) in the
  DataSource CORBA transport layer are CORBA::Expression objects
  and nothing else. 2 places violated this rule.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30118 ce417995-dfc9-0310-95a0-acdaff106893
* test: add missing headers
* FileDescriptorActivity: make it compliant with the ActivityInterface specification
  This commit makes FileDescriptorActivity more full-featured and
  compliant:
  - trigger() now works. That should allow a task context to be both
  port- and fd- driven at the same time
  - isRunning() now returns true only while step() is called. It
  returns false while select() is blocking, as it should be
  - added timeout support
  - added a test case
* better naming scheme for the new data flow API
  The following changes have been brought:
  - the "connection element" infrastructure is now dubbed "channel elements",
  as it explains the concept better (they are just bits of pipes, and
  can be used to build data flows that are not based on connections)
  - the only piece left with "Conn" in it is ConnPolicy as this policy
  *does* describe a connection
  - the ReadPort/WritePort classes have been renamed into OutputPort
  and InputPort as it is much clearer.
* Fix doc typo for setActivity.
  Pointed out by
  Adolfo Rodríguez Tsouroukdissian
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30114 ce417995-dfc9-0310-95a0-acdaff106893
* Added boost UTF unit test for command race condition.
* Ported patch for CppUnit testing with OMNIORB from S. Roderick to boost UTF.
* Merged cppunit changes into boost branch from rev df53fc91d uptil now.
  In principle, the boost unit tests branch is now a maturely equivalent to the cppunit branch.
* Ported CORBA test to boost::tests too.
  This still fails because of missing patches on the boost tests branch.
* Fixed most boost unit tests.
  In my boost::tests version, the BOOST_AUTO_TEST_CASE macros may not be mixed
  with plain function definitions. So I had to split out all test cases from
  helper functions and other declarations.
  Also, this branch is based on older (pre 1.6) test cases, which had to be
  brought up to level of the 1.8.x semantics.
  Not all CPPUNIT tests have been ported to this branch yet, this is needing
  more manual work.
  Only one test fails: array assignment changes capacity in typesTest.
* Fixups for boost/tests UTF
  * Use new CORBA CMake flags
  * replace log_test_suites (unknown type) with log_test_units
  * Fix event_test.hpp: do not declare the test functions in the fixture class.
  The Boost unit testing is not working properly yet. Also, they are
  getting outdated with every new testcase in the cppunit part. We'd
  better prepare a switch-at-once scenario, such that double maintenance
  is avoided.
* Port unit tests to Boost test framework
  If accepted, this will replace the cppunit tests.
  Patch by Jimmy Jorgensen
* Fix bug #642: Race condition causes commands not to be executed
  Added test case and fixed bug.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30108 ce417995-dfc9-0310-95a0-acdaff106893
* Applied patch for CppUnit testing with OMNIORB from S. Roderick.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30107 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen build updates.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30106 ce417995-dfc9-0310-95a0-acdaff106893
* Improve data port documentation, suggested on Orocos-users ML
  Suggested by Theo De Vries.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30105 ce417995-dfc9-0310-95a0-acdaff106893
* small correction in documentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30103 ce417995-dfc9-0310-95a0-acdaff106893
* Applied modified patch for ORB timeouts.
  Original patch from Simon Pelletier-Thibault <simon.pelletiert@gmail.com>
  Moved the InitOrb function to ApplicationServer.
* Improve data port documentation, suggested on Orocos-users ML
  Suggested by Theo De Vries.
* Fix bug 634 Events lost in state machine
  See the bug report for all details. We're now enabling all
  event handlers by default when the SM is activated.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30078 ce417995-dfc9-0310-95a0-acdaff106893
* Added warning about callback relying on addEvent of scripting type.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30077 ce417995-dfc9-0310-95a0-acdaff106893
* Improve API documentation of Sequential and Slave activity.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30076 ce417995-dfc9-0310-95a0-acdaff106893
* rtt: properly clean up when start() fails in IRQActivity
  This fixes a problem in IRQActivity when NonPeriodicActivity::start()
  returns false, namely that the IRQ handler was not released.
* rtt: implement IRQActivity
* FileDescriptorActivity: properly cleanup on failed start
  This patch properly closes the internal communication pipe if
  NonPeriodicActivity::start() returns false. Otherwise, there is a
  possibility of a ressource leak.
* FileDescriptorActivity: SingleThread waits for loop() to return. No need to do it in breakLoop()
* FileDescriptorActivity: implement destructor
  It seems that the rule for activities is that they should clean up
  after themselves on destruction. Given that we rely on virtual
  methods, it is for sure dangerous, but anyway ...
  Call stop() in FileDescriptorActivity destructor.
* FileDescriptorActivity: fix the wait condition on breakLoop
  select() returns -1 when the pipe is closed, not EBADF
* FileDescriptorActivity: call step() on error
  This allows the RunnableInterface to properly handle the error (for
  instance entering a TaskContext error state), instead of blindly
  stopping the activity.
* rtt: implement FileDescriptorActivity
  This activity allows to have step() called when data is available on a
  file descriptor. A mechanism is provided which allows to provide the
  file descriptor on the TaskContext object and have the activity
  automatically discover it.
* doc: don't hide scope names
  Some classes have the same name in RTT:: and RTT::Corba, so we
  cannot have doxygen hide the namespace.
* implement PortInterface::connectTo
  This is first for backward compatibility reasons, and because
  it promotes code reusal -- avoiding having a lot of places
  where the actual port types is checked.
  Still, I believe createConnection is the one that should be used
  most of the time.
* fix header inclusion
  Fix some headers whose inclusion resulted to errors in
  external projects (i.e. after installation).
* add ReadPortInterface::getDataSource()
  This is a useful interface for uniform access to data-reading
  elements, for instance in the task browser and friends.
  This commit adds the interface to read ports. To access write
  ports, one should first create the read port with antiClone(),
  connect with createConnection and create the data source. This
  is so because we cannot easily implement the memory management
  needed to implement WritePortInterface::getDataSource
* corba: implement local proxies for remote ports
  This commit implements RemoteReadPort and RemoteWritePort which
  are local CORBA proxies for remote ports. In this implementation,
  a remote port is represented by a CORBA client to a DataFlowInterface
  and a name.
  Because of this choice, some specific operations of WritePortInterface
  are not yet implemented on RemoteWritePort. This is because it is
  impossible to get a DataFlowInterface object from a given port
  (and therefore, for instance, RemoteWritePort::createConnection
  cannot be implemented). To fix this, one would have to have a CORBA
  representation of the port objects themselves.
  To allow transparent use of Remote*Port in connections,
  I had to change the way connections are
  represented in WritePort<T>. Before, a PortInterface* pointer
  was representing the read port of the connection, and used
  later to disconnect a specific port. Now, an opaque PortID
  type is now used. That PortID is generated by the virtual
  PortInterface::getPortID and equivalence is tested with
  PortInterface::isSameID. This PortID object is owned by
  WritePort<T> and deleted by it on disconnection.
  That way, it is possible to have temporary PortInterface objects
  (like on-stack RemoteReadPort) used to create permanent connections
  *and* still be able to disconnect selectively later on.
  Finally, I defined the semantic of PortInterface::clone
  and PortInterface::antiClone, so that it can be defined
  (hopefully) meaningfully on remote ports. The semantic is now
  that these methods must return local ports that have the same
  type and name than the remote ones. For instance, a RemoteWritePort
  representing a remote WritePort<double> would clone into
  WritePort<double> and antiClone into ReadPort<double>.
* fix some memory leaks
  This fixes two memory leaks in the data flow code:
  * DataObject<T> objects are initialized with a refcount of 1,
  and one must call deref() to use it with intrusive_ptr
  * new_data_on_port_event should be deleted by the port's destructor.
* make the new dataflow connection interface MT-safe
  This commits uses ListLockFree<T> for connection management in
  WritePort<T>, making the connection management interface
  (createConnection and disconnect) MT-safe.
  Moreover, some fixes have been implemented in the implementation
  of connection elements. Mainly, we must make sure that every
  method which is using a pointer to ConnElementBase should also
  be holding a local shared_ptr on that connection element.
* implement ListLockFree::delete_if
* core,corba: test and fix port signalling
  This commit tests the "new data event" functionality on ports,
  and fixes it for CORBA.
* corba,test: update the test suite for the changes in connection management
* clarify the semantics of write() and read() return values for both connections and ports
  Right now, the semantic of Connection<T>::write was really unclear.
  This commit clarifies it. One consequence of this analysis is that
  there is no well-defined meaning for WritePort<>::write. Therefore,
  this method now returns void.
  The meaning for Connection<T>::write is now "dangling connection", as
  for instance a socket connection for which the other side is closed.
  WritePort<T>::write reads that return value and automatically deletes
  these dangling connections.
* delete TypeTransporter object in TypeInfo destructor
* corba: call deactivate_servant whenever required
  This fixes some of the memory leaks issues that exist in the
  CORBA layer, but not all of them. I am unfortunately not
  verse enough in the arcanes of memory management in CORBA.
* corba: adapt the CORBA transport to the new dataflow interface
  This commit makes the CORBA transport work with the new data flow interface. The
  cornerstone of this is still the DataFlow IDL interface, which provides the
  buildReaderHalf service.
  Note about RemoteConnElement<T>: this class is both a ConnElement and a
  CORBA refcounted servant. We therefore make both sides use the same refcount,
  but taking care that the refcounting starts at 1 as CORBA dictates it.
  Note about ControlTaskProxy: the changes brought by the new data flow interface
  have removed the CorbaPort class -- which should come back at some point. For
  now, simply comment out that part in ControlTaskProxy::synchronize().
* base the default PortInterface::isLocal() on serverProtocol()
  In practice, if serverProtocol() != 0, then we actually need to
  use the type system (we need to marshal/unmarshal). Therefore,
  isLocal() should return false.
* PortInterface::getConnFactory() should be virtual
* add a default argument for default_policy in ReadPortInterface constructor
  Do not force the user to give a default_policy argument. Instead,
  initialize it by default with ConnPolicy()
* fix createConnection for remote ports
  Remove the constraint that remote ports must be a subclass
  of the appropriate ConnElement<T>. Remote ports can simply
  be subclasses of (Read|Write)PortInterface. Typing is needed
  only in the local case.
* make build(Reader|Writer)Half independendent of resp. writer/reader
  Until now, buildReaderHalf and buildWriterHalf were getting both
  the reader and writer ports to set up the connection. This is a
  hassle in practice (because we need to have access to both port
  objects) and IMO unnecessary.
  This commit therefore adds the constraint that building one half
  of the connection is independent of the particular remote port.
  Additional setup can still be done at the connection establishment
  level (i.e. createConnection by default, or for instance a specific
  connection engine).
* make the default ConnElement<T> a forwarder element
  Often, specialized connection elements will have one direction
  where they do something special (say: filtering), and will simply
  forward the calls on the other direction. Actually, operations
  defined in the default ConnElementBase are already forwarding
  the operation.
  This commit makes the same for read() and write() in ConnElement<T>.
  That avoid code duplication in specialized connection elements.
* implement initialization of new connections
  This commit adds two functionalities to the data flow mechanisms
  * write ports can (optionally) store the last value that
  has been written on them. This very useful for debugging
  purposes, and can be useful in the following items
  * if the write port does store the last written sample, then
  it is possible to initialize new connections with that sample
  (i.e. write that sample on every newly created connection).
* start the redesign of the data flow implementation
  In this new implementation, data flow is represented by mainly
  two components:
  * the ports are the dataflow endpoints at the task level. They
  are represented in practice by WritePort<T> and ReadPort<T> objects.
  * the connection is the data path between two ports. There can be
  multiple connections going out of a write port, but only one
  connection entering a read port.
  Connections are established from the WritePort side. ConnElement
  are managed as shared pointers (more specifically, intrusive_ptr)
  *from the writer* (i.e. a connection element holds an intrusive_ptr
  to the next element in the chain, but a normal pointer to the
  previous element). For now, there is no mt-guarantees whatsoever.
  A connection is uniquely defined by its writer port, its read port and
  a connection policy. This later object, of class ConnPolicy, defines
  how the connection should behave. For now, we support the type of
  data holder (data or buffer), and the type of synchronization (locked
  or lock-free).
  The connections are made of connection elements (ConnElement) objects.
  A connection is built in two halves. If the connected endpoints are
  in the same process, that concept is useless. However, if the two
  are on different machines, it takes its meaning:
  * the reader half is the part that is built in the process
  where the ReadPort is located.
  * the writer half is the part that is built in the process
  where the WritePort is located.
  In practice, it allows to have different policies that dictates
  different ConnElement structure.
* Find TAO cmake broken
  This is the only way I can get this to work. You have to force the list into a string first, due to the use of RTT_CORBA_CFLAGS within a string with the COMPILE_FLAGS property in SET_TARGET_PROPERTIES of orocs-rtt-corba-dynamic-TARGET. We have to embed a string, not a list.
  Works for Cmake 2.4 under Ubuntu Hardy with ACE/TAO in standard install location. Also works for CMake 2.6 under Mac Leopard with ACE/TAO in non-standard install location. I believe the overall problem will *only* show up with non-standard install locations.
  If others can reproduce this, then IMHO this leads us towards not mixing CMake lists and strings throughout our build files.
  <code>
  From: kiwi.net@mac.com <kiwi.net@mac.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30011 ce417995-dfc9-0310-95a0-acdaff106893
* RTT cmake does not integrate xercesc when it's not installed at /usr
  For the RTT cmake to integrate a xerces library installed on a non standard path (eg /opt/xercesc), I had to apply the following patch:
  From: orocos@dpinol.com <orocos@dpinol.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30010 ce417995-dfc9-0310-95a0-acdaff106893
* Fix multiple registrations when TC is started multiple times.
  This is only for 1.8.x fixing. 1.10.0 needs a more structured
  solution, like using addEventPort for setting up the event connection.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30008 ce417995-dfc9-0310-95a0-acdaff106893
* Clarify addEventPort vs addPort in CPBM document.
  A note is added which clarifies the effect of adding the various
  port types with addEventPort.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30006 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes bug #623: DataPort and BufferPort do not cause to emit events when
  added as EventPort.
  The testEventPorts unit test has been completed and the bugs were
  fixed in the respective classes.
  The unit test uses the default SequentialActivity, which should be
  representative for all activity implementations.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30005 ce417995-dfc9-0310-95a0-acdaff106893
* Initial unit test for event ports.
  Basics work, but test fails when forming a connection when
  tasks are already running. Needs more work.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30004 ce417995-dfc9-0310-95a0-acdaff106893
* Updated Installation manual to also cover recent TAO versions and OMNIORB.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@30003 ce417995-dfc9-0310-95a0-acdaff106893
* Applied patch for missing include in corba.h
  Patch from S. Roderick on orocos-dev
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29996 ce417995-dfc9-0310-95a0-acdaff106893
* Applied Find TAO cmake broken
  Patch from S. Roderick on Orocos-dev
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29995 ce417995-dfc9-0310-95a0-acdaff106893
* Minor updates to installation manual, according to recent changes in build system.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29987 ce417995-dfc9-0310-95a0-acdaff106893
* tests: Only run event_test::testConcurrentEmit on gnulinux systems. It would hang the computer in true real-time schedulers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29984 ce417995-dfc9-0310-95a0-acdaff106893
* Fix dead links in RTT changes document.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29979 ce417995-dfc9-0310-95a0-acdaff106893
* Third time right operators() function.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29977 ce417995-dfc9-0310-95a0-acdaff106893
* Move operators() implementation to cpp file.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29975 ce417995-dfc9-0310-95a0-acdaff106893
* Minimal change to avoid double executions (in CommandProcessor::step) of a doubly queued command.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29973 ce417995-dfc9-0310-95a0-acdaff106893
* Use RTT::types() and RTT::operators() in toolkit plugin manual
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29972 ce417995-dfc9-0310-95a0-acdaff106893
* Finish up the RTT Changes document for 1.8.0
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29971 ce417995-dfc9-0310-95a0-acdaff106893
* Added RTT::operators() short notation for
  RTT::OperatorRepository::Instance().
  This is analogous to the RTT::types() function. Both are
  used for registering types.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29970 ce417995-dfc9-0310-95a0-acdaff106893
* fix: wrong declaration of the types() function
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29946 ce417995-dfc9-0310-95a0-acdaff106893
* props: Add findValue to PropertyBag and check for nill in add/remove
  functions.
  This function allows to look for a property by value instead of by
  name. For example, look for the property that has the value "Test":
  Property<string> test_p = bag.findValue<string>("Test");
  if ( !test_p.ready() )
  // not found !
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29944 ce417995-dfc9-0310-95a0-acdaff106893
* doc: write down how toolkit plugins look like and clarify why they
  are needed (unknown_t).
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29943 ce417995-dfc9-0310-95a0-acdaff106893
* doc: fix doxygen docs of property loading and saving.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29942 ce417995-dfc9-0310-95a0-acdaff106893
* Add RTT::types() function for getting TypeInfoRepository.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29941 ce417995-dfc9-0310-95a0-acdaff106893
* build: remove RTT_CXXFLAGS
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29940 ce417995-dfc9-0310-95a0-acdaff106893
* Revert "build: rename only left RTT_CXXFLAGS to correct RTT_CFLAGS"
  This reverts commit 567e344bb32e526c493667e4eadce77dec7bc6b5.
  Conflicts:
  config/global_setup.cmake
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29926 ce417995-dfc9-0310-95a0-acdaff106893
* build: Cleanup of CORBA selection mechanism in cmake
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29925 ce417995-dfc9-0310-95a0-acdaff106893
* docs: Add section about adding dot operators to toolkit.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29924 ce417995-dfc9-0310-95a0-acdaff106893
* events: fix Atomic.hpp include in signal base implementation.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29923 ce417995-dfc9-0310-95a0-acdaff106893
* build: rename only left RTT_CXXFLAGS to correct RTT_CFLAGS
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29922 ce417995-dfc9-0310-95a0-acdaff106893
* Improved CORBA compilation by not requiring -DCORBA_IS_X flags.
  rtt/corba/corba.h is now included by every corba related file
  which includes in turn rtt/corba/rtt-corba-config.h such that
  the build knows which CORBA type is used TAO/OMNIORB.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29921 ce417995-dfc9-0310-95a0-acdaff106893
* Fix minor compilation/build system errors after omniorb-port.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29920 ce417995-dfc9-0310-95a0-acdaff106893
* Remove always-recurring hasWork patch on EventProcessor.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29919 ce417995-dfc9-0310-95a0-acdaff106893
* corba: fix an ambiguity problem in corba-to-C++ convertions
  When:
  * using OmniORB
  * on an x32 machine
  it seems that there is an ambiguity problem for int-to-corba
  and uint-to-corba convertions. I guess it has to choose between
  int-to-Long and uint-to-ULong or something.
  Given that int is always 32bits on both architectures, we make the compiler
  chose  Long/ULong.
  From: Daniel Kühn <dakuehn@kuehn2-u.dfki.uni-bremen.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29918 ce417995-dfc9-0310-95a0-acdaff106893
* build: update corba-specific build variable
  first, the RTT_CORBA_CFLAGS should be used instead of RTT_CFLAGS for
  corba-specific parameters. Moreover, there is still a problem with
  OmniORB, for which the use of IDL-generated headers still require
  the specification of rtt/corba as the include directory. Therefore,
  set it in the .pc file.
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29917 ce417995-dfc9-0310-95a0-acdaff106893
* build: fix a problem with BOOST detection
  On my system, I get 'BOOST' as a boolean value, leading to strange
  "-I/usr/1" cflags ... Chaning the name to a less misleading one (i.e.
  BOOST_DIR) fixes the problem.
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29916 ce417995-dfc9-0310-95a0-acdaff106893
* corba,tests: apply corba-specific configuration to the test builds as well
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29915 ce417995-dfc9-0310-95a0-acdaff106893
* corba: actually get a ControlTaskProxy object in corba tests
  ControlTaskProxy::Create (rightly) returns a local object when a local
  servant is given to it. The problem is that, in corba tests, we actually
  want to use a corba proxy for the tests to be valid.
  This commit adds a force_remote parameter to ControlTaskProxy::Create,
  so that it creates a local proxy even in the case where the ControlTask
  pointer is actually a local task.
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29914 ce417995-dfc9-0310-95a0-acdaff106893
* corba: use "omniORB4" as ORB name
  This is completely ignored by TAO but not by omniORB
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29913 ce417995-dfc9-0310-95a0-acdaff106893
* corba: make sure that OmniORB's DynSK files are implementation are compiled
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29912 ce417995-dfc9-0310-95a0-acdaff106893
* corba: fix installation of rtt-corba-config.h
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29911 ce417995-dfc9-0310-95a0-acdaff106893
* corba: allow to use both the TAO and OmniORB CORBA implementations
  The TAO implementation is really taking too much resources for my need.
  On the other hand, people I know are very happy about OmniORB for a
  robot control application, so I made the choice of trying OmniORB.
  This patch allows to specify the desired Corba implementation (TAO or
  OmniORB) at compile-time by specifying the CORBA_IMPLEMENTATION CMake
  variable. The default choice is still TAO of course.
  A specific header, the rtt-corba-config.h is now installed to tell which
  implementation is in use. The CORBA_IS_TAO and CORBA_IS_OMNIORB
  variables are defined accordingly.
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29910 ce417995-dfc9-0310-95a0-acdaff106893
* corba: be more specific when a buffer channel cannot be created
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29909 ce417995-dfc9-0310-95a0-acdaff106893
* corba: cleanup 0-values returned through Corba
  This patch fixes a problem and introduces a "best practice". NULL is not
  a valid value for _ptr types in Corba. "Invalid pointer" must be created
  through the calls to the typed _nil() methods.
  Moreover, it is better to return "false" for booleans, as it improves
  the ability to search for bad "return 0" cases.
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29908 ce417995-dfc9-0310-95a0-acdaff106893
* corba: small fix for consistency
  In all but one method of DataFlowInterface_i, the check was
  if ( returned value is valid )
  return now;
  issue warning;
  return 0;
  This commit simply uses the same scheme in the one method where the
  check was done the other way around.
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29907 ce417995-dfc9-0310-95a0-acdaff106893
* corba: fix wrong validity test for corba pointers
  An invalid corba pointer may be non-NULL. The specification requires
  that the validity of a CORBA object be tested by CORBA::is_nil
  From: Sylvain Joyeux <sylvain.joyeux@dfki.de>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29906 ce417995-dfc9-0310-95a0-acdaff106893
* Completes the default SequentialActivity setup for TaskContext
  With this patch, any TaskContext is created with a 'sequential activity' by
  default. This means it can be started (or activated) and process commands and
  events, without having a thread. As a bonus, thread-safety is still fully
  guaranteed for these primitives and the behaviour is very similar (if not equal) to
  NonPeriodicActivity. When a command or event comes in, it is processed in the
  thread of the sender (ie sequential with the calling code). If multiple
  senders operate on the receiver, the first one processes all the requests, so
  no thread blocks in case of contention in this implementation.
  Please review and test this.
  New API:
  TaskContext a(A);
  a.start(); // works
  a.stop();
  a.setActivity( new PeriodicActivity(0, 0.01) ); // assign new activity to 'A'
  a.start(); now 'A' is periodic.
  a.stop();
  a.setActivity( 0 ); // make 'A' sequential again.
  // etc...
  This patch is backwards compatible with 'old' applications.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29905 ce417995-dfc9-0310-95a0-acdaff106893
* Return true in trigger() if activity is running.
  This patch is similar to a previous patch on NonPeriodicActivity.
  trigger() should only return false if the activity is not active
  or does not implement the trigger() mechanism.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29904 ce417995-dfc9-0310-95a0-acdaff106893
* FIXED - bug# 606: PeerParser and PropertyParser fail to compile using boost 1.37
  https://www.fmtc.be/bugzilla/orocos/show_bug.cgi?id=606
  Applied both patches from S. Roderick and P. Soetens. Confirmed to work on
  boost 1.35.0 and 1.37.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29889 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes bug# 615: event_test fails sometimes
  Change the refcount from int to AtomicInt, which clears out the
  race conditions in the shared pointer.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29888 ce417995-dfc9-0310-95a0-acdaff106893
* Fix cmake typo in RTAI detection.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29887 ce417995-dfc9-0310-95a0-acdaff106893
* Apply the Xenomai cmake logic of S. Roderick to RTAI as well.
  Needs testing, but it looks all right.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29886 ce417995-dfc9-0310-95a0-acdaff106893
* Fix rtstreams by including cstring.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29880 ce417995-dfc9-0310-95a0-acdaff106893
* Makes Plugin API explicit and renames/extends toolkit/transport plugins
  Patch contributed by S. Roderick in order to define the 'Plugin'
  API and define a ToolkitPlugin and a TransportPlugin.
  This breaks existing toolkit/transport plugins because the base
  classes have been renamed.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29879 ce417995-dfc9-0310-95a0-acdaff106893
* Add improved debugging and error reporting of transports and type toolkits.
  Patch submitted by S. Roderick.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29878 ce417995-dfc9-0310-95a0-acdaff106893
* Do not bail out when not root and using recent Xenomai versions.
  Patch by S. Roderick. We'll improve (or remove) the 'root' detection if
  we can find a better way of seeing if root privileges are required.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29850 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for RTT to use Xenomai from non-standard install dir
  The paths for Xenomai are hard coded into RTT. This patch applies the
  recommended CMake method to find libraries, etc., using the
  CMAKE_INCLUDE_PATH and CMAKE_LIBRARY_PATH environment variables.
  S
  From: S Roderick <kiwi.net@mac.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29849 ce417995-dfc9-0310-95a0-acdaff106893
* Fix CommandProcessor queue processing
  It was reported on the mailing list that commands queued in a
  non-periodic activity were not all dequeued and only the first
  item was processed. This patch makes the CommandProcessor to
  process all queued commands in a step() and adds a unit test
  for checking this behaviour.
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29848 ce417995-dfc9-0310-95a0-acdaff106893
* Wrote initial changes document for RTT 1.8
  From: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29847 ce417995-dfc9-0310-95a0-acdaff106893
* Add imageobject attributes to pdf images for proper scaling. Fix running-over examples by keeping the example text short.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29825 ce417995-dfc9-0310-95a0-acdaff106893
* Upgrade PDF stylesheet to fop 0.94.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29824 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: NonPeriodicActivity::breakLoop() did not return false by default.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29819 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes bug #610: Check concurrent event implementation test
  The unit test itself was bogus. It did not implement the breakLoop()
  function and then did not test if stop() succeeded. Since breakLoop()
  returned false, stop() failed, but the unit test assumed the task was
  stopped. Hence drawing wrong results.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29818 ce417995-dfc9-0310-95a0-acdaff106893
* Squashed commit of the following:
  commit 46da027362568c175089989965feaff37e65dea8
  Author: Peter Soetens <peter.soetens@fmtc.be>
  Date:   Fri Jan 9 18:08:58 2009 +0100
  Fix gcc4 warnings about ambiguous if/else statements
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29817 ce417995-dfc9-0310-95a0-acdaff106893
* Location of cppunit headers not added to include directories of tests
  Hi,
  for some reason the location of the cppunit header are not added to
  the include directories of the tests:
  the attached patch fixes this.
  Ruben
  Signed-off-by: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29816 ce417995-dfc9-0310-95a0-acdaff106893
* Patch to make io-Eating available to other toolkits
  Patch makes the Eat/EatEnd/... internal functionality embedded in RTT::TypeStream, available to other toolkits/code.
  S
  Signed-off-by: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29815 ce417995-dfc9-0310-95a0-acdaff106893
* Fix GCC detection on SUSE as reported on orocos-dev ML.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29814 ce417995-dfc9-0310-95a0-acdaff106893
* Document and fix trigger() and start() behaviour of non-periodic threads/activities.
  SingleThread::start() returns now true when a loop() is still
  being scheduled.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29813 ce417995-dfc9-0310-95a0-acdaff106893
* Turn compilation of tests off by default.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29812 ce417995-dfc9-0310-95a0-acdaff106893
* Remove duplicate occurence of EventProcessor::hasWork() impl.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29811 ce417995-dfc9-0310-95a0-acdaff106893
* Completes the default SequentialActivity setup for TaskContext
  With this patch, any TaskContext is created with a 'sequential activity' by
  default. This means it can be started (or activated) and process commands and
  events, without having a thread. As a bonus, thread-safety is still fully
  guaranteed for these primitives and the behaviour is very similar (if not equal) to
  NonPeriodicActivity. When a command or event comes in, it is processed in the
  thread of the sender (ie sequential with the calling code). If multiple
  senders operate on the receiver, the first one processes all the requests, so
  no thread blocks in case of contention in this implementation.
  Please review and test this.
  New API:
  TaskContext a(A);
  a.start(); // works
  a.stop();
  a.setActivity( new PeriodicActivity(0, 0.01) ); // assign new activity to 'A'
  a.start(); now 'A' is periodic.
  a.stop();
  a.setActivity( 0 ); // make 'A' sequential again.
  // etc...
  This patch is backwards compatible with 'old' applications.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29810 ce417995-dfc9-0310-95a0-acdaff106893
* Fix AnalogOutput.hpp: return zero in rawValue()/value() when reading the subdevice fails.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29804 ce417995-dfc9-0310-95a0-acdaff106893
* Fix constructor syntax typo in manual.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29803 ce417995-dfc9-0310-95a0-acdaff106893
* Minor documentation additions to Timer class.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29802 ce417995-dfc9-0310-95a0-acdaff106893
* Re-test the lock-free event and fixes the unit test.
  Concurrent emits are now propertly handled.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29801 ce417995-dfc9-0310-95a0-acdaff106893
* This patch fixes up the rt_list implementation and the unit test.
  rt_list is capable of delivering the correct number of callbacks
  in multi-threaded cases. This of course does not fix the list lock
  free implementation, but it's at least an alternative.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29800 ce417995-dfc9-0310-95a0-acdaff106893
* Resurrect the oro_allocator and rt_list files for testing alternative
  event implementations (without lock-free lists).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29799 ce417995-dfc9-0310-95a0-acdaff106893
* [git] Add .gitignore file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29798 ce417995-dfc9-0310-95a0-acdaff106893
* This unit test discloses that concurrent emits of an event do not lead to the event handler being called for every emit.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29797 ce417995-dfc9-0310-95a0-acdaff106893
* Compile errors
  The patch itself, forgot to attach it,
  Ruben
  Disclaimer: http://www.kuleuven.be/cwis/email_disclaimer.htm
  ### Eclipse Workspace Patch 1.0
  #P rtt
  Signed-off-by: Peter Soetens <peter.soetens@fmtc.be>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29774 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup/removal of old usage patterns in manuals.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29773 ce417995-dfc9-0310-95a0-acdaff106893
* Plugins: Fix section about adding operator<<.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29772 ce417995-dfc9-0310-95a0-acdaff106893
* Remove outdated section from program processor manual.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29771 ce417995-dfc9-0310-95a0-acdaff106893
* Promote the usage of TaskContext::setActivity in the manual.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29770 ce417995-dfc9-0310-95a0-acdaff106893
* Add section about event driven data flow (addEventPort) and clarify in other sections the real-timeness and thread-safetyness of each primitive.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29769 ce417995-dfc9-0310-95a0-acdaff106893
* Remove superfluous run() implementation in SlaveActivity.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29756 ce417995-dfc9-0310-95a0-acdaff106893
* Fix minor documentation updates. Mention SequentialActivity in TaskContext manual.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29755 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: add caller as argument in ActivityInterface::disableRun
  Such that the activity can distinguish between the owning and
  an associated runnable interface. Only the owner calling disableRun(this)
  will cause the activity to erase the pointer to runner.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29754 ce417995-dfc9-0310-95a0-acdaff106893
* Fix regression: Do not check pam limits when we run as root.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29753 ce417995-dfc9-0310-95a0-acdaff106893
* Fix typo in TaskContext::start(): call TaskCore::start().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29752 ce417995-dfc9-0310-95a0-acdaff106893
* Merge branch 'sequential-act'
  Conflicts:
  src/EventDrivenActivity.cpp
  src/EventDrivenActivity.hpp
  src/NonPeriodicActivity.hpp
  src/TaskContext.hpp
  Minor conflicts due to the changes done on the Activity
  front in sequential-act and event-driven-data branches.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29751 ce417995-dfc9-0310-95a0-acdaff106893
* Moved the DataDrivenTask code to TaskContext and removed the former.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29750 ce417995-dfc9-0310-95a0-acdaff106893
* Improved data driven tasks.
  This patch removes the dependency on EventDrivenActivity for DataDrivenTask
  components. The event-triggering ports management is now done in DataFlowInterface
  (where port management belongs) and the DataDrivenTask only relies on information
  in that class. The new DataFlowInterface::addEventPort method sets which ports
  should fire events for this task. the DataDrivenTask::start method picks this up
  registers a callback and this one collects the data for updateHook(updated_ports).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29749 ce417995-dfc9-0310-95a0-acdaff106893
* event-driven: make DataDrivenTask and EventDrivenActivity RT-friendly
  The current implementation was using std::set to filter duplicates in
  the wakeup events. The problem is that std::set does allocate memory
  behind our backs, making it unusable in RT contexts.
  This patch changes the container from std::set to std::vector and, given
  that we know the maximum number of unique events to wake us up,
  reserves() that number on startup. Then, duplicates are searched "by
  hand". It could have a performance impact on tasks that listen to a high
  number of events, but that seems an unlikely situation. One would have
  to not only listen to a high number of events, but the event-driven
  activity would have to be scheduled so that most of these events fire
  before the activity gets fired.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29748 ce417995-dfc9-0310-95a0-acdaff106893
* rtt: provide information about triggering events in EventDrivenActivy/DataDrivenActivity
  After this commit, it is actually possible to know which events triggered
  the current step() in EventDrivenActivity. Moreover, in DataDrivenTask, a
  new updateHook( set<PortInterface*> const& ) method is provided, which
  gets called with the list of ports updated since the last update().
  The implementation should be thread-safe.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29747 ce417995-dfc9-0310-95a0-acdaff106893
* rtt: allow to use DataDrivenTask with other activities than the EventDrivenActivity
  The use of the EventDrivenActivity is now optional. This is to allow having an
  optional event-driven behaviour, but still being able to deploy some task
  contexts with other kind of activities.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29746 ce417995-dfc9-0310-95a0-acdaff106893
* corba: call removePort on the connection when the object is destroyed
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29745 ce417995-dfc9-0310-95a0-acdaff106893
* rtt: implement event-driven schemes
  This commit introduces a data-driven scheme in which a task is woken up
  when new data is available on one of its input ports. To achieve this,
  the following modifications have been done:
  * a per-input-port Event< void() > object can be created, which is
  signalled every time new data is written on this port.
  * the EventDrivenActivity has been resurrected (the current one could
  not even compile because of pure-virtual methods not being
  implemented). The new implementation is based on NonPeriodicActivity.
  It provides an addEvent method which defines which events should
  trigger the activity.
  * a DataDrivenTask, child of TaskContext, is provided. This glues
  everything by calling the addEvent method of its activity (which has
  to be an EventDrivenActivity) for all the trigger events of its input
  ports.
  This is still a partial implementation as the port events are signalled
  only if an input port has written on the connection. It won't work if
  the connection object is used directly.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29744 ce417995-dfc9-0310-95a0-acdaff106893
* Remove double header contents in PulseTrainGeneratorInterface.hpp (Reported by Bodmer Marc <Marc.Bodmer@bystronic.com>)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29729 ce417995-dfc9-0310-95a0-acdaff106893
* remove local unrevised changes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29694 ce417995-dfc9-0310-95a0-acdaff106893
* Add getRefernceTime to logger API for synchronization with reporting
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29693 ce417995-dfc9-0310-95a0-acdaff106893
* [PATCH] rtt: display exception info when PeriodicThread catches one (by S.Joyeux).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29683 ce417995-dfc9-0310-95a0-acdaff106893
* [PATCH] doc: ready() is not equivalent to connected()
  ready() is not equivalent to connected(): the implementation actually
  evaluates the data source once (i.e. checks that the data source can
  be read).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29682 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compilation errors with Intel compiler: move using operator=; directive to public:
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29681 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong -L flag in .pc file for CORBA.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29680 ce417995-dfc9-0310-95a0-acdaff106893
* Guard against faulty include directives in .pc files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29679 ce417995-dfc9-0310-95a0-acdaff106893
* Reset RTT_USER_LINKFLAGS at beginning of each cmake run.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29678 ce417995-dfc9-0310-95a0-acdaff106893
* Only build tests if cppunit is found.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29659 ce417995-dfc9-0310-95a0-acdaff106893
* Bump trunk version number to 1.6.99
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29642 ce417995-dfc9-0310-95a0-acdaff106893
* Fix -dev RTT packages such that they also contain the 1.4 SO_VERSION number. This allows switching between different development versions (one at a time), while being able to have all run-time library versions at the same time.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29624 ce417995-dfc9-0310-95a0-acdaff106893
* Fix .pc generation for all targets: let user link also with 'in headers exposed' libraries.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29623 ce417995-dfc9-0310-95a0-acdaff106893
* Remove unused files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29621 ce417995-dfc9-0310-95a0-acdaff106893
* [debian] Use the create-control.sh script to create the .install and control files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29620 ce417995-dfc9-0310-95a0-acdaff106893
* Fix real-time breaking bug in Property writing (Fix Proposed by S. Vandenbroucke).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29619 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compiler warning: implicit cast from char* to const char*: use strcpy/malloc/free combo.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29609 ce417995-dfc9-0310-95a0-acdaff106893
* revert commit r29603.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29607 ce417995-dfc9-0310-95a0-acdaff106893
* Fix xml bugs in install manual.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29605 ce417995-dfc9-0310-95a0-acdaff106893
* Add missing include.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29604 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compiler warning: implicit cast from char* to const char*: change fosi RTOS_TASK::name attribute to const char*
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29603 ce417995-dfc9-0310-95a0-acdaff106893
* Added bugzilla links and cleanups to rtt 1.6 changes doc.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29598 ce417995-dfc9-0310-95a0-acdaff106893
* Final patch from S. Roderick for getting RTT/OCL+ACE/TAO work on Mac OS-X.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29597 ce417995-dfc9-0310-95a0-acdaff106893
* Merge patch #355 from bug #533: Mac OS X port.
  Seems to work. Well done.
  [part 2: missing add of os/macosx]
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29596 ce417995-dfc9-0310-95a0-acdaff106893
* Merge patch #355 from bug #533: Mac OS X port.
  Seems to work. Well done.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29594 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #586: debian/control build-dependencies.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29578 ce417995-dfc9-0310-95a0-acdaff106893
* Applied patch #346 from Bug 533: Mac OS X port: RTT Corba Patch, adds UseCorba.cmake
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29574 ce417995-dfc9-0310-95a0-acdaff106893
* Add unit tests for setting buffers/ data ports with operator=
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29573 ce417995-dfc9-0310-95a0-acdaff106893
* Further preparing release notes for RTT 1.6.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29572 ce417995-dfc9-0310-95a0-acdaff106893
* Try to fix compile error in BufferPort/operator= by user.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29542 ce417995-dfc9-0310-95a0-acdaff106893
* fix syntax typo reported by S. Roderick
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29541 ce417995-dfc9-0310-95a0-acdaff106893
* Update docs for ControlTaskProxy::Create
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29515 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #580: No description set for this port even if set
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29499 ce417995-dfc9-0310-95a0-acdaff106893
* Massive fix of removing trailing whitespace.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29491 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compile error in corba_test.cpp test.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29487 ce417995-dfc9-0310-95a0-acdaff106893
* Debian: Depend on old | new xenomai package names.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29483 ce417995-dfc9-0310-95a0-acdaff106893
* Debian: Always compile rtt with -g
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29482 ce417995-dfc9-0310-95a0-acdaff106893
* configure script: be more robust against whitespaces in input.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29481 ce417995-dfc9-0310-95a0-acdaff106893
* Remove trailing white spaces from license header scripts.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29479 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug: issue fatal parse exception when property not found in property bag.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29478 ce417995-dfc9-0310-95a0-acdaff106893
* Fix parsing of nested properties (peerparser.taskObject() does not/never return null).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29443 ce417995-dfc9-0310-95a0-acdaff106893
* Added OCL section. Still need to insert the correct bugzilla links.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29434 ce417995-dfc9-0310-95a0-acdaff106893
* Add XML file format example + C++ to XML mapping.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29433 ce417995-dfc9-0310-95a0-acdaff106893
* Create package with debugging symbols
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29428 ce417995-dfc9-0310-95a0-acdaff106893
* Fix yet another TAO 1.6 issue: do not include <tao/Any.h> directly svn di src/corba/DataFlowI.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29418 ce417995-dfc9-0310-95a0-acdaff106893
* Remove buggy 'rtt-config-compat.h' include.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29409 ce417995-dfc9-0310-95a0-acdaff106893
* Removed 'building container from string' debug message.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29395 ce417995-dfc9-0310-95a0-acdaff106893
* Applied second patch from bug #567: Does not compile with TAO 1.6.
  Removes dead code and fixes link libraries.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29392 ce417995-dfc9-0310-95a0-acdaff106893
* Document some more changes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29391 ce417995-dfc9-0310-95a0-acdaff106893
* Apply patch from bug #566:CORBA Connections may cause TRANSIENT exception when server exited.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29389 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes for bug# 538: Unable specify log level when starting deployer
  Applied Logger patch (#315) on RTT
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29385 ce417995-dfc9-0310-95a0-acdaff106893
* Purified previous patch by using the C++ headers instead of the C headers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29378 ce417995-dfc9-0310-95a0-acdaff106893
* Applied patch from bug #568: Missing stdlib.h inclusions by S. Joyeux.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29377 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #565: Periodicity of thread not guaranteed under (preempt-rt) gnulinux
  Applied patch for using clock_nanosleep()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29372 ce417995-dfc9-0310-95a0-acdaff106893
* Use the ENABLE_TESTS macro, set to ON by default.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29366 ce417995-dfc9-0310-95a0-acdaff106893
* Use the ENABLE_TESTS macro.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29365 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #550: RTT doesn't know about pam_limits and rtprio for non-root users.
  Applied patch by S Roderick.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29363 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes bug #559: Seg fault on certain state machine transitions
  * all events are processed asynchronously
  * events are enabled before entry{}
  * events from entry{} are processed the same step
  * events from run {} are processed the next step
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29362 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes bug #563: scripting support for array broken
  return last object of partial path if partial is ok.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29361 ce417995-dfc9-0310-95a0-acdaff106893
* Oops, committed some local changes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29360 ce417995-dfc9-0310-95a0-acdaff106893
* rearranged array parser test
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29359 ce417995-dfc9-0310-95a0-acdaff106893
* adding tests for array constructors
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29358 ce417995-dfc9-0310-95a0-acdaff106893
* Test also for array assignment.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29354 ce417995-dfc9-0310-95a0-acdaff106893
* Fix assignment of fixed-size arrays.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29353 ce417995-dfc9-0310-95a0-acdaff106893
* Added signal recovery from nanosleep().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29352 ce417995-dfc9-0310-95a0-acdaff106893
* Re-add the const qualifier to the 'getter' methods of ports. Removing it broke too much applications, which used const as well.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29351 ce417995-dfc9-0310-95a0-acdaff106893
* Change constructor registration order of array to allow better accepted multi-args constructor syntax.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29346 ce417995-dfc9-0310-95a0-acdaff106893
* Fix destruction order of EE objects. Probably first stopping them is a better fix...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29345 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #561: build system lacks proper cppunit detection, part 2 :-)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29342 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #561: build system lacks proper cppunit detection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29340 ce417995-dfc9-0310-95a0-acdaff106893
* Set Logger::In for EE functions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29336 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #549: Call stop from your own thread. Patch applied
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29325 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #557: Parser should be more picky about what it accepts. Applied patch and tested. Sorry users for this *very* confusing behavior.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29324 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #558: RTT does not compile for TAO 1.5.x. Patch applied. Credits to Markus Eich for reporting and testing.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29323 ce417995-dfc9-0310-95a0-acdaff106893
* Add unit test for multi-threaded logger.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29322 ce417995-dfc9-0310-95a0-acdaff106893
* Fix possible unprotected access for bug# 545: Logger In() instances do not nest correctly
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29321 ce417995-dfc9-0310-95a0-acdaff106893
* Fix outstanding issues of bug# 545: Logger In() instances do not nest correctly
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29320 ce417995-dfc9-0310-95a0-acdaff106893
* Refine corba connection unit tests.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29310 ce417995-dfc9-0310-95a0-acdaff106893
* Add Logger::In to ControlTaskProxy
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29309 ce417995-dfc9-0310-95a0-acdaff106893
* Do not return null objects when querying for the datasource or buffer of a Corba Connection.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29308 ce417995-dfc9-0310-95a0-acdaff106893
* Fix connecting to already connected remote port using a CorbaPort/CorbaConnection.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29303 ce417995-dfc9-0310-95a0-acdaff106893
* Fix crash when connecting ports using a CORBA proxy and a taskcontext. Add unit tests, one still fails when connecting two proxies.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29300 ce417995-dfc9-0310-95a0-acdaff106893
* Fix connecting to remote connection from local side. Also, add disconnect() call to DataFlow.idl.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29294 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes bug #545: Logger In() instances do not nest correctly. Applied patch by S. Roderick (and P. Soetens).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29292 ce417995-dfc9-0310-95a0-acdaff106893
* Update the --nocatch option such that it must appear as the last option. When the remove it from argc/argv.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29290 ce417995-dfc9-0310-95a0-acdaff106893
* Add Logger::In statements.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29287 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug 510: loading multiple programscripts and statemachines
  Rewrite updateProperties such that a PropertyBag with n times the same propertyname is updated correctly n times, instead of all n being projected to a single property in the target bag.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29286 ce417995-dfc9-0310-95a0-acdaff106893
* Finish orocos-rtt-changes for 1.6.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29281 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #544: Unable have event transition with no select statements:
  Rewrote the transition parsing, added unit tests, updated documentation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29269 ce417995-dfc9-0310-95a0-acdaff106893
* Add comment about how to setup parser debugging
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29268 ce417995-dfc9-0310-95a0-acdaff106893
* Correct debug rules for ValueChangeParser
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29267 ce417995-dfc9-0310-95a0-acdaff106893
* Allow global (state machine wide) event and condition transitions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29256 ce417995-dfc9-0310-95a0-acdaff106893
* Add RemoteMethod.hpp to debian install list.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29247 ce417995-dfc9-0310-95a0-acdaff106893
* Add --list-missing for deb building.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29244 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #539: debian/liborocos-rtt-common-dev.install contains non-existing files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29243 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #541: error in installation manual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29242 ce417995-dfc9-0310-95a0-acdaff106893
* Fixup compile errors in patch by S. Roderick.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29231 ce417995-dfc9-0310-95a0-acdaff106893
* Added initial rtt-changes for 1.6.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29227 ce417995-dfc9-0310-95a0-acdaff106893
* Applied patch by S. Roderick: RTT::Logger patch allowing creation with automatic attachment to ostream.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29225 ce417995-dfc9-0310-95a0-acdaff106893
* Applying patch for bug #488: AnalogIn/OutInterface is an atrocity.
  Make analog interface raw type signed
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29223 ce417995-dfc9-0310-95a0-acdaff106893
* Remove wrong include of corba/Services.hpp
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29221 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #488: AnalogIn/OutInterface is an atrocity.
  Applied analog-interface-cleanup3.patch
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29219 ce417995-dfc9-0310-95a0-acdaff106893
* Set initial value in Set() when DataPort is not connected.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29217 ce417995-dfc9-0310-95a0-acdaff106893
* Fix type bug: use 'uint' instead of 'unsigned int' as type name.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29216 ce417995-dfc9-0310-95a0-acdaff106893
* Reduce verbosity of type transport registration
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29215 ce417995-dfc9-0310-95a0-acdaff106893
* Catch exceptions at the port level and disconnect the port if exceptions happen.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29214 ce417995-dfc9-0310-95a0-acdaff106893
* re-throw CORBA exception in ControlTaskProxy constructor.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29213 ce417995-dfc9-0310-95a0-acdaff106893
* Fix installation instructions for older Debian/Ubuntu version.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29205 ce417995-dfc9-0310-95a0-acdaff106893
* Fixing bug #529: [Scripting]No conversions available from int -> double ->float etc. Applied uint/float values patch from Fabian Wiesel.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29200 ce417995-dfc9-0310-95a0-acdaff106893
* Fixing bug #529: [Scripting]No conversions available from int -> double ->float etc. Applied auto-conversion patch.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29199 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong docs about 'trigger()', should read 'execute()'.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29198 ce417995-dfc9-0310-95a0-acdaff106893
* Fix case where a getDataSource() is done on a CorbaConnection of a Buffered remote port.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29195 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #512: [Project] Allow to load extra properties from file in a TaskContext.
  Patch applied. Dynamically (run-time) adding properties is now possible.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29193 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #527 and #532: Corba Data/Buffer ports do not respect connection direction.
  Patch applied.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29192 ce417995-dfc9-0310-95a0-acdaff106893
* Remove unnecessary debug messages from *repository classes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29154 ce417995-dfc9-0310-95a0-acdaff106893
* Misc installation fixes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29125 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes bug #522: Not needed to use TAO_IDL_BE. Final 'neutral' documentation fix.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29124 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #522: Not needed to use TAO_IDL_BE. Applied patch #255.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29123 ce417995-dfc9-0310-95a0-acdaff106893
* Revert part of previous patch: readers really need to be able to create connection objects. Now I remember again.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29098 ce417995-dfc9-0310-95a0-acdaff106893
* Added unit tests for different ways of connecting ports. Passes this revision.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29097 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes bug #527: Can not connect ports using only IDL interface
  Removes the createConnection functions from the Read* ports and fixes DataFlowI such that it uses PortInterface::connectTo(...)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29096 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes bug #527: Can not connect ports using only IDL interface
  Add connectPorts to C++ proxy interface.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29095 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes bug #527: Can not connect ports using only IDL interface
  changed the connectTo implementation such that remote ports get a chance of connecting as well.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29094 ce417995-dfc9-0310-95a0-acdaff106893
* Return connection handle in createConnection of ReadBufferPort.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29092 ce417995-dfc9-0310-95a0-acdaff106893
* New unit tests to test connection creation over corba.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29091 ce417995-dfc9-0310-95a0-acdaff106893
* 0010-corba-DataFlowInterface-connectPorts-does-not-nee.patch by Sylvain Joyeux <sylvain.joyeux@dfki.de>.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29090 ce417995-dfc9-0310-95a0-acdaff106893
* 0009-corba-trivial-fix-for-BufferChannel-empty.patch by Sylvain Joyeux <sylvain.joyeux@dfki.de>.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29089 ce417995-dfc9-0310-95a0-acdaff106893
* 0008-corba-fix-a-bad-void-cast.patch by Sylvain Joyeux <sylvain.joyeux@dfki.de>.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29088 ce417995-dfc9-0310-95a0-acdaff106893
* 0007-corba-validate-port-types-when-making-connections.patch by Sylvain Joyeux <sylvain.joyeux@dfki.de>.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29087 ce417995-dfc9-0310-95a0-acdaff106893
* 0006-corba-remove-leftovers-from-previous-merges.patch by Sylvain Joyeux <sylvain.joyeux@dfki.de>.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29086 ce417995-dfc9-0310-95a0-acdaff106893
* 0005-corba-implement-createConnection-on-reader-ports.patch by Sylvain Joyeux <sylvain.joyeux@dfki.de>.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29085 ce417995-dfc9-0310-95a0-acdaff106893
* 0004-corba-define-connectPorts-on-DataFlowInterface.patch by Sylvain Joyeux <sylvain.joyeux@dfki.de>.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29084 ce417995-dfc9-0310-95a0-acdaff106893
* 0003-corba-cleaning.patch by Sylvain Joyeux <sylvain.joyeux@dfki.de>.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29083 ce417995-dfc9-0310-95a0-acdaff106893
* 0002-corba-fix-crash-when-the-connection-creation-fails.patch by Sylvain Joyeux <sylvain.joyeux@dfki.de>.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29082 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #527: Can not connect ports using only IDL interface. CorbaPort did not implement serverProtocol, hence, the ConnectionFactory thought it was a local port.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29075 ce417995-dfc9-0310-95a0-acdaff106893
* Fix crash when ci is null in createBuffer/DataPort.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29073 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #527: Can not connect ports using only IDL interface. Patch applied but requires unit tests.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29069 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #528: Bug in ConnectionFactory: mixing readers and writers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29068 ce417995-dfc9-0310-95a0-acdaff106893
* Update time_test to new Timer API.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29059 ce417995-dfc9-0310-95a0-acdaff106893
* Add RTT 1.4.1 release notes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29055 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #511: Error when creating TimerComponent. Rename isActive() to isArmed().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29051 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #524: Method-Command repositories do not have removeX. Proposed fix applied.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29050 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #526: Corba-test fails on latest trunk. ORO_REMOTING was not enabled.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29049 ce417995-dfc9-0310-95a0-acdaff106893
* Add missing GPL+exception license texts in headers/sources.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29042 ce417995-dfc9-0310-95a0-acdaff106893
* Fix minor doxygen typo.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29041 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #523: OS_MAX_THREADS name is misleading. Rename to OS_MAX_CONC_ACCESS in CMake.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29040 ce417995-dfc9-0310-95a0-acdaff106893
* Update/fix gpl/lgpl header generation scripts.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29039 ce417995-dfc9-0310-95a0-acdaff106893
* Add OROCOS_TARGET_NAME macro which is a C-string of the target's name.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29028 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #500: Howto load external toolkits. Add ORO_TOOLKIT_PLUGIN macro for making an (external) toolkit a plugin.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29024 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #521: event transitions can cause crashes (in state machines,...).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29023 ce417995-dfc9-0310-95a0-acdaff106893
* Improve Invoker template API and add result_type typedef.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29002 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #178: Event transition in state machine script undected if no 'select' statement.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29001 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #520: getMethod<...>("name") does not work for remote/ CORBA components - unit tests.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@29000 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #520: getMethod<...>("name") does not work for remote/ CORBA components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28999 ce417995-dfc9-0310-95a0-acdaff106893
* Fix various image XML formatting mistakes: change 'fop' -> 'fo'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28998 ce417995-dfc9-0310-95a0-acdaff106893
* Fix crash when initialising Attribute with null pointer (happens when getAttribute<T>() returns null)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28997 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong priority of MainThread returned for gnulinux.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28986 ce417995-dfc9-0310-95a0-acdaff106893
* Update device interface manual.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28965 ce417995-dfc9-0310-95a0-acdaff106893
* Add instructions for Ubuntu users.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28964 ce417995-dfc9-0310-95a0-acdaff106893
* Fix very minor doxygen typo.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28950 ce417995-dfc9-0310-95a0-acdaff106893
* Added Debian/Ubuntu packages install instructions and updated
  Getting started/Makefile section
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28948 ce417995-dfc9-0310-95a0-acdaff106893
* Properly setup and cleanup CORBA environment in this test suite.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28904 ce417995-dfc9-0310-95a0-acdaff106893
* rtt/doc: Updated command example, added cross references, fixed download links, various edits for clarity.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28903 ce417995-dfc9-0310-95a0-acdaff106893
* Remove possibly harming assert(false) statement.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28902 ce417995-dfc9-0310-95a0-acdaff106893
* Fix memory leak in MethodC.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28901 ce417995-dfc9-0310-95a0-acdaff106893
* Scheduler RTAI soft threads in SCHED_OTHER.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28900 ce417995-dfc9-0310-95a0-acdaff106893
* Avoid 'TRAP' messages by enabling the FPU for each thread.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28883 ce417995-dfc9-0310-95a0-acdaff106893
* Fix build error/include paths for dev_test.cpp
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28857 ce417995-dfc9-0310-95a0-acdaff106893
* Fix install when BUILD_DOCS is ON or OFF
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28854 ce417995-dfc9-0310-95a0-acdaff106893
* Add api and xml dirs to CMakeLists.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28840 ce417995-dfc9-0310-95a0-acdaff106893
* Review of the first chapters of the components manual. Improved some figures.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28834 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #482: Corba's createMethodAny and createCommandAny methods broken.
  Tested and applied patch. Adds a unit test for corba a well.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28833 ce417995-dfc9-0310-95a0-acdaff106893
* Minor cleanup of unnecessary includes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28832 ce417995-dfc9-0310-95a0-acdaff106893
* Add setBit(bool) function to DigitalOutput. Add some unit tests for dev/Digital* dev/Analog* classes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28831 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong order of checking preconditions in run(unsigned int ms) function.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28830 ce417995-dfc9-0310-95a0-acdaff106893
* Minor log() typo fixes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28829 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: MainThread::getPriority() returns a random number in gnulinux. Now returns 0.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28828 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #486: SimulationThread locks up system under Xenomai 2.4
  Applied proposed patch. Tested on testfarm.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28827 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrning: missing braces around initializer for ‘char [1]’
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28824 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #481: connectPorts only partially connects two read ports.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28818 ce417995-dfc9-0310-95a0-acdaff106893
* Add example for error states.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28789 ce417995-dfc9-0310-95a0-acdaff106893
* replace orocos mailinglist with orocos-users.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28787 ce417995-dfc9-0310-95a0-acdaff106893
* Fix typo in addConstructor example.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28786 ce417995-dfc9-0310-95a0-acdaff106893
* Fix orocos-rtt-corba.pc file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28755 ce417995-dfc9-0310-95a0-acdaff106893
* Last documentation updates before release.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28746 ce417995-dfc9-0310-95a0-acdaff106893
* Look for xenomai in even more places
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28743 ce417995-dfc9-0310-95a0-acdaff106893
* Add idl target to avoid code generation mess when using make -jx
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28738 ce417995-dfc9-0310-95a0-acdaff106893
* Correct version number of rtt trunk to 1.4.99
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28737 ce417995-dfc9-0310-95a0-acdaff106893
* Add MAKE_FLAGS and boost-dev deps.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28729 ce417995-dfc9-0310-95a0-acdaff106893
* Minor updates to RTT 1.4.0 news.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28714 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #462: make check fails to compile the tests
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28708 ce417995-dfc9-0310-95a0-acdaff106893
* fix minor type in NEWS
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28707 ce417995-dfc9-0310-95a0-acdaff106893
* Work around some catalog file issues in DocBook processing.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28701 ce417995-dfc9-0310-95a0-acdaff106893
* Prepare release notes for 1.4.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28700 ce417995-dfc9-0310-95a0-acdaff106893
* Clarify some CORBA aspects and tools of RTT.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28699 ce417995-dfc9-0310-95a0-acdaff106893
* Merge bug #423 [Project] Improve Component execution model and #354 update() of taskcontext executed too often
  The TaskCore/TaskContext interface has been extended to control the Active, FatalError, RunTimeWarning and RunTimeError states.
  Documentation and tests have been updated. Note: reset() was renamed to resetError() to avoid conflicts with existing user code.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28698 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup logger OS info strings.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28697 ce417995-dfc9-0310-95a0-acdaff106893
* Fix *.install scripts for lxrt.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28696 ce417995-dfc9-0310-95a0-acdaff106893
* Add LXRT to rules/control for RTT 1.4.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28695 ce417995-dfc9-0310-95a0-acdaff106893
* Apply patch by Leopold Palomo Avellaneda lepalom at wol. es:
  Upgrade debian packages to RTT 1.4. Fix some cmake bugs along the way:
  * Set SO_VERSION to 1.4
  * Handle marshalling correctly
  * Build static and dynamic libs
  * Xenomai Debian support
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28685 ce417995-dfc9-0310-95a0-acdaff106893
* Initialise res = -1 in ORO_main macro (2).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28680 ce417995-dfc9-0310-95a0-acdaff106893
* Initialise res = -1 in ORO_main macro.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28679 ce417995-dfc9-0310-95a0-acdaff106893
* Fix sporadic crashes when using logger in RTAI 3.5: something fishy in the rtai headers messes our stack up. To be further investigated, may be an interfering MACRO or function/variable name conflict.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28678 ce417995-dfc9-0310-95a0-acdaff106893
* ORO_main(): Fix use of Logger class after __os_exit().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28675 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #453: One can not specify where boost headers are installed
  I added a BOOST_INSTALL directory option. Use -DBOOST_INSTALL=/opt/include for example.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28674 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #459: ORO_main should be optionally defined
  This solves link issues on Mac OS X as well.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28673 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong include paths in boost headers: use macro tricking.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28669 ce417995-dfc9-0310-95a0-acdaff106893
* Install boost/function_types into rtt/boost/function_types.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28665 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compiler warnings (int/uint comparison) in Timer.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28657 ce417995-dfc9-0310-95a0-acdaff106893
* Fix crashes with newer glibc versions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28656 ce417995-dfc9-0310-95a0-acdaff106893
* Change type name of 'unknown type' to 'unknown_t'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28655 ce417995-dfc9-0310-95a0-acdaff106893
* Document most important changes for RTT 1.4.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28635 ce417995-dfc9-0310-95a0-acdaff106893
* Define _XOPEN_SOURCE 'just to be sure' we got all defines we need.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28634 ce417995-dfc9-0310-95a0-acdaff106893
* Drop TypeTransporter code when using ORO_EMBEDDED.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28633 ce417995-dfc9-0310-95a0-acdaff106893
* Fix link libraries for tests: append -${OROCOS_TARGET} to lib names
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28629 ce417995-dfc9-0310-95a0-acdaff106893
* Remove dead template code from CORBA layer.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28628 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup/improve the synchronize() method of the ControlTaskProxy. Not yet fully what we want (auto synchronisation), but anyway an improvement.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28627 ce417995-dfc9-0310-95a0-acdaff106893
* Fix crashes in DataSource narrowing during TypeTransport. Use dynamic_cast instead of static_cast.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28626 ce417995-dfc9-0310-95a0-acdaff106893
* Remove support for RTAI 2.24.x
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28625 ce417995-dfc9-0310-95a0-acdaff106893
* Remove support for RTAI 2.24.x
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28624 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #452: error: ‘LLONG_MAX’ was not declared in this scope.
  Define this macro ourselves if not provided by the compiler.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28623 ce417995-dfc9-0310-95a0-acdaff106893
* Update email addresses.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28622 ce417995-dfc9-0310-95a0-acdaff106893
* Create a 'targets' subdirectory to contain specialisations of the rtt-config.h file. The OROCOS_TARGET define is now used to locate the target file. Also the library names and .pc files are extended with the -<target> suffix. This is all to support multiple targets in the same directory. If no target is specified, a default is used.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28621 ce417995-dfc9-0310-95a0-acdaff106893
* Add note about why not calling cleanup() in destructor (virtual function)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28620 ce417995-dfc9-0310-95a0-acdaff106893
* Fix typos in component manual and update installation instructions with new TAO/CORBA semantics.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28618 ce417995-dfc9-0310-95a0-acdaff106893
* Fix uncaught exception in state machine script parsing when using transition events.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28616 ce417995-dfc9-0310-95a0-acdaff106893
* Fix doc about property marshalling, fix catalog location in cmake.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28612 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed reading of bool (true/false) values (from KTaskBrowser).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28596 ce417995-dfc9-0310-95a0-acdaff106893
* Try to fix reading of bool (true/false) values.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28595 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for new CORBA protocol layer: better checks for remote data narrowing.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28589 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #451: RTT Corba Proxy object does not replicate remote interface correctly
  First, clear the interface before reconstructing the remote interface,
  then reconstruct the objects correctly and recursively.
  Also fixes a crash in getPeerList if the ControlTask == NotFound.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28588 ce417995-dfc9-0310-95a0-acdaff106893
* Add some assert()'s to CORBAExpression class.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28587 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #450: Fix re-arming of expired timer in Timer::timeout()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28578 ce417995-dfc9-0310-95a0-acdaff106893
* Doc: Fix XML file generation in source dir. This breaks dependency checking on the catalog.xml file though.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28577 ce417995-dfc9-0310-95a0-acdaff106893
* Bump trunk version number to 1.4.99 and uncache version number.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28576 ce417995-dfc9-0310-95a0-acdaff106893
* Add svn:ignore of build, patch, hidden files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28575 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #448: RTT applications get killed under Xenomai 2.3.2 and higher:
  Use rt_task_join to cleanup threads nicely.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28561 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #449: Xenomai fosi.h needs cleanup:
  Remove dangerous constructs, inline xenomai wrapper calls.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28560 ce417995-dfc9-0310-95a0-acdaff106893
* Modify SimulationThread such that run(int steps) does not work when already running. Would cause concurrency problems.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28558 ce417995-dfc9-0310-95a0-acdaff106893
* Modify more tests such that they use the SimulationThread more correctly.
  These mis-uses were discovered by a more performant PeriodicActivity implementation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28557 ce417995-dfc9-0310-95a0-acdaff106893
* Remove debug 'cout' statements from timer test.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28556 ce417995-dfc9-0310-95a0-acdaff106893
* Modify some taskcontext tests such that they use the SimulationThread more correctly.
  These mis-uses were discovered by a more performant PeriodicActivity implementation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28555 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compile error: add detail:: namespace.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28552 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #371: [Project] PeriodicActivity/TimerThread imposes too much overhead
  Applied patch remove-timer-interface.patch
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28551 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug 447: Several crashes using ctaskbrowser (CORBA):
  Invert the proxy <-> object reference lookup of the proxies cache, seems to fix ControlTaskProxy::Create() method (magic fix).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28550 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #447: Several crashes using ctaskbrowser (CORBA):
  fix CORBA memory management in proxies.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28549 ce417995-dfc9-0310-95a0-acdaff106893
* Finishing up the pluggable protocol part of RTT/Corba. Add fall-back protocol which displays warnings if protocol or type are unknown.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28548 ce417995-dfc9-0310-95a0-acdaff106893
* Remove duplicated code in header.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28506 ce417995-dfc9-0310-95a0-acdaff106893
* Remove deprecated factory classes and getArgumentSpec() method.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28505 ce417995-dfc9-0310-95a0-acdaff106893
* Add missing includes for limits.h and float.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28504 ce417995-dfc9-0310-95a0-acdaff106893
* Add missing constants InfiniteTicks, InfiniteNSecs and InfiniteSeconds for lxrt.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28503 ce417995-dfc9-0310-95a0-acdaff106893
* Add missing <cassert> include.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28502 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #439: [Project]Make CORBA transport pluggable.
  Medium size patch, valgrind tested.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28501 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #442: RTT::EventService: getEvents returns no names.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28500 ce417995-dfc9-0310-95a0-acdaff106893
* Added minor code comments.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28499 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #438:[Project]TimerComponent for time based events.
  Add Timer class, OS support (linux,lxrt,xenomai) and unit tests.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28488 ce417995-dfc9-0310-95a0-acdaff106893
* Document corbaloc workaround for using the Naming Service.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28487 ce417995-dfc9-0310-95a0-acdaff106893
* Minor doc changes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28486 ce417995-dfc9-0310-95a0-acdaff106893
* AnyToPNG: Remove annoying debug messages.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28484 ce417995-dfc9-0310-95a0-acdaff106893
* Test ScriptingAccess as well in state test.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28483 ce417995-dfc9-0310-95a0-acdaff106893
* Avoid rounding errors in LXRT/rtos_task_set_period when nanosecs == 0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28482 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #435: make check fails for rtai 3.3:
  Fix regression caused bug fix for bug #360.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28471 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #431: os/oro_powerpc not build
  The powerpc headers were not installed.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28413 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #428: Logger::In in(module) may crash in multi-threaded scenarios:
  Do not restore parent Logger module pointer, but set it to [Logger].
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28400 ce417995-dfc9-0310-95a0-acdaff106893
* Reduce Logger code in ExecutionEngine.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28399 ce417995-dfc9-0310-95a0-acdaff106893
* Reduce Logger code in thread classes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28398 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #427: [Critical] Could not create thread TimerThreadInstance.
  Use pthread_join() in gnulinux layer to free up resources.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28394 ce417995-dfc9-0310-95a0-acdaff106893
* Spelling fixes and minor edits
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28390 ce417995-dfc9-0310-95a0-acdaff106893
* Minor clarifications to installation manual.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28382 ce417995-dfc9-0310-95a0-acdaff106893
* RTT Release notes for 1.2.1
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28362 ce417995-dfc9-0310-95a0-acdaff106893
* be more permissive in ticksconversion test.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28360 ce417995-dfc9-0310-95a0-acdaff106893
* re-activate all unit test cases for time, logger and buffers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28356 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #360: Rounding errors in time algorithms in RTAI > 3.3
  Set EPSILON (allowed error) to 2 ns instead of 1 ns in test case.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28355 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #360: [CRITICAL][/src/rtt/build-lxrt/tests/task-test::main()] The TimerThreadInstance thread seems to be blocked ( ret was 65534 .) for RTAI 3.4/3.5
  * Corrected the return values of rtos_sem_wait_timed: return 0 on success, -1 on timeout.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28354 ce417995-dfc9-0310-95a0-acdaff106893
* Do not include fosi.h in Event headers. Fix Event.hpp license text.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28353 ce417995-dfc9-0310-95a0-acdaff106893
* Adapt CORBA layer to fix of bug #422: StatementProcessor::getCommand(int ticket) causes segfault.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28343 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #422: StatementProcessor::getCommand(int ticket) causes segfault
  Changes API of getCommand in ScriptingAccess and StatementProcessor.
  getCommand(int ticket) returns a DispatchInterface::shared_ptr
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28341 ce417995-dfc9-0310-95a0-acdaff106893
* Minor documentation cleanups. Deprecate some unused classes, suggest ConditionInterface -> DataSource<bool> conversion.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28340 ce417995-dfc9-0310-95a0-acdaff106893
* Fix configure wrapper script when --prefix is used.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28339 ce417995-dfc9-0310-95a0-acdaff106893
* Fix StatementProcessor command execution: use dispatch() such that command is executed in CommandProcessor instead of in current thread.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28334 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup of documentation:
  - remove dominant author listing.
  - update copyright years to 2007
  - minor cleanups.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28325 ce417995-dfc9-0310-95a0-acdaff106893
* Re-vamped the pdf/html doc generation, using hires images for pdf.
  Also using the B/W svg 'admon' icons instead of older png icons.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28316 ce417995-dfc9-0310-95a0-acdaff106893
* Globally use -D_REENTRANT for TAO headers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28310 ce417995-dfc9-0310-95a0-acdaff106893
* Better compiler detection when using distcc
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28309 ce417995-dfc9-0310-95a0-acdaff106893
* Add notes about the configure script options.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28253 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #412 :Include rtt-config.h in Corba headers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28248 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #419: CORBA Action::executeAny does not use given arguments.
  Due to a name clash between sub- and super-class, the wrong object was called upon executeAny.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28245 ce417995-dfc9-0310-95a0-acdaff106893
* Fix Method example: do not clash with in 1.2.0 added clean() method.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28242 ce417995-dfc9-0310-95a0-acdaff106893
* Minor Logger::log() => log() rewriting cleanups in CORBA code.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28241 ce417995-dfc9-0310-95a0-acdaff106893
* More clear error message when connection setup fails.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28240 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #412: _REENTRANT has to be defined for Corba build.
  The easiest backwards compatible fix is to define it in the rtt-config.h file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28239 ce417995-dfc9-0310-95a0-acdaff106893
* Document in code why scripting asfds+asdfa is not allowed (memory allocation)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28238 ce417995-dfc9-0310-95a0-acdaff106893
* Fix minor doxy typo in PeerParser.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28237 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #417: Compile error when configuring Read/WriteBufferPort connections.
  Add pure virtuals in BufferConnection base classes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28236 ce417995-dfc9-0310-95a0-acdaff106893
* Add RTT_EXPORT decl to Property and PropertyBag classes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28217 ce417995-dfc9-0310-95a0-acdaff106893
* Bump trunk version number to 1.2.99
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28206 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug# 410: gnulinux fosi contains accidental abort() statement.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28193 ce417995-dfc9-0310-95a0-acdaff106893
* Minor typo fixes in changes doc.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28136 ce417995-dfc9-0310-95a0-acdaff106893
* Add 1.2.0 release notes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28133 ce417995-dfc9-0310-95a0-acdaff106893
* Added new header locations to installation manual.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28124 ce417995-dfc9-0310-95a0-acdaff106893
* Document bug #402: Mixing liborocos-rtt.a and .so causes crash upon exit.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28123 ce417995-dfc9-0310-95a0-acdaff106893
* Fix memleaks when calling removeEvent.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28121 ce417995-dfc9-0310-95a0-acdaff106893
* Add unit test check for adding twice same portname.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28120 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #401: ports()->removePort does not remove associated TaskObject from interface.
  This patch fixes that issue and adds a unit test as well.
  It also deprecates some 'utility' functions for 'exporting' ports, which is now done automatically when the port is added.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28119 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: display RTT version instead of 'OROPKG_CORELIB'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28118 ce417995-dfc9-0310-95a0-acdaff106893
* Add initial svn-users-to-email mapping file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28070 ce417995-dfc9-0310-95a0-acdaff106893
* Modify svn2log to have prettier formatting.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28069 ce417995-dfc9-0310-95a0-acdaff106893
* Move svn2log.py script to scripts dir.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28068 ce417995-dfc9-0310-95a0-acdaff106893
* Remove empty directory
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28067 ce417995-dfc9-0310-95a0-acdaff106893
* Add svn2log.py script.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28066 ce417995-dfc9-0310-95a0-acdaff106893
* Remove old svn:ignore property.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28058 ce417995-dfc9-0310-95a0-acdaff106893
* Remove stale svnmerge-integrated property.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28055 ce417995-dfc9-0310-95a0-acdaff106893
* Install RTT by default in /usr/local.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28054 ce417995-dfc9-0310-95a0-acdaff106893
* Revert part of r28012: OperationInterface has no member properties().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28020 ce417995-dfc9-0310-95a0-acdaff106893
* Rewrite all attributes()->properties() to properties()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28012 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #388: Property of std::vector<double> not working:
  Same bug present in refreshProperties, typically used when reading a file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28011 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #388: Property of std::vector<double> not working.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@28008 ce417995-dfc9-0310-95a0-acdaff106893
* Update FAQ, ulinks and misc changes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27986 ce417995-dfc9-0310-95a0-acdaff106893
* Set generated version number.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27985 ce417995-dfc9-0310-95a0-acdaff106893
* Fix TaskState bug when task was started/stopped with ActivityInterface::start() instead of TaskCore::start().
  The EE now manages state transitions between Stopped and Running.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27974 ce417995-dfc9-0310-95a0-acdaff106893
* Minor edits in orocos-rtt-changes and -installation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27971 ce417995-dfc9-0310-95a0-acdaff106893
* Fix version macro: RTT_VERSION.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27970 ce417995-dfc9-0310-95a0-acdaff106893
* Minor doxygen updates.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27966 ce417995-dfc9-0310-95a0-acdaff106893
* Correct version number macro: RTT_VERSION
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27965 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #385: Component starts anyway it was not configured yet.
  Add an optional parameter to the TaskContext/TaskCore constructor indicating the initial state.
  Adapt manuals
  Write unit test.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27942 ce417995-dfc9-0310-95a0-acdaff106893
* Make libraries overview fig a Figure.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27941 ce417995-dfc9-0310-95a0-acdaff106893
* Center figures&captions in html/pdf docs.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27940 ce417995-dfc9-0310-95a0-acdaff106893
* Fix include path for oro_atomic.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27933 ce417995-dfc9-0310-95a0-acdaff106893
* Fix undefined symbols: use NANO_TIME instead of RTIME in fosi_internal functions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27932 ce417995-dfc9-0310-95a0-acdaff106893
* Also detect xenomai in debian package locations.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27931 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup parsed StateMachine and Task Objects:
  * _really\_ fix left-over variable after parse error (Bug #379)
  * rename confusing variables in state machine parser class (context->machine)
  * rename set/getTaskContext to set/getTaskObject in ParsedStateMachine
  * Fix crash: invalid task object list after state machine parse error.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27902 ce417995-dfc9-0310-95a0-acdaff106893
* Fix CORBA crash: check validity of cached TaskObject pointer.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27901 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #378: Loading program in KTaskbrowser reports success upon syntax error:
  After reverting r6925 , this patch actually fixes this bug.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@27885 ce417995-dfc9-0310-95a0-acdaff106893
* Revert r6924: wrong fix on wrong file (bug #378).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6969 ce417995-dfc9-0310-95a0-acdaff106893
* Updated README for RTT 1.2.0: Added notes about CORBA, --enable-corba.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6968 ce417995-dfc9-0310-95a0-acdaff106893
* Updated doc/README.txt to 1.2.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6967 ce417995-dfc9-0310-95a0-acdaff106893
* Added most/all changes to RTT 1.2.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6964 ce417995-dfc9-0310-95a0-acdaff106893
* Renamed orocos-changes.xml to orocos-rtt-changes.xml.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6963 ce417995-dfc9-0310-95a0-acdaff106893
* Fix drawing: update() -> updateHook().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6958 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #377: Errors when starting program.
  Fixes double registration of data ports and a memleak.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6957 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #326: [Project]XML format: change of type=xyz fields
  In new property files, PropertyBags will be written as structs with type=PropertyBag
  std::vector<double> will be written as structs with type=array
  Fully backwards compatible (unit test included).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6952 ce417995-dfc9-0310-95a0-acdaff106893
* Property: operator<<: get streaming from DataSourceBase class.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6951 ce417995-dfc9-0310-95a0-acdaff106893
* CPF: Allow the name of an element to be empty.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6950 ce417995-dfc9-0310-95a0-acdaff106893
* Verify scheduler/priority before creating a new thread.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6949 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #382: RTT does not provide means to check scheduler/priority combos.
  bool CheckScheduler(int& sched_type)
  bool CheckPriority(int& sched_type, int& priority);
  int rtos_task_check_scheduler(int* sched);
  int rtos_task_check_priority(int* sched, int* prio);
  For all OS'es (ecos untested).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6948 ce417995-dfc9-0310-95a0-acdaff106893
* Update name, description of .pc file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6945 ce417995-dfc9-0310-95a0-acdaff106893
* Fix VERSION -> RTT_VERSION in .pc file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6942 ce417995-dfc9-0310-95a0-acdaff106893
* Basic packaging instructions for building tar.gz and deb files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6941 ce417995-dfc9-0310-95a0-acdaff106893
* Builds debian package for gnulinux.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6940 ce417995-dfc9-0310-95a0-acdaff106893
* Added extra --enable/--disable flags for corba, embedded, shared
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6939 ce417995-dfc9-0310-95a0-acdaff106893
* Added the CMAKE_CXX_FLAGS_ADD macro which collects -f/-O/-W flags for building the lib.
  RTT_CFLAGS is now only used for the orocos-rtt.pc file (i.e. -I... flags)
  Added SOVERSION to .so target.
  Do not use Xerces when exceptions are disabled.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6938 ce417995-dfc9-0310-95a0-acdaff106893
* Turning CORBA by default off, even if detected.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6937 ce417995-dfc9-0310-95a0-acdaff106893
* Fighting the nasty gcc 4.1.2 bug again.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6936 ce417995-dfc9-0310-95a0-acdaff106893
* Do not install config.guess and config.sub
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6935 ce417995-dfc9-0310-95a0-acdaff106893
* Remove 2 .bak files in boost/function_types.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6934 ce417995-dfc9-0310-95a0-acdaff106893
* Fix various memleaks regarding scripting objects (Fixes bugs introduced on the 1.2 branch).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6933 ce417995-dfc9-0310-95a0-acdaff106893
* Fix various memleaks when event connection setup fails.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6932 ce417995-dfc9-0310-95a0-acdaff106893
* Fix memleak, add clear() method to EventService.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6931 ce417995-dfc9-0310-95a0-acdaff106893
* Fix numerous potential memleaks in type system when converting types.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6930 ce417995-dfc9-0310-95a0-acdaff106893
* Fix memleak in unit test.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6929 ce417995-dfc9-0310-95a0-acdaff106893
* Added section about selecting the scheduler for an Activity.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6928 ce417995-dfc9-0310-95a0-acdaff106893
* Install initial debian package directory structure.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6927 ce417995-dfc9-0310-95a0-acdaff106893
* Allow to --disable-corba.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6926 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #379: 'Ghost' attributes appear in TaskContext when state machine loading fails.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6925 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #378: Loading program in KTaskbrowser reports success upon syntax error.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6924 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #376: Programs not accessible in stateMachine
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6916 ce417995-dfc9-0310-95a0-acdaff106893
* copy orocos-html.css when generating html docs.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6914 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for Bug #322: Do not use #include <pkgconf/system.h>: Add RTT_VERSION* defines to rtt-config.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6902 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #367: PeriodicActivity does not start PeriodicThread if necessary.
  Patch + unit test.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6854 ce417995-dfc9-0310-95a0-acdaff106893
* Test threads with 100Hz threads instead of 1kHz threads such that embedded systems have a chance to keep up.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6853 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong priority setting leading to mass thread-creation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6852 ce417995-dfc9-0310-95a0-acdaff106893
* Finished ecos merge into build system. Untested.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6851 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #365: ThreadInterface::getScheduler() returns wrong scheduler in Xenomai.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6850 ce417995-dfc9-0310-95a0-acdaff106893
* Added ecos target.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6849 ce417995-dfc9-0310-95a0-acdaff106893
* Revert patch 6847.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6848 ce417995-dfc9-0310-95a0-acdaff106893
* Added ecos target.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6847 ce417995-dfc9-0310-95a0-acdaff106893
* Generate rtt.tag file in doc/ dir.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6846 ce417995-dfc9-0310-95a0-acdaff106893
* Move ComponentArch.svg to images/xml dir.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6845 ce417995-dfc9-0310-95a0-acdaff106893
* * Updated manuals with new figures
  * Remove states. and programs. prefixes from example scripts
  * Explain TaskContext state diagram.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6844 ce417995-dfc9-0310-95a0-acdaff106893
* Fix rtt symlink for Doxygen, Add docs/docapi make targets.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6843 ce417995-dfc9-0310-95a0-acdaff106893
* Improved cmake wrapper script.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6842 ce417995-dfc9-0310-95a0-acdaff106893
* * Generate ocl-intro and toolkit-plugin docs.
  * Fix doxygen 'ln -s rtt' link
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6841 ce417995-dfc9-0310-95a0-acdaff106893
* Rewrite the installation manual for release 1.2.0, remove obsoleted files in doc dir.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6840 ce417995-dfc9-0310-95a0-acdaff106893
* Doc: Added front page figure, fixed reserved words column layout in parser manual, do not create pdf from orocos-faq.xml
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6839 ce417995-dfc9-0310-95a0-acdaff106893
* Fix include path after check-headers.sh.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6838 ce417995-dfc9-0310-95a0-acdaff106893
* Script to check installed files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6837 ce417995-dfc9-0310-95a0-acdaff106893
* Fix include path.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6836 ce417995-dfc9-0310-95a0-acdaff106893
* Do not use/compile broken CORBA classes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6835 ce417995-dfc9-0310-95a0-acdaff106893
* Do not use/compile broken CORBA classes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6834 ce417995-dfc9-0310-95a0-acdaff106893
* Fix ThreadScope include, move it to .cpp file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6833 ce417995-dfc9-0310-95a0-acdaff106893
* Move TaskState to TaskCore in order to keep consistent with 1.0 semantics.
  The ExecutionEngine asks the TaskCore if it may start (TaskState==Stopped).
  The EE does not know the TaskContext class, thus the state must be kept in TaskCore.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6832 ce417995-dfc9-0310-95a0-acdaff106893
* Fix ThreadScope include, move it to .cpp file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6831 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compilation error on wrong log() usage.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6830 ce417995-dfc9-0310-95a0-acdaff106893
* Fix DriveInterface include.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6829 ce417995-dfc9-0310-95a0-acdaff106893
* Fix PropertyMarshaller classes to report error when marshalling is disabled by user.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6828 ce417995-dfc9-0310-95a0-acdaff106893
* Fix lookup bug in PeerParser, make CommandParser errors pretty.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6827 ce417995-dfc9-0310-95a0-acdaff106893
* Fix include directives for NameServer.hpp in rtt/dev
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6826 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong include path.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6825 ce417995-dfc9-0310-95a0-acdaff106893
* Fix dead link in API main page.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6824 ce417995-dfc9-0310-95a0-acdaff106893
* Beautified doxygen generation (include hint)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6823 ce417995-dfc9-0310-95a0-acdaff106893
* Fix linking to nested namespaces in API docs.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6822 ce417995-dfc9-0310-95a0-acdaff106893
* Merged docs from r6544:6750
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6821 ce417995-dfc9-0310-95a0-acdaff106893
* Generate faq/changes doc files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6820 ce417995-dfc9-0310-95a0-acdaff106893
* Fix configure script when using CC=, CXX=.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6819 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed doc generation dependencies, orocos.ent generation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6818 ce417995-dfc9-0310-95a0-acdaff106893
* Added docpdf, dochtml and docpng targets.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6817 ce417995-dfc9-0310-95a0-acdaff106893
* Fix dangling references in xml docs, update orocos.ent path in catalog.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6816 ce417995-dfc9-0310-95a0-acdaff106893
* Complete documentation generation PDF/HTML.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6815 ce417995-dfc9-0310-95a0-acdaff106893
* XSL cleanup: fix xsltsl files and rename orocos.xsl to orocos-pdf.xsl
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6814 ce417995-dfc9-0310-95a0-acdaff106893
* Updated configure script, set default RTAI/XENOMAI INSTALL_DIR if not set.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6813 ce417995-dfc9-0310-95a0-acdaff106893
* Updated release txt files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6812 ce417995-dfc9-0310-95a0-acdaff106893
* Added more orocos-changes entries.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6811 ce417995-dfc9-0310-95a0-acdaff106893
* Remove broken TAO services from RTT: CosProperty and CosEvent.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6810 ce417995-dfc9-0310-95a0-acdaff106893
* Fix target cpu detection: move detection from check_depend.cmake to rtt-config.h.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6809 ce417995-dfc9-0310-95a0-acdaff106893
* Addition for bug #352: TaskContext offers no configuration function
  Corba fix for ControlTaskProxy.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6808 ce417995-dfc9-0310-95a0-acdaff106893
* Patch of bug #328:[Project]Refactor TaskObject vs TaskContext.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6807 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug in patch for bug #325: 'Could not open file for writing'.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6806 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug in patch for bug #353: stop() blocks forever.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6805 ce417995-dfc9-0310-95a0-acdaff106893
* Patch of bug #352:TaskContext offers no configuration function.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6804 ce417995-dfc9-0310-95a0-acdaff106893
* Fix copy/paste typo for gnulinux config.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6803 ce417995-dfc9-0310-95a0-acdaff106893
* Patch of bug #353: loopActivity
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6802 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #301:Toolkit Plugins should provide read()/operator>> as well
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6801 ce417995-dfc9-0310-95a0-acdaff106893
* Patch of bug #325: [Project]Add PropertyMarshaller class
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6800 ce417995-dfc9-0310-95a0-acdaff106893
* Fix Xenomai native+posix skin:'Cannot rt_task_create() MainThread.'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6799 ce417995-dfc9-0310-95a0-acdaff106893
* Fix boost/xerces detection by using own version of CheckIncludeFileCXX.cmake
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6798 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: use OS_HAVE_STREAMS instead of HAVE_STREAMS.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6797 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: Do not use stringstream if streams not supported.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6796 ce417995-dfc9-0310-95a0-acdaff106893
* Fix typo in docs.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6795 ce417995-dfc9-0310-95a0-acdaff106893
* Added initial PowerPC+Cross-compiling support.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6794 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong include of Marshaller.hpp header.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6793 ce417995-dfc9-0310-95a0-acdaff106893
* Fix include macro of TinyDemarshaller.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6792 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong include paths in generictask_test.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6789 ce417995-dfc9-0310-95a0-acdaff106893
* Fix taskcontext-test: do not use rtt/* headers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6785 ce417995-dfc9-0310-95a0-acdaff106893
* Fix taskcontext-test: duplicate code in header.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6784 ce417995-dfc9-0310-95a0-acdaff106893
* Fix taskcontext-test: not all testfiles were run.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6783 ce417995-dfc9-0310-95a0-acdaff106893
* Updated authors file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6780 ce417995-dfc9-0310-95a0-acdaff106893
* Fix corba + static libraries. +Enable GCC visibility macros.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6779 ce417995-dfc9-0310-95a0-acdaff106893
* Preparing RTT changes document for 1.2.x
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6776 ce417995-dfc9-0310-95a0-acdaff106893
* Fix typo in CMakeLists.txt file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6775 ce417995-dfc9-0310-95a0-acdaff106893
* Added -fvisibility=hidden framework to reduce symbol count in .so files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6773 ce417995-dfc9-0310-95a0-acdaff106893
* Add doxy comment to getName().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6772 ce417995-dfc9-0310-95a0-acdaff106893
* Move code out of template function.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6771 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #362 on 1.2 branch: orocos-rtt.pc file does not list -lpthread
  + Fixed Xenomai specific build and link flags.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6746 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed Xenomai cmake syntax error.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6732 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed Xenomai detection.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6731 ce417995-dfc9-0310-95a0-acdaff106893
* fixed linking problem when building without corba (bug 358)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6703 ce417995-dfc9-0310-95a0-acdaff106893
* Add yield() function to ThreadInterface.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6700 ce417995-dfc9-0310-95a0-acdaff106893
* Fix cmake dependency bug on orocos-rtt-corba.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6696 ce417995-dfc9-0310-95a0-acdaff106893
* Fix minor typo + ubuntu support.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6692 ce417995-dfc9-0310-95a0-acdaff106893
* Guard SET_SOURCE_FILES_PROPERTIES with check if properties need to be set.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6645 ce417995-dfc9-0310-95a0-acdaff106893
* Reset version number to 1.1.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6642 ce417995-dfc9-0310-95a0-acdaff106893
* Fixing Corba flags in pkgconfig file. There is still an awkward bug regarding dependencies between orocos-rtt and orocos-rtt-corba, in which case the former is built before the latter, while that should not happen...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6640 ce417995-dfc9-0310-95a0-acdaff106893
* Fix setting RTT CXX flags, add embedded flags as well.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6638 ce417995-dfc9-0310-95a0-acdaff106893
* Move cmake uninstall file to config dir.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6636 ce417995-dfc9-0310-95a0-acdaff106893
* syncing with orocos-trunk version 6615, resolving bugs 332
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6616 ce417995-dfc9-0310-95a0-acdaff106893
* Fix install path of boost/function_types: it should not be in 'rtt/'.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6615 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong include of '<TaskContext.hpp>'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6614 ce417995-dfc9-0310-95a0-acdaff106893
* Reverted major part of patch r6571: Fix rtt-config.hpp include statements.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6612 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #314: Priority and scheduler of activities.
  Added a constructor to PeriodicActivity and NonPeriodicActivity and *Thread classes which allows to select the scheduler.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6606 ce417995-dfc9-0310-95a0-acdaff106893
* Improved build:
  * Detect gcc version
  * Detect cmake version
  * Embedded OS options
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6605 ce417995-dfc9-0310-95a0-acdaff106893
* added patch for bug 338, in sync now with orocos-trunk revision 6593
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6595 ce417995-dfc9-0310-95a0-acdaff106893
* fix warning int <--> unisgned int
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6581 ce417995-dfc9-0310-95a0-acdaff106893
* fixed typo in TaoIDL and added OROPKG_CORBA define and added corba
  include dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6580 ce417995-dfc9-0310-95a0-acdaff106893
* resolving bug 340 in rtt-1.2 branch
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6579 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #289: Rethink the os/oro\_*.h assembly functions:
  * Bitops files have been removed
  * atomic ops & cmpxchg have oro\_ prefix
  This patch passes 'make check'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6578 ce417995-dfc9-0310-95a0-acdaff106893
* Fix minor errors in testcases.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6577 ce417995-dfc9-0310-95a0-acdaff106893
* Re-applying svn merge -r6552:6553 .: Fix gcc-4.1 crash with too much templates.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6576 ce417995-dfc9-0310-95a0-acdaff106893
* fixed include rtt-config.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6575 ce417995-dfc9-0310-95a0-acdaff106893
* removed obsolete files, fixed includes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6574 ce417995-dfc9-0310-95a0-acdaff106893
* library compiles, some of the tests not
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6573 ce417995-dfc9-0310-95a0-acdaff106893
* rtt-1.2 branch in sync with orocos-trunk revision 6571
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6572 ce417995-dfc9-0310-95a0-acdaff106893
* fixed problem with include of rtt-config.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6571 ce417995-dfc9-0310-95a0-acdaff106893
* updated rtt-branch to orocos trunk revision 6544
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6567 ce417995-dfc9-0310-95a0-acdaff106893
* Build system cleanup:
  * build .so library in src dir
  * Added embedded options
  * Added logger options
  * Doc & Corba file generation cleanup
  * Marshalling includes fixes.
  * Added 'RTT' Build type (mainly required for LXRT).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6554 ce417995-dfc9-0310-95a0-acdaff106893
* Fix gcc-4.1 crash: too much template code.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6553 ce417995-dfc9-0310-95a0-acdaff106893
* added forgotten files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6552 ce417995-dfc9-0310-95a0-acdaff106893
* library compiles, tests not
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6551 ce417995-dfc9-0310-95a0-acdaff106893
* still moving around
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6550 ce417995-dfc9-0310-95a0-acdaff106893
* updating files for compilation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6548 ce417995-dfc9-0310-95a0-acdaff106893
* moving ProgramTask to scripting-dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6547 ce417995-dfc9-0310-95a0-acdaff106893
* removing some duplicated files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6546 ce417995-dfc9-0310-95a0-acdaff106893
* almost in sync with trunk, i'm going to check the .rej manually
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6545 ce417995-dfc9-0310-95a0-acdaff106893
* Remove obsololeted include from RTT.hpp
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6528 ce417995-dfc9-0310-95a0-acdaff106893
* Add DESTDIR support for Orocos 1.2.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6518 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed CORBA build, moved some Marshall* files back to src dir, improved 'make check'.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6515 ce417995-dfc9-0310-95a0-acdaff106893
* Added docbook to html and pdf using cmake.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6514 ce417995-dfc9-0310-95a0-acdaff106893
* Add cmake wrapper configure script.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6220 ce417995-dfc9-0310-95a0-acdaff106893
* Fix TinyXML marshaller building.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6218 ce417995-dfc9-0310-95a0-acdaff106893
* tried a merge, not completely working
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6214 ce417995-dfc9-0310-95a0-acdaff106893
* new name of rtt lib
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6210 ce417995-dfc9-0310-95a0-acdaff106893
* avoid warning
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6209 ce417995-dfc9-0310-95a0-acdaff106893
* threshold to make test succeed
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6208 ce417995-dfc9-0310-95a0-acdaff106893
* new name: liborocos-rtt
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6207 ce417995-dfc9-0310-95a0-acdaff106893
* fixed buffers-test compile bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6093 ce417995-dfc9-0310-95a0-acdaff106893
* uncommenting test that won't build
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6081 ce417995-dfc9-0310-95a0-acdaff106893
* fixing hardcoded os/target include dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6080 ce417995-dfc9-0310-95a0-acdaff106893
* include path for test
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6079 ce417995-dfc9-0310-95a0-acdaff106893
* include and install paths
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6078 ce417995-dfc9-0310-95a0-acdaff106893
* merging rtt-trunk with orocos-trunk
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6077 ce417995-dfc9-0310-95a0-acdaff106893
* Initialized merge tracking via "svnmerge" with revisions "1-5948" from
  https://svn.mech.kuleuven.be:/repos/orocos/orocos-trunk
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6075 ce417995-dfc9-0310-95a0-acdaff106893
* define marshaller fixed
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6074 ce417995-dfc9-0310-95a0-acdaff106893
* removed needed define
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6073 ce417995-dfc9-0310-95a0-acdaff106893
* set some includes right, removed old cdl file, removed obsolete defines
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6071 ce417995-dfc9-0310-95a0-acdaff106893
* fix version number
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6069 ce417995-dfc9-0310-95a0-acdaff106893
* include rtt-config.h in rtt folder
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6066 ce417995-dfc9-0310-95a0-acdaff106893
* fix define
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6065 ce417995-dfc9-0310-95a0-acdaff106893
* added installation of rtt-config.h file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6062 ce417995-dfc9-0310-95a0-acdaff106893
* create all necessary tests for rtt
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6060 ce417995-dfc9-0310-95a0-acdaff106893
* linking problems for tests solved
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6059 ce417995-dfc9-0310-95a0-acdaff106893
* wrong include in taskthread_test is fixed, still trying to get to an optimal build configuration
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6057 ce417995-dfc9-0310-95a0-acdaff106893
* some changes to the configuration (linking flags)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6056 ce417995-dfc9-0310-95a0-acdaff106893
* changed configuration of rtt-config.h.in
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6055 ce417995-dfc9-0310-95a0-acdaff106893
* fix examples. compiles already, but does not link yet
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6051 ce417995-dfc9-0310-95a0-acdaff106893
* fix for tests
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6049 ce417995-dfc9-0310-95a0-acdaff106893
* fixes to test on estimation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6048 ce417995-dfc9-0310-95a0-acdaff106893
* add config folder ;-)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6047 ce417995-dfc9-0310-95a0-acdaff106893
* playing with tests
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6046 ce417995-dfc9-0310-95a0-acdaff106893
* fix for lxrt
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6045 ce417995-dfc9-0310-95a0-acdaff106893
* compiles for gnulinux!!!!!!!!!!!!!!!!!!!!!!!!
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6044 ce417995-dfc9-0310-95a0-acdaff106893
* forgot to commit
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6043 ce417995-dfc9-0310-95a0-acdaff106893
* almost compiling version.. just for backup purposes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6042 ce417995-dfc9-0310-95a0-acdaff106893
* bunch of fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6037 ce417995-dfc9-0310-95a0-acdaff106893
* remove pkgconfig folder
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6035 ce417995-dfc9-0310-95a0-acdaff106893
* perparing for removal of pkgconfig folder
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6034 ce417995-dfc9-0310-95a0-acdaff106893
* and rename... no could not do this after moving from echo. Should have done it at once, but that's too late
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6033 ce417995-dfc9-0310-95a0-acdaff106893
* lost file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6032 ce417995-dfc9-0310-95a0-acdaff106893
* automatic generated include files in pkgconfig, now we have to figure out how to automaticaly generate them with cmake ;)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6030 ce417995-dfc9-0310-95a0-acdaff106893
* rtt-config
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6029 ce417995-dfc9-0310-95a0-acdaff106893
* remove pkgconf
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6028 ce417995-dfc9-0310-95a0-acdaff106893
* stuff
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6027 ce417995-dfc9-0310-95a0-acdaff106893
* new include path
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6026 ce417995-dfc9-0310-95a0-acdaff106893
* add cmake file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6024 ce417995-dfc9-0310-95a0-acdaff106893
* rename
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6018 ce417995-dfc9-0310-95a0-acdaff106893
* add cmakefiles
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6017 ce417995-dfc9-0310-95a0-acdaff106893
* new file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6014 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6008 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6007 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6006 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6005 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6004 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6003 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6002 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6001 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@6000 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5999 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5998 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5997 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5996 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5995 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5994 ce417995-dfc9-0310-95a0-acdaff106893
* new folder
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5993 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5992 ce417995-dfc9-0310-95a0-acdaff106893
* new folder
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5991 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5990 ce417995-dfc9-0310-95a0-acdaff106893
* new dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5989 ce417995-dfc9-0310-95a0-acdaff106893
* remove
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5988 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5987 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5986 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5985 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5984 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5983 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5982 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5981 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5980 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5979 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5978 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5977 ce417995-dfc9-0310-95a0-acdaff106893
* add
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5976 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5975 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5974 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5973 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5972 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5971 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5970 ce417995-dfc9-0310-95a0-acdaff106893
* add dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5969 ce417995-dfc9-0310-95a0-acdaff106893
* remove current
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5968 ce417995-dfc9-0310-95a0-acdaff106893
* stuff
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5967 ce417995-dfc9-0310-95a0-acdaff106893
* move cxx to cpp
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5966 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5965 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5964 ce417995-dfc9-0310-95a0-acdaff106893
* remove
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5963 ce417995-dfc9-0310-95a0-acdaff106893
* remove
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5962 ce417995-dfc9-0310-95a0-acdaff106893
* remove
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5961 ce417995-dfc9-0310-95a0-acdaff106893
* (re)move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5960 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5959 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5958 ce417995-dfc9-0310-95a0-acdaff106893
* move out of current
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5957 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5956 ce417995-dfc9-0310-95a0-acdaff106893
* remove
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5955 ce417995-dfc9-0310-95a0-acdaff106893
* move
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5954 ce417995-dfc9-0310-95a0-acdaff106893
* rename
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5953 ce417995-dfc9-0310-95a0-acdaff106893
* remove stuff
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5952 ce417995-dfc9-0310-95a0-acdaff106893
* rename
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5951 ce417995-dfc9-0310-95a0-acdaff106893
* copy of trunk
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/trunk/rtt@5950 ce417995-dfc9-0310-95a0-acdaff106893
* include boost scoped ptr if necessary and only if appropriate, should fix bug #244
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5948 ce417995-dfc9-0310-95a0-acdaff106893
* Closing bug #115.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5946 ce417995-dfc9-0310-95a0-acdaff106893
* Extend DriveInterface/AxisInterface with getEnable(). Use an 'empty' DigitalOutput when the switch needs to be simulated.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5942 ce417995-dfc9-0310-95a0-acdaff106893
* Allow to specify make CC='distcc gcc-...'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5940 ce417995-dfc9-0310-95a0-acdaff106893
* Document change of bug #201: [API] Rename WriteDataPort class to DataPort.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5939 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #240: cannot find orocos-local.pc
  Don't ask me why it worked here...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5938 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #238: building orocos-trunk fails
  Remove all references to device_drivers package.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5937 ce417995-dfc9-0310-95a0-acdaff106893
* Document bug #188
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5932 ce417995-dfc9-0310-95a0-acdaff106893
* Remove old flags (kernel module, smp, sched_type) from lxrt,xenomai build options.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5891 ce417995-dfc9-0310-95a0-acdaff106893
* Also install pkgconfig/orocos-rtt.pc file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5889 ce417995-dfc9-0310-95a0-acdaff106893
* connectPorts: detect two same-name ports connected to different connection: print warning.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5887 ce417995-dfc9-0310-95a0-acdaff106893
* Remove old flags (kernel module, smp, sched_type) from build gnulinux options.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5886 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup properties: unused files, simple marshalling choices.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5885 ce417995-dfc9-0310-95a0-acdaff106893
* Remove old device drivers template.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5884 ce417995-dfc9-0310-95a0-acdaff106893
* Remove the old device_drivers directory, use orocos-components.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5883 ce417995-dfc9-0310-95a0-acdaff106893
* By default, compile atomic operations with CONFIG_SMP enabled to help the dual core users.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5850 ce417995-dfc9-0310-95a0-acdaff106893
* Include threads.hpp by default such that portable priorities (HighestPriority, LowestPriority,...) become available.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5849 ce417995-dfc9-0310-95a0-acdaff106893
* More informative .cdl package description.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5844 ce417995-dfc9-0310-95a0-acdaff106893
* Fix memleak in Type sytem.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5843 ce417995-dfc9-0310-95a0-acdaff106893
* Fix DataObject memleak, lower ConnectionFactory logging info to 'Debug'.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5842 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #115: [Project] Move device drivers to orocos-components
  * Move utility classes Digital* and Analog* to device_interface
  * Add DriveInterface class
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5841 ce417995-dfc9-0310-95a0-acdaff106893
* Update templates to no longer use signal-processing package.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5840 ce417995-dfc9-0310-95a0-acdaff106893
* Addition to bug #210: update documentation & includes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5839 ce417995-dfc9-0310-95a0-acdaff106893
* Addition to bug #210: remove empty files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5838 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #210: Remove ZTT and friends:
  * PeriodicThread/SingleThread are now ORO_SCHED_RT by default except in gnulinux.
  * add setScheduler, getScheduler and setPriority to ThreadInterface
  * The fosi_internal was adapted to match these functions
  * Remove corelib ZTThread, ZLThread, NRTThread and NPActivity PActivity, NRTActivity.
  * Thus use PeriodicActivity and NonPeriodicActivity
  * Remove Hard-coded thread-scope dependencies
  * Various documentation updates in OS and CoreLib.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5837 ce417995-dfc9-0310-95a0-acdaff106893
* Remove old 'doc' targets.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5836 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug 234: XML Parsing: DTD's and Parsers.
  * Xerces no longer depends on presence of cpf.dtd
  * Add cpf.dtd as const char* in the code.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5835 ce417995-dfc9-0310-95a0-acdaff106893
* See bug #231: Remove signal_processing from orocos-trunk. Will be added later to orocos-components.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5825 ce417995-dfc9-0310-95a0-acdaff106893
* Remove empty-box 'math' package.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5824 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #193: testtimeprogress fails on rtai-3.3-cv linux 2.6.16.28
  Remove test that handles rounding incorrectly.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5789 ce417995-dfc9-0310-95a0-acdaff106893
* removing geometry and kinematics_dynamics from orocos-trunk. From now
  on we will use the new released KinDyn Library.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5788 ce417995-dfc9-0310-95a0-acdaff106893
* Fix warning: overflow in implicit constant conversion.
  => Declare PSECS_IN_SECS as 'long long'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5781 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #204: reading properties does not fail.
  Extend the semantics of the Marshalling/PropertyLoader such that
  all, some or one property is read from or written to a file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5780 ce417995-dfc9-0310-95a0-acdaff106893
* Remove empty can directory.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5779 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #217: error when compiling orocos-trunk with corba support.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5775 ce417995-dfc9-0310-95a0-acdaff106893
* Krypton is now in orocos-components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5762 ce417995-dfc9-0310-95a0-acdaff106893
* Fix+testcase for bug #200: Property of unsigned int.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5761 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #212, add picoseconds support to orocos. Part 2
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5759 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #212, add picoseconds support to orocos
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5758 ce417995-dfc9-0310-95a0-acdaff106893
* Patched acinclude.m4 manually in response to bug #190. Part 3.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5755 ce417995-dfc9-0310-95a0-acdaff106893
* Patched acinclude.m4 manually in response to bug #190. Part 2.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5754 ce417995-dfc9-0310-95a0-acdaff106893
* Patched acinclude.m4 manually in response to bug #190.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5753 ce417995-dfc9-0310-95a0-acdaff106893
* remove unused counter code
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5746 ce417995-dfc9-0310-95a0-acdaff106893
* Pretty pictures documentation, requires Java Jimi though.
  + Added FrameworkOverview.svg, improved ApplicationStack.svg
  + README explaining the make targets/files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5745 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation Fixes for SimulationAxis, see http://lists.mech.kuleuven.be/pipermail/orocos-dev/2006-September/002346.html
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5744 ce417995-dfc9-0310-95a0-acdaff106893
* fix typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5741 ce417995-dfc9-0310-95a0-acdaff106893
* Add 'docs' target to top level doc Makefile.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5718 ce417995-dfc9-0310-95a0-acdaff106893
* Add Makefile.am for XML doc generation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5717 ce417995-dfc9-0310-95a0-acdaff106893
* Remove deprecated doc.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5709 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation relocation effort.
  Move all Docbook-xml files to doc/xml and the
  images to doc/xml/images. A simple 'make docs'
  now builds all the manuals.
  All package 'doc' dirs have been removed.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5708 ce417995-dfc9-0310-95a0-acdaff106893
* Corba Data Ports, part II
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5696 ce417995-dfc9-0310-95a0-acdaff106893
* Corba Data Ports. Connect buffered and unbuffered Ports over a network.
  It works, but it remains as an 'extra' for the adventurous.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5695 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compile error in DataSourceAdaptor. Make ValueDataSource and ReferenceDataSource constructible on stack as well.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5694 ce417995-dfc9-0310-95a0-acdaff106893
* Fix typo in Doxygen comment.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5693 ce417995-dfc9-0310-95a0-acdaff106893
* Use Logger to print warnings.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5692 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #205: [API] Deprecate GenericTaskContext, upgrade TaskContext
  * Add execution()/engine(), marshalling() and scripting() members to TaskContext interface
  * Add clear() function to TaskContext to clear the dynamical interface (methods, commands,...)
  * Improved documentation on 'various places'.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5691 ce417995-dfc9-0310-95a0-acdaff106893
* Only omit priority test if GNULINUX && SCHED_OTHER
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5690 ce417995-dfc9-0310-95a0-acdaff106893
* Small docu update on connecting ports.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5689 ce417995-dfc9-0310-95a0-acdaff106893
* Be less strict with priorities in the gnu/linux case.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5688 ce417995-dfc9-0310-95a0-acdaff106893
* Test new DataPort type.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5687 ce417995-dfc9-0310-95a0-acdaff106893
* Figure linking 'activity' to 'execution engine' to 'processors' and 'update'.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5686 ce417995-dfc9-0310-95a0-acdaff106893
* Second try at fixing bug #198: use the new connectTo() implementation of PortInterface.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5683 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #198: also connect two read ports.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5682 ce417995-dfc9-0310-95a0-acdaff106893
* Improving the DataFlow and Port interfaces with regard to
  bugs #201 and #198.
  * Renamed WriteDataPort to DataPort and created a 'Write only' WriteDataPort
  * Better documentation of interface
  * Improved the aport->connectTo( bport ) semantics: will try very hard to
  connect aport and bport, even if both are readers.
  * Allow to set the implementation of a port's connection for both
  DataConnection and BufferConnection objects.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5681 ce417995-dfc9-0310-95a0-acdaff106893
* API documentation limitDrive
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5679 ce417995-dfc9-0310-95a0-acdaff106893
* remove unused header
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5669 ce417995-dfc9-0310-95a0-acdaff106893
* remove unused header
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5668 ce417995-dfc9-0310-95a0-acdaff106893
* doxygendocument axis and friend classes, so they show up at least up in API documentation, fix indentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5667 ce417995-dfc9-0310-95a0-acdaff106893
* Update namespace CAN => RTT::CAN, bug #65.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5663 ce417995-dfc9-0310-95a0-acdaff106893
* Rename bool update() to bool execute(), see bug #199.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5661 ce417995-dfc9-0310-95a0-acdaff106893
* Make TaskContext functions virtual such that they can be overridden by user code.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5660 ce417995-dfc9-0310-95a0-acdaff106893
* Add ready() and getDataSource() methods to MethodC class.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5659 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug: Number of threads: start counting from zero or 1?
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5654 ce417995-dfc9-0310-95a0-acdaff106893
* try to fix bug #197
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5645 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #196 + fix indentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5643 ce417995-dfc9-0310-95a0-acdaff106893
* more fixes for bug 157, remove unused cdl defines
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5642 ce417995-dfc9-0310-95a0-acdaff106893
* use new location
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5632 ce417995-dfc9-0310-95a0-acdaff106893
* Bump version number to 0.25.1
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5625 ce417995-dfc9-0310-95a0-acdaff106893
* Fix additional Doxygen links.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5620 ce417995-dfc9-0310-95a0-acdaff106893
* Fix Doxygen link for TaskBrowser until TaskBrowser component is
  on the web as well.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5619 ce417995-dfc9-0310-95a0-acdaff106893
* * Add _default_POA() methods to all servants.
  * Extend ScriptingAccess to track status of commands which were execute()'d.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5618 ce417995-dfc9-0310-95a0-acdaff106893
* Add Hello World figure.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5617 ce417995-dfc9-0310-95a0-acdaff106893
* Fix not using of detected CXXFLAGS in OS layer.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5616 ce417995-dfc9-0310-95a0-acdaff106893
* Improved version of DLibCommand, use a ProtocolT to transfer data.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5615 ce417995-dfc9-0310-95a0-acdaff106893
* remove obsolete code, part 2
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5614 ce417995-dfc9-0310-95a0-acdaff106893
* remove obsolete code
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5613 ce417995-dfc9-0310-95a0-acdaff106893
* Add missing RTT namespace.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5612 ce417995-dfc9-0310-95a0-acdaff106893
* remove svn:ignore property.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5611 ce417995-dfc9-0310-95a0-acdaff106893
* Remove dead Reporting code.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5608 ce417995-dfc9-0310-95a0-acdaff106893
* Document 'global' Orocos namespace.'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5607 ce417995-dfc9-0310-95a0-acdaff106893
* Document RTT::Corba namespace.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5606 ce417995-dfc9-0310-95a0-acdaff106893
* Move rt_std namespace into RTT::rt_std
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5605 ce417995-dfc9-0310-95a0-acdaff106893
* * Add Orb threading
  * Fix last Corba issues wrt orb shutdown
  * Fix statement processor return values and error reporting.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5602 ce417995-dfc9-0310-95a0-acdaff106893
* Wipe Control Kernel from the face of the earth.
  Fixes bug #39
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5598 ce417995-dfc9-0310-95a0-acdaff106893
* Fix generation of IDL files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5597 ce417995-dfc9-0310-95a0-acdaff106893
* Minor updates.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5596 ce417995-dfc9-0310-95a0-acdaff106893
* Finish CORBA-fixup to new Component interfaces:
  * Put Corba classes in namespace RTT::Corba instead of Orocos namespace
  * Rename Factories to OperationInterface
  * Rename Execution to Operations
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5595 ce417995-dfc9-0310-95a0-acdaff106893
* Add Distribution Library header for Commands.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5594 ce417995-dfc9-0310-95a0-acdaff106893
* Fixup inkscape png generation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5593 ce417995-dfc9-0310-95a0-acdaff106893
* Remove HB from copyrights, add FMTC.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5590 ce417995-dfc9-0310-95a0-acdaff106893
* Fix warning in makefile.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5587 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes for bug #188: [API] Commands: evaluate() deprecated, use done()
  And testcase for bug #182: Stand-alone ExecutionEngine.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5586 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #182: Make owner optional in constructor.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5585 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #182: Stand-alone ExecutionEngine
  Fix crash on application shutdown.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5584 ce417995-dfc9-0310-95a0-acdaff106893
* Corba layer actually compiles again.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5583 ce417995-dfc9-0310-95a0-acdaff106893
* Fix path to rtt/corba/
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5582 ce417995-dfc9-0310-95a0-acdaff106893
* Bug #186: Deprecate EventDrivenActivity : remove docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5581 ce417995-dfc9-0310-95a0-acdaff106893
* Related to bug #188: Deprecate evaluate(), use done().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5580 ce417995-dfc9-0310-95a0-acdaff106893
* Documented OperationFactory.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5579 ce417995-dfc9-0310-95a0-acdaff106893
* Added vim syntax highliting file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5576 ce417995-dfc9-0310-95a0-acdaff106893
* Start compiling CORBA again...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5575 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #158:addPeer connection direction:
  * addPeer and connectPeers only setup "Execution Flow"
  * connectPorts is used to setup "Data Flow", ie connect data ports.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5574 ce417995-dfc9-0310-95a0-acdaff106893
* Small typo fixes in the component builder's manual.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5573 ce417995-dfc9-0310-95a0-acdaff106893
* Added initial Component Deployment section.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5571 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bugs #184:Execution Engine does not process Events in 'non periodic' activities
  and fix bug #182:Stand-alone ExecutionEngine.
  * ExecutionEngine: 'parent' is optional now
  * All Processors: use new 'trigger/update' semantics to have more efficient implementation.
  * Adapt the tests to the more restrictive EventProcessor.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5570 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup old 'Template*'/'Factory*' files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5569 ce417995-dfc9-0310-95a0-acdaff106893
* Updates on documentation execution flow/data flow connection, WIP.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5568 ce417995-dfc9-0310-95a0-acdaff106893
* Minor doc updates and rename _task_name to mtask_name.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5567 ce417995-dfc9-0310-95a0-acdaff106893
* Fix indentation of SingleThread.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5566 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #185: [API] Breaking ActivityInterface trigger() and update()
  Beware to rename all use of activity->trigger() to activity->update()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5565 ce417995-dfc9-0310-95a0-acdaff106893
* Import patch of peter.soetens@gmail.com: Add support for tinyxml.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5564 ce417995-dfc9-0310-95a0-acdaff106893
* Move TaskIntro to task-intro package. Add new drawings for TaskCore/TaskContext interfaces.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5562 ce417995-dfc9-0310-95a0-acdaff106893
* Add missing links
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5559 ce417995-dfc9-0310-95a0-acdaff106893
* New caveats document for Orocos 0.25.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5558 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes for bug #168 and bug #164.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5550 ce417995-dfc9-0310-95a0-acdaff106893
* Avoid duplicate names for .dia files, as this breaks the doc-generation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5541 ce417995-dfc9-0310-95a0-acdaff106893
* Doxy updates: Use @par instead of @section in class docs.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5540 ce417995-dfc9-0310-95a0-acdaff106893
* Detect wrong arity in addEvent, addMethod,... methods using BOOST_STATIC_ASSERT.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5538 ce417995-dfc9-0310-95a0-acdaff106893
* Minor fixes to experimental RemoteCommand.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5537 ce417995-dfc9-0310-95a0-acdaff106893
* Improved various manuals:
  * Add notion of Commands to corelib
  * Fix new parser syntax 'emit' --> 'do'
  * Replace 'task-intro' by 'Hello World' example
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5535 ce417995-dfc9-0310-95a0-acdaff106893
* Adapt tests to various API changes in both C++ and scripting.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5534 ce417995-dfc9-0310-95a0-acdaff106893
* Set Logger::In module to task's name when executing ExectionEngine.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5533 ce417995-dfc9-0310-95a0-acdaff106893
* Return a const& string in getName() and getDescription().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5532 ce417995-dfc9-0310-95a0-acdaff106893
* Limit use of Logger::In in order not to spoil global Logger context.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5531 ce417995-dfc9-0310-95a0-acdaff106893
* Fix crash upon value assignment created by ValueChangeParser.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5527 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug# 162: Improve ExecutionEngine: Policies and Implementations.
  Applies as wel to bug# 160: Renaming getExecutionEngine(), getCommandProcessor(),...
  * The EE has been slimmed down and is now simpeler in 'shared' use.
  * One can set the EE and all processors on a per component basis.
  * It is possible to disable each 'kind' of processor in the final build in order
  to reduce code size (experimental).
  * Improve Doxygen documentation about EE policies.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5526 ce417995-dfc9-0310-95a0-acdaff106893
* Rename Command::evaluate() to Command::done().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5525 ce417995-dfc9-0310-95a0-acdaff106893
* Add dependency upon Event system.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5524 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #165: OS::PeriodicThread depends on RTT::Event, CompletionProcessor.
  Change the implementation of setToStop().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5523 ce417995-dfc9-0310-95a0-acdaff106893
* Small doxygen update.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5522 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: compile exception handler upon OROBLD_OS_NOEXCEPTIONS, not upon OROBLD_EMBEDDED.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5521 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug# 163: recognise more cpf types.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5520 ce417995-dfc9-0310-95a0-acdaff106893
* Remove no longer needed include.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5519 ce417995-dfc9-0310-95a0-acdaff106893
* Testcase for bug #161.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5518 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #161: BufferPort:: Push() / Pull() broken
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5517 ce417995-dfc9-0310-95a0-acdaff106893
* Finish fix for deployment: do not connectTo() if connected().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5516 ce417995-dfc9-0310-95a0-acdaff106893
* quick fix for bug 157
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5512 ce417995-dfc9-0310-95a0-acdaff106893
* Partial fix for deployment.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5510 ce417995-dfc9-0310-95a0-acdaff106893
* fix log message
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5503 ce417995-dfc9-0310-95a0-acdaff106893
* combine setLimitDriveEvent and limitDrive methods into one new method
  limitDrive. Api changed
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5472 ce417995-dfc9-0310-95a0-acdaff106893
* enable lower and higher drive limits check
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5471 ce417995-dfc9-0310-95a0-acdaff106893
* new makefile
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5470 ce417995-dfc9-0310-95a0-acdaff106893
* List 'this' as TaskObject as well.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5469 ce417995-dfc9-0310-95a0-acdaff106893
* Corrected initialisation of shared pointer in Event.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5468 ce417995-dfc9-0310-95a0-acdaff106893
* Make Processors optional in ExecutionEngine +
  Allow to set a processor in order to change the policy.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5467 ce417995-dfc9-0310-95a0-acdaff106893
* Corrected initialisation of shared pointers in Method class.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5466 ce417995-dfc9-0310-95a0-acdaff106893
* Reworking the TaskContext manual:
  * Preparing to move out the taskintro example
  * Must replace it by Hello World example.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5465 ce417995-dfc9-0310-95a0-acdaff106893
* Scripting Improvement, related to bug #140:
  * Drop 'emit' keyword and use 'do' to invoke events.
  * Drop 'task.' prefix when addressing task properties:
  script variables may no longer clash with task variables.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5464 ce417995-dfc9-0310-95a0-acdaff106893
* Fix eventservice tests
  Fix accidental removal of most tests from testsuite
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5444 ce417995-dfc9-0310-95a0-acdaff106893
* Possible fix for bug #156: Print error messages when getX<T>(name) is failing.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5443 ce417995-dfc9-0310-95a0-acdaff106893
* Possible fix for bug #155: g++-3.3.5 does not compile 'signal_template.hpp'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5437 ce417995-dfc9-0310-95a0-acdaff106893
* Implement copy constructor, or gcc starts whining about my code.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5429 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup dependencies from corelib on execution.
  Header files are moved from execution to corelib.
  EventDrivenActivity has been moved from activities to events.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5424 ce417995-dfc9-0310-95a0-acdaff106893
* Add Event firing support to the TaskBrowser and the Command
  'do' statements.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5423 ce417995-dfc9-0310-95a0-acdaff106893
* In case you tried to compile the previous revision...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5405 ce417995-dfc9-0310-95a0-acdaff106893
* Removed deprecated interface classes. If someone complains, we'll put them back.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5404 ce417995-dfc9-0310-95a0-acdaff106893
* Renamed 'struct's to 'class' in order to get better Doxygen docs.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5403 ce417995-dfc9-0310-95a0-acdaff106893
* Fix images: remove absolute paths from svg files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5402 ce417995-dfc9-0310-95a0-acdaff106893
* The closing patch for the TaskContext API refactoring:
  * Removing obsoleted 'Factory' files
  * Revamped the Event<T> interface and implementation
  * Updated the corelib/taskcontext manuals
  * Installed a 'signature' preprocessor template to generate easier N-arity template classes
  * Documentation updates
  * Saved some memory in the Method implementation, using shared_ptr.
  * Fixed bug in addMethod(), not adding to C++ interface
  * Added multiple testcases, checking types, constructors, commands and methods
  * Reworked the events testcases to use the new API.
  * Moved 'signal' stuff from namespace sigslot to namespace RTT
  * 'handle' has been renamed to Handle and the old Handle is removed.
  * Adapt 'Axis' class to new Event interface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5397 ce417995-dfc9-0310-95a0-acdaff106893
* Added an addDataObject method to the AttributeRepository in order to replace MapDataSourceFactory.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5396 ce417995-dfc9-0310-95a0-acdaff106893
* Log valid info when creating a Constant.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5385 ce417995-dfc9-0310-95a0-acdaff106893
* Additional command const& args tests.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5376 ce417995-dfc9-0310-95a0-acdaff106893
* Turn off experimental command remoting.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5375 ce417995-dfc9-0310-95a0-acdaff106893
* small update for C++ command args tests.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5374 ce417995-dfc9-0310-95a0-acdaff106893
* Possible fix for bug #139 (most likely) and bug #143 (maybe).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5373 ce417995-dfc9-0310-95a0-acdaff106893
* Namespace/Modules documentation update.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5343 ce417995-dfc9-0310-95a0-acdaff106893
* Correct svn version number for nightly builds.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5342 ce417995-dfc9-0310-95a0-acdaff106893
* version 0.25.0-devel1
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5339 ce417995-dfc9-0310-95a0-acdaff106893
* version 0.25.0-devel1
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5338 ce417995-dfc9-0310-95a0-acdaff106893
* Omit 'author' from front page of manuals
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5337 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation fixes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5306 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation fixes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5305 ce417995-dfc9-0310-95a0-acdaff106893
* Fix related to bug #129: CompletionProcessor must be a BlockingEventProcessor.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5277 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #129: Removing Events out of activities
  * All setup/connect methods only take an EventProcessor and no
  longer a ThreadInterface or ActivityInterface
  * The CompletionProcessor is both an EventProcessor and a
  NonPeriodicActivity
  In order to emulate old behaviour, inherit from EventProcessor or
  BlockingEventProcessor or add such an object as a member to your class.
  Then pass the appropriate pointer to the Event setup/connect methods.
  Finally invoke on your EventProcessor step() to process a single event
  or loop() to wait for events.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5276 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #130:
  * Add a common MainThread class which calls the fosi_internal
  functions rtos_task_create_main(RTOS_TASK*) and
  rtos_task_delete_main(RTOS_TASK*)
  * Clean up old files along the way
  * Set all namespaces correctly to RTT::OS
  * The MainThread singleton is instantiated in startstop.cxx
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5275 ce417995-dfc9-0310-95a0-acdaff106893
* Remove empty directory.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5274 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #134: Crash in TaskContext destructor when state machines and functions are used.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5271 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #132: Make build system respect the use of --includedir= and --libdir='
  From Ben Gardiner
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5258 ce417995-dfc9-0310-95a0-acdaff106893
* Possible fix for bug #131: problem compiling orocos-components on lxrt with g++-3.3.5
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5250 ce417995-dfc9-0310-95a0-acdaff106893
* Make Attribute<T>(AttributeBase*) constructor more acceptive.
  Make DataObjects standard not reference counted such that they
  behave more like Buffers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5224 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen updates, Do not use 'extern template' in embedded systems.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5222 ce417995-dfc9-0310-95a0-acdaff106893
* Missing file for bug #128.
  I need to take a patent on this.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5206 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #128: [Project] Toolkit: add arbitrary constructors for use in scripting.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5203 ce417995-dfc9-0310-95a0-acdaff106893
* Started re-documenting RTT namespace using Doxygen 'modules'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5202 ce417995-dfc9-0310-95a0-acdaff106893
* Added getPortType() method to PortInterface.
  Cleanup of DataObject constructor. It still has a getName(),
  pondering about it if it should remain or disapear.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5201 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup files. execution/DataSource.hpp is superfluous in the 'rtt' system.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5198 ce417995-dfc9-0310-95a0-acdaff106893
* By default, do not use -DNDEBUG when doing gnulinux.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5197 ce417995-dfc9-0310-95a0-acdaff106893
* Add 'trigger'/'update' support for simulation activities.
  This allows a TaskContext, which is run by a simulation activity,
  to be 'update()'ed and hence be executed step by step.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5196 ce417995-dfc9-0310-95a0-acdaff106893
* Investigating bug #126: testcase for invoking same command multiple times.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5195 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #126: create dispatched command.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5194 ce417995-dfc9-0310-95a0-acdaff106893
* Missing file for previous commit.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5192 ce417995-dfc9-0310-95a0-acdaff106893
* Possible fix for bug #126 and a sh*tload of others.
  The scripting was not properly adapted to the new Command implementation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5191 ce417995-dfc9-0310-95a0-acdaff106893
* Added/Adapted test for new Attribute syntax.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5187 ce417995-dfc9-0310-95a0-acdaff106893
* Added/Adapted test for new Attribute syntax.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5186 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug#127: Orocos-trunk does not compile with gcc-3.3
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5182 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for bug #119: Improve Attribute/Property usage
  Attributes get a name upon construction.
  Allow (but also check for) uninitialised Attribute objects.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5165 ce417995-dfc9-0310-95a0-acdaff106893
* RTT is 'used' in the Orocos namespace.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5164 ce417995-dfc9-0310-95a0-acdaff106893
* Add ready() method at various places in order to get a uniform API.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5163 ce417995-dfc9-0310-95a0-acdaff106893
* Code to allow 'mirroring' of properties, see bug #119.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5162 ce417995-dfc9-0310-95a0-acdaff106893
* Add ready() method in order to uniform the API.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5161 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #116, superfluous std::fixed statement
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5149 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for project #65: new Orocos namespace:
  moved CAN stuff to RTT::CAN namespace and headers from can/ to rtt/can.
  The device drivers need clearly to leave the orocos-trunk and go into
  orocos-components...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5148 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for Project #65: Convert Orocos to the RTT namespace.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5147 ce417995-dfc9-0310-95a0-acdaff106893
* Patch for Project #104: Commands and Methods : Away with the Template* classes
  The TaskContext interface has been changed to the 'CommandRepository' and 'MethodRepository'
  for commands and methods. Use the commands.pl script to convert your app.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5146 ce417995-dfc9-0310-95a0-acdaff106893
* Final patch for closing bug #66: Refactoring Logger.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5145 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #114
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5135 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #113: put Property templates in ORO_CoreLib namespace.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5130 ce417995-dfc9-0310-95a0-acdaff106893
* Accidentally forgot to add ActionInterface in previous commit.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5118 ce417995-dfc9-0310-95a0-acdaff106893
* Improve Command<Sig> and Method<Sig> implementations to allow
  remote commands and methods and 'simple' storage in the OperationInterface.
  Retrieval is done with getCommand(name) and getMethod(name).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5115 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #96, but not confirmed for correctness.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5114 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes for bug #112: Problems compiling with the gcc-4.1 suite
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5104 ce417995-dfc9-0310-95a0-acdaff106893
* Fix BindStorage for g++ 3.X compilers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5100 ce417995-dfc9-0310-95a0-acdaff106893
* Added method() and command() free functions for Method and Command creation.
  Documentation updates.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5099 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #109: the "It only gets uglier patch."
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5095 ce417995-dfc9-0310-95a0-acdaff106893
* Generate 'Makefile' in srcdir.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5094 ce417995-dfc9-0310-95a0-acdaff106893
* Bump version number to 0.25.0-devel0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5093 ce417995-dfc9-0310-95a0-acdaff106893
* Added TaskCore, Bugzilla project #102.
  The TaskCore uses 'Command<T>' and 'Method<T>' objects to define commands and methods.
  In this patch, the use of these objects is complementary to the TemplateFactory approach.
  In future patches, the TemplateFactory will be deprecated in favour of this new approach.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5090 ce417995-dfc9-0310-95a0-acdaff106893
* Small usability fixes, add list() overload for getting names in bag.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5089 ce417995-dfc9-0310-95a0-acdaff106893
* Do not print error message, but print (type name) upon write().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5067 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #108: Add linux include path in .pc file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5053 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #107: s/periodset/setperiod/
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5044 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #103: corelib::types does not exist
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5043 ce417995-dfc9-0310-95a0-acdaff106893
* Add two tests to check getPriority and getPeriod from a PeriodicThread
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5042 ce417995-dfc9-0310-95a0-acdaff106893
* refix bug #106 (tested this time :-), uninitialized variable problem
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5041 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #106: lxrt make check fails wrt priority.
  This patch sets also the POSIX priority 'more correctly', upon
  thread creation, a rtos_set_priority() (unused in Orocos) is not
  correct wrt POSIX, but should work for LXRT.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5040 ce417995-dfc9-0310-95a0-acdaff106893
* refix bug #6, formerly solved in r4605, regression introduced by fosi patch in r4714
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5039 ce417995-dfc9-0310-95a0-acdaff106893
* Auto-reset on execute if command was done (bug #105)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5037 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #100: TaskBrowser does not list properties.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5036 ce417995-dfc9-0310-95a0-acdaff106893
* Addition related to bug #84: By default, compile with -O2 for all OS's.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5034 ce417995-dfc9-0310-95a0-acdaff106893
* fix regression introduced by r5024.  This should solve bug 97 and 99
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5032 ce417995-dfc9-0310-95a0-acdaff106893
* try to fix bug #97
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5024 ce417995-dfc9-0310-95a0-acdaff106893
* Fix missing </section>.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5014 ce417995-dfc9-0310-95a0-acdaff106893
* Fix Attribute<Frame> compile error.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5010 ce417995-dfc9-0310-95a0-acdaff106893
* Add the NO-WARRANTY file to the dist package.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5004 ce417995-dfc9-0310-95a0-acdaff106893
* Update new files with license information (LGPL)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5003 ce417995-dfc9-0310-95a0-acdaff106893
* Updated ports() and attributes()/properties() docs of TC.
  Added more natural interface to properties() from the TC, returns the PropertyBag.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4997 ce417995-dfc9-0310-95a0-acdaff106893
* More informative Logger messages for Port connection.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4995 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #95, remove deprecated device driver
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4988 ce417995-dfc9-0310-95a0-acdaff106893
* Distribute CORBA package for release.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4984 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #85: device drivers not in sync with trunk
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4974 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong reference to CANPieController.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4970 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #90: Only load GeometryToolkit if package is available.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4969 ce417995-dfc9-0310-95a0-acdaff106893
* Finishing off the type system:
  * Properties and Attributes ask Type system to build data sources
  * AttributeRepository interface change: addAttribute is now analogous to addProperty
  * Properties are now fully supported in the parser (bug #89 )
  * CORBA uses same system to relyably rebuild properties and attributes in proxy
  * RealTime Toolkit: std::vector<double> looses its const& mark
  * Assignment of DS: convert rhs to value or const&, depending on boost::call_traits,
  currently, 'classes' and 'double' are passed by const&, while int, float,... are passed by value.
  This is why the RTT change of std::vector and std::string is allowed.
  * RealTime Toolkit: std::string looses its const& mark
  * This patch should fix bug #92 as well
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4968 ce417995-dfc9-0310-95a0-acdaff106893
* Update installer with new versions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4966 ce417995-dfc9-0310-95a0-acdaff106893
* Remove author from front page.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4965 ce417995-dfc9-0310-95a0-acdaff106893
* Do not compile LXRT's fosi.c file with -O3
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4962 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #88: applications do not compile anymore if ports are included
  Added testcase as well to avoid future embarrassments.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4958 ce417995-dfc9-0310-95a0-acdaff106893
* Test also std::vector<double> method arguments and ret values.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4957 ce417995-dfc9-0310-95a0-acdaff106893
* Test some more variable creation locations in search for bug #86.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4956 ce417995-dfc9-0310-95a0-acdaff106893
* Fix clone()/antiClone(): use prefered buffer size.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4951 ce417995-dfc9-0310-95a0-acdaff106893
* Remove piece of code that caused bugs #87 and #82: merge this another time.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4948 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #82: Reading Properties does not work anymore
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4939 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #83: KryptonDriver configuration not in sync with trunk
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4938 ce417995-dfc9-0310-95a0-acdaff106893
* Various header fixes after 'make check-headers'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4937 ce417995-dfc9-0310-95a0-acdaff106893
* Replace std::cout messages with Logger
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4934 ce417995-dfc9-0310-95a0-acdaff106893
* Class to add only type name to type system.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4933 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #80: Add missing include files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4931 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #80: compile error with latest trunk and gcc 4.0.3
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4929 ce417995-dfc9-0310-95a0-acdaff106893
* Fix XML manuals wrt Xi:include
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4928 ce417995-dfc9-0310-95a0-acdaff106893
* Add virtual destructor.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4927 ce417995-dfc9-0310-95a0-acdaff106893
* Detect comedi as well in the standard include path.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4924 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #76: RecusiveMutex creating two mutex'es
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4922 ce417995-dfc9-0310-95a0-acdaff106893
* Anticipate null pointers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4921 ce417995-dfc9-0310-95a0-acdaff106893
* Remove debugging code.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4920 ce417995-dfc9-0310-95a0-acdaff106893
* C++ Streams cleanup.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4919 ce417995-dfc9-0310-95a0-acdaff106893
* Add conversion from Assignable value to Assignable const& DS.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4918 ce417995-dfc9-0310-95a0-acdaff106893
* Distantiate between HAVE_IOSTREAM and HAVE_STREAMS.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4917 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compile error, added include <exceptions>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4916 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compile error when disabling Logger
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4915 ce417995-dfc9-0310-95a0-acdaff106893
* Added ORO_EMBEDDED flags to createDataSources()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4911 ce417995-dfc9-0310-95a0-acdaff106893
* Fix clientside segfault when invoking a void method
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4907 ce417995-dfc9-0310-95a0-acdaff106893
* Fix serverside segfault upon shutdown
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4906 ce417995-dfc9-0310-95a0-acdaff106893
* Toolkits: autoload Geometry toolkit
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4904 ce417995-dfc9-0310-95a0-acdaff106893
* Updated news from branches.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4891 ce417995-dfc9-0310-95a0-acdaff106893
* Added type system / toolkit docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4878 ce417995-dfc9-0310-95a0-acdaff106893
* RTT: display bool as 'true' or 'false'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4868 ce417995-dfc9-0310-95a0-acdaff106893
* Fix value() implementation of most adaptors.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4867 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed pkg-config not handling 'URL' field. Improved comedi detection.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4866 ce417995-dfc9-0310-95a0-acdaff106893
* Revert patch 4864: wrong commit.
  Used: svn merge -r4864:4863 .
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4865 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed pkg-config not handling 'URL' field. Improved comedi detection.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4864 ce417995-dfc9-0310-95a0-acdaff106893
* Fix segfault upon trigger() with no activity set.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4860 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug 77
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4858 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug #78: do DataPort.Set( value) in scipts does not work
  The parser did not recognize 'data sources' in 'do' statements.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4857 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug 74
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4850 ce417995-dfc9-0310-95a0-acdaff106893
* fix typos
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4848 ce417995-dfc9-0310-95a0-acdaff106893
* Create a 'local' orocos.pc file for non-installable builds.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4847 ce417995-dfc9-0310-95a0-acdaff106893
* Fix TaskBrowser::disconnect() and DataFlowInterface::removePort()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4846 ce417995-dfc9-0310-95a0-acdaff106893
* task/activity and other small fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4845 ce417995-dfc9-0310-95a0-acdaff106893
* Add pkgconfig support to Orocos build system: generate orocos-'target'.pc file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4829 ce417995-dfc9-0310-95a0-acdaff106893
* Include frames.h for convenience.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4828 ce417995-dfc9-0310-95a0-acdaff106893
* Semantic change of operator<< :
  * print 'DataSource::value()' instead of 'DataSource::get()'
  * TaskBrowser must first 'evaluate()' a data source, then print it.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4827 ce417995-dfc9-0310-95a0-acdaff106893
* Marshalling requires exceptions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4826 ce417995-dfc9-0310-95a0-acdaff106893
* task --> activity
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4825 ce417995-dfc9-0310-95a0-acdaff106893
* Improvements on Error reporting and handling.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4824 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #73: Control Kernel parsing does not work anymore
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4822 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #71: No destructor for Logger when logging is disabled.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4819 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #71: No destructor for Logger when logging is disabled.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4817 ce417995-dfc9-0310-95a0-acdaff106893
* Update apci drivers to Activity naming
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4812 ce417995-dfc9-0310-95a0-acdaff106893
* Optimize for execution: use -O3
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4809 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for bug 69: work around gcc-3.3 bug.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4806 ce417995-dfc9-0310-95a0-acdaff106893
* modified some tests such that they can work with the ORO_EMBEDDED flag.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4804 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed corba related compilation bugs.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4803 ce417995-dfc9-0310-95a0-acdaff106893
* Added bool DispatchInterface::dispatch().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4802 ce417995-dfc9-0310-95a0-acdaff106893
* Fix possible crash when logging is used.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4786 ce417995-dfc9-0310-95a0-acdaff106893
* Fix crash when wrong assignment of a property happens.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4785 ce417995-dfc9-0310-95a0-acdaff106893
* Fix Logger memleak: delete 'd' pointer upon cleanup.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4784 ce417995-dfc9-0310-95a0-acdaff106893
* Add (void) type to DataSourceTypeInfo.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4783 ce417995-dfc9-0310-95a0-acdaff106893
* Fix memleak: delete EventProcessor.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4782 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong #ifdef.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4772 ce417995-dfc9-0310-95a0-acdaff106893
* Added documentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4767 ce417995-dfc9-0310-95a0-acdaff106893
* Fix undefined variable error
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4765 ce417995-dfc9-0310-95a0-acdaff106893
* Add the RTT namespace.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4764 ce417995-dfc9-0310-95a0-acdaff106893
* Add clone() and antiClone() functions to ports + Add getPortNames() to DataFlowInterface.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4762 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for #52:warning+compile error when using Ports
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4761 ce417995-dfc9-0310-95a0-acdaff106893
* Fix ScriptingAccess in TC constructor.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4760 ce417995-dfc9-0310-95a0-acdaff106893
* Fix variable name typo.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4752 ce417995-dfc9-0310-95a0-acdaff106893
* Reset the 'width' field when ostream-ing frames.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4750 ce417995-dfc9-0310-95a0-acdaff106893
* Remove 'dupes' of 'parent none' in cdl scripts
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4749 ce417995-dfc9-0310-95a0-acdaff106893
* Add forgotten file: must implement throw_exception when no exceptions are used in boost
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4748 ce417995-dfc9-0310-95a0-acdaff106893
* Embedded Orocos Patch:
  * use 'ORO_THROW' instead of throw
  * allow compilation with -fno-exceptions
  * allow compilation without the parser package (ScriptingAccess + ParserScriptingAccess)
  * Embedded allows only simple arguments for methods and commands.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4747 ce417995-dfc9-0310-95a0-acdaff106893
* Configurable logging:
  * printf / iostream choice
  * to file yes/no
  * to remote client yes/no
  + Maximum log lines stored in memory.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4746 ce417995-dfc9-0310-95a0-acdaff106893
* Fix URLs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4745 ce417995-dfc9-0310-95a0-acdaff106893
* Patch from Ben Gardiner: make uninstall-local: and install-exec-local in Makefile.am respect DESTDIR,
  fixes bug #67
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4743 ce417995-dfc9-0310-95a0-acdaff106893
* replace rtos_set_scheduler with new fosi call rtos_task_priority, move non portable OROSEM_OS_SCHEDTYPE to linux/xenomai/lxrt, remove some leftovers of previous fosi
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4737 ce417995-dfc9-0310-95a0-acdaff106893
* add get_name to template interface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4736 ce417995-dfc9-0310-95a0-acdaff106893
* adapt templates for porting orocos to new fosi
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4735 ce417995-dfc9-0310-95a0-acdaff106893
* fix holderdebolder indentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4734 ce417995-dfc9-0310-95a0-acdaff106893
* Beautify the stream output of Double6D/MultiVector and std::vector<double>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4733 ce417995-dfc9-0310-95a0-acdaff106893
* forgot to commit this when applying the fosi patch
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4732 ce417995-dfc9-0310-95a0-acdaff106893
* Task->Activity fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4731 ce417995-dfc9-0310-95a0-acdaff106893
* Improve testing speed, mainly by using SimulationThread::run() and removing the sleep(1)'s.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4730 ce417995-dfc9-0310-95a0-acdaff106893
* Adapt test to new Marshalling interface.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4729 ce417995-dfc9-0310-95a0-acdaff106893
* Add include for <fstream>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4728 ce417995-dfc9-0310-95a0-acdaff106893
* Fix several compilation issues/bugs related to Marshalling and Logger refactoring in corelib.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4727 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup left-overs of the type refactoring.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4726 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup left-overs of the type refactoring.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4725 ce417995-dfc9-0310-95a0-acdaff106893
* Interface/usability additions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4724 ce417995-dfc9-0310-95a0-acdaff106893
* * Major 'Marshalling' cleanup
  * Added the PropertyBagVisitor class which is a small base
  class of PropertyIntrospection.
  * Added the 'EmptyMarshaller' which is a dummy.
  * Fine-tuned the 'introspection/visit/identify' semantics:
  - PropertyBagVisitor just visits the bag's properties recursively.
  - PropertyIntrospection visits _and\_ decomposes to
  learn about every type present.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4723 ce417995-dfc9-0310-95a0-acdaff106893
* * Cleanup left-overs of type refactoring.
  * updateCommand( ) takes non-const DataSourceBase* argument
  * Added docs about compose/decomposeType
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4722 ce417995-dfc9-0310-95a0-acdaff106893
* Completely exclude Logger code for Embedded systems.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4721 ce417995-dfc9-0310-95a0-acdaff106893
* Add support for the 'run( steps )' function of the SimulationThread
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4720 ce417995-dfc9-0310-95a0-acdaff106893
* I promise this is the last time I commit before compiling \!
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4719 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed compilation error when OROCFG_CORELIB_REALTIME_TOOLKIT_IMPORT is not defined.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4718 ce417995-dfc9-0310-95a0-acdaff106893
* Rework fosi et al. see http://lists.mech.kuleuven.be/pipermail/orocos-dev/2006-May/001465.html
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4714 ce417995-dfc9-0310-95a0-acdaff106893
* fixed marshalling of std::vector<double> and added a testcase.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4712 ce417995-dfc9-0310-95a0-acdaff106893
* Merge Type Repos Refactoring from orocos-devel/orocos-type-repos
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4711 ce417995-dfc9-0310-95a0-acdaff106893
* s/seper/separ/g
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4694 ce417995-dfc9-0310-95a0-acdaff106893
* Ironing out CORBA merge glitches, updated installation docs wrt CORBA
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4690 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong include of CosPropertyService.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4688 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong include of CosPropertyService.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4687 ce417995-dfc9-0310-95a0-acdaff106893
* Resolution to bug #53: Add Get/Set Push/Pop methods to the Ports.
  Fix compilation bug in BufferDataSource as well.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4680 ce417995-dfc9-0310-95a0-acdaff106893
* Fix typo line
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4678 ce417995-dfc9-0310-95a0-acdaff106893
* Fix typo in Tao detection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4677 ce417995-dfc9-0310-95a0-acdaff106893
* Fix several configure and compilation issues wrt Corba project.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4674 ce417995-dfc9-0310-95a0-acdaff106893
* Corba Project.
  This is project #20 in Bugzilla.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4673 ce417995-dfc9-0310-95a0-acdaff106893
* Add Corba Manual. Adapt corba classes to changed CoreLib interface.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4672 ce417995-dfc9-0310-95a0-acdaff106893
* Add Obligatory missing file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4669 ce417995-dfc9-0310-95a0-acdaff106893
* Changed documentation of static RPY function as it was incorrect.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4668 ce417995-dfc9-0310-95a0-acdaff106893
* Add Corba package to trunk.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4667 ce417995-dfc9-0310-95a0-acdaff106893
* Implement destructor correctly, avoid virtual function calls in SlaveActivity.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4664 ce417995-dfc9-0310-95a0-acdaff106893
* Set activity when running a RunnableInterface.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4663 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #56: wrong includes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4661 ce417995-dfc9-0310-95a0-acdaff106893
* New activity: SlaveActivity.
  New method in ActivityInterface: bool trigger()
  Added support for 'trigger' to GenericTaskContext
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4660 ce417995-dfc9-0310-95a0-acdaff106893
* Merge project #31 on trunk: CoreLib 'Task' renaming to 'Activity'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4647 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: Use Time.hpp conversions for correct s ->ns conversion.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4619 ce417995-dfc9-0310-95a0-acdaff106893
* revert 'unauthorized' commits 4600-4601-4602 since it's not clear why they are necessary
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4618 ce417995-dfc9-0310-95a0-acdaff106893
* Another patch for fixing bug #47.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4617 ce417995-dfc9-0310-95a0-acdaff106893
* Working directory for tasks->activities renaming.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4616 ce417995-dfc9-0310-95a0-acdaff106893
* Small layout changes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4615 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for patch 4610: add missing file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4611 ce417995-dfc9-0310-95a0-acdaff106893
* * Use DataSource conversions also during assignments
  * Move DataSourceAdaptor.hpp to corelib package.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4610 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #51: Return 'int' instead of 'unsigned int' for compatibility with the scripting.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4609 ce417995-dfc9-0310-95a0-acdaff106893
* Lower required version of docbook
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4607 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug #6, where the equality assertions fail due to rounding errors
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4605 ce417995-dfc9-0310-95a0-acdaff106893
* Fix building of CompletionProcessor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4604 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #33: build for rtai3-3 failed.
  * do not call rt_preempty_always() for recent rtai versions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4603 ce417995-dfc9-0310-95a0-acdaff106893
* new include
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4602 ce417995-dfc9-0310-95a0-acdaff106893
* new paths
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4601 ce417995-dfc9-0310-95a0-acdaff106893
* extra include
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4600 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: Add bool full() method to BufferBase.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4599 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: erronous error message when thread is not running.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4598 ce417995-dfc9-0310-95a0-acdaff106893
* Add section about crashes caused by mixing compilers or SMP systems
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4597 ce417995-dfc9-0310-95a0-acdaff106893
* Prettify the TaskBrowser, provide event info, add color themes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4596 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: bug #50 'Scripting: one can not define variables in a statemachine's state'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4595 ce417995-dfc9-0310-95a0-acdaff106893
* Add 'full()' method to Port interface.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4594 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: documentation and data() const access from WriteDataPort.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4593 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #49 : Wrongfully invoke method twice when using assignment.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4590 ce417995-dfc9-0310-95a0-acdaff106893
* Add getEvents() method to EventService.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4589 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: Add comparison of std::vector<double>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4588 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug 47: use 'size_type' instead of 'size_t'
  + Add constructors for 'default' values for DataObjectLockFree and BufferLockFree.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4587 ce417995-dfc9-0310-95a0-acdaff106893
* Add small test case to test double6d and array methods.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4586 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #47 : misuse of size_t for inspecting buffer size/capacity.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4584 ce417995-dfc9-0310-95a0-acdaff106893
* Improved BufferLockFree and added FixedSizeMemoryPool for thread-independent lock-free buffering of data.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4581 ce417995-dfc9-0310-95a0-acdaff106893
* fix some cdl flaws, see http://lists.mech.kuleuven.be/pipermail/orocos-dev/2006-March/001271.html
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4578 ce417995-dfc9-0310-95a0-acdaff106893
* only log if reporting enabled
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4574 ce417995-dfc9-0310-95a0-acdaff106893
* Change ConnectionFactory to work with GCC 3.3.x. It now requires a class-level template instead of a function-level template.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4573 ce417995-dfc9-0310-95a0-acdaff106893
* remove deprecated option + adapt dual-kernel specific documentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4572 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug 45. Correct synchronisation of stop() in SingleThread.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4571 ce417995-dfc9-0310-95a0-acdaff106893
* Updated release scripts
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4570 ce417995-dfc9-0310-95a0-acdaff106893
* Add note about RTAI/LXRT rtai_up+rtai_lxrt.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4556 ce417995-dfc9-0310-95a0-acdaff106893
* Add Thread period changing question.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4555 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: SM Typedefs must be protected instead of private.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4553 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: constrain depth of make check-headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4534 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: namespaces and include bugs detected by make check-headers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4533 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: invoke rtos_sem_signal upon RT/NRT state change.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4531 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: remove undefined DIAS entry
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4530 ce417995-dfc9-0310-95a0-acdaff106893
* Doc Fix: add state change diagrams as png
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4527 ce417995-dfc9-0310-95a0-acdaff106893
* Doc Fixes: Overview document and XPointer inclusions in manuals
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4525 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: documentation example for Ports, Ports.hpp inclusion typos
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4521 ce417995-dfc9-0310-95a0-acdaff106893
* Doc Fixes: Fix creation of png out of svg files. Fix dead link in installation manual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4520 ce417995-dfc9-0310-95a0-acdaff106893
* Refactoring the documentation, moved bits and pieces around.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4513 ce417995-dfc9-0310-95a0-acdaff106893
* Fix Bug #44:fosi.h: _XOPEN_SOURCE 600 is not sufficient to pull in CLONE\_* for rtai_lxrt.h.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4512 ce417995-dfc9-0310-95a0-acdaff106893
* Added cross compilation instructions and make target.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4508 ce417995-dfc9-0310-95a0-acdaff106893
* Fix link to Orocos::Smartsoft
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4506 ce417995-dfc9-0310-95a0-acdaff106893
* Auto generate png files from svg files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4505 ce417995-dfc9-0310-95a0-acdaff106893
* Update the Orocos Overview document with new figures
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4504 ce417995-dfc9-0310-95a0-acdaff106893
* Moved svg diagrams to doc/svg subdir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4503 ce417995-dfc9-0310-95a0-acdaff106893
* Add Orocos overview figures
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4502 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: Add MaximumAcceleration to properties and remove dupe of MaximumVelocity.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4495 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation fixes:
  * replace .ac.be by .be
  * Fix stylesheets for unscoped classnames
  * Fix catalog redirection for orocos.ent file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4493 ce417995-dfc9-0310-95a0-acdaff106893
* Added LGPL License info to new files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4484 ce417995-dfc9-0310-95a0-acdaff106893
* Rename <sectN> to <section>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4483 ce417995-dfc9-0310-95a0-acdaff106893
* Fine tune manual types and pdf stylesheet.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4482 ce417995-dfc9-0310-95a0-acdaff106893
* Bump version number to 0.23.0, remove tar-ustar option:
  this breaks packaging of trunk.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4481 ce417995-dfc9-0310-95a0-acdaff106893
* remove obsolete RTAI-kernel-space port
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4478 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes: dist-checking fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4474 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: add missing getArity() method
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4470 ce417995-dfc9-0310-95a0-acdaff106893
* Fix: missing trailing backslash in dist-files list
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4468 ce417995-dfc9-0310-95a0-acdaff106893
* Add xenomai.cdl.in for dist-packaging
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4466 ce417995-dfc9-0310-95a0-acdaff106893
* Implement task disconnect() methods.
  This method informs all the peers that this task left the network
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4465 ce417995-dfc9-0310-95a0-acdaff106893
* remove obsolete rtlinux port
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4464 ce417995-dfc9-0310-95a0-acdaff106893
* Moved device drivers section to components manual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4463 ce417995-dfc9-0310-95a0-acdaff106893
* split the RTCS manual in sub-manuals which target different roles
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4462 ce417995-dfc9-0310-95a0-acdaff106893
* split developer's docs off user manuals
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4461 ce417995-dfc9-0310-95a0-acdaff106893
* Compare and swap a wider range of pointer types
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4460 ce417995-dfc9-0310-95a0-acdaff106893
* Make isRunning() a method
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4459 ce417995-dfc9-0310-95a0-acdaff106893
* Data Flow implementation for Task Contexts.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4458 ce417995-dfc9-0310-95a0-acdaff106893
* Hide (protect) refcount of DataSourceBase
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4457 ce417995-dfc9-0310-95a0-acdaff106893
* Added a 'base' class for buffer capacity/size methods
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4456 ce417995-dfc9-0310-95a0-acdaff106893
* Add License: LGPL
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4452 ce417995-dfc9-0310-95a0-acdaff106893
* Remove branch-0.20 tracking from trunk.
  Refer to new development plan: branches track trunk, not vice versa.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4449 ce417995-dfc9-0310-95a0-acdaff106893
* Improved ASSERT checking in tests.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4448 ce417995-dfc9-0310-95a0-acdaff106893
* Small readability updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4430 ce417995-dfc9-0310-95a0-acdaff106893
* Addes some info about fosi template files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4429 ce417995-dfc9-0310-95a0-acdaff106893
* FOSI Template for OS ports
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4428 ce417995-dfc9-0310-95a0-acdaff106893
* Add support for OS'es without main() function.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4427 ce417995-dfc9-0310-95a0-acdaff106893
* Fix PeriodicTask::start() not checking return value of timer::addTask
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4426 ce417995-dfc9-0310-95a0-acdaff106893
* Fix default startup() returning 'nothing
  ' instead of 'true'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4425 ce417995-dfc9-0310-95a0-acdaff106893
* Add Boost.function_types, which is not yet officially in boost.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4424 ce417995-dfc9-0310-95a0-acdaff106893
* Add getArity() function to the Command and Method factories
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4423 ce417995-dfc9-0310-95a0-acdaff106893
* Change the ConnectionC API to truely 'userfriendly' callback connection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4422 ce417995-dfc9-0310-95a0-acdaff106893
* Improved error reporting when constructing an invalid CommandC, MethodC or EventC
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4421 ce417995-dfc9-0310-95a0-acdaff106893
* Declare the 'emit_type
  ' to be used by event factory parts of the library
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4420 ce417995-dfc9-0310-95a0-acdaff106893
* Add sigslot::handle retrieval methods to Handle class
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4419 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong EOL encodings
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4418 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #35
  Properly detect initialize() returning false.
  Added unit test for this situation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4417 ce417995-dfc9-0310-95a0-acdaff106893
* Fix program script unit tests to more restrictive start/stop semantics of programs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4416 ce417995-dfc9-0310-95a0-acdaff106893
* Feedback from Herman, use more diagrams.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4415 ce417995-dfc9-0310-95a0-acdaff106893
* Less strict alias parsing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4413 ce417995-dfc9-0310-95a0-acdaff106893
* Fix method pass by reference for std::vector types.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4412 ce417995-dfc9-0310-95a0-acdaff106893
* minor readability updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4411 ce417995-dfc9-0310-95a0-acdaff106893
* 'Massive' update of the TaskContext manual, making the examples far more practical to novice users.
  Added the 'application code' hooks: startup() update() shutdown().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4408 ce417995-dfc9-0310-95a0-acdaff106893
* Reorder task primitive to front of manual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4406 ce417995-dfc9-0310-95a0-acdaff106893
* Added Xenomai section, simplify text
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4405 ce417995-dfc9-0310-95a0-acdaff106893
* Added TAO configuration instructions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4404 ce417995-dfc9-0310-95a0-acdaff106893
* Remove disturbing logger messages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4403 ce417995-dfc9-0310-95a0-acdaff106893
* Generate idl files from configure script instead of cdl file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4399 ce417995-dfc9-0310-95a0-acdaff106893
* Fix warnings about unused arguments
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4398 ce417995-dfc9-0310-95a0-acdaff106893
* Fix uninitialised 'mstep' value
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4397 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compiler warnings: unused argument
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4396 ce417995-dfc9-0310-95a0-acdaff106893
* rename data() to datasources() in order to prevent name clash
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4395 ce417995-dfc9-0310-95a0-acdaff106893
* implemented the cross-ref with Doxygen framework
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4394 ce417995-dfc9-0310-95a0-acdaff106893
* Cross-reference updates to Manuals
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4393 ce417995-dfc9-0310-95a0-acdaff106893
* Small API updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4392 ce417995-dfc9-0310-95a0-acdaff106893
* Add data() methods
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4391 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation updates for 0.22.0 release
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4387 ce417995-dfc9-0310-95a0-acdaff106893
* Fix parsers for cross-task event interception in StateMachine event transitions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4386 ce417995-dfc9-0310-95a0-acdaff106893
* Add kinematics components to templates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4385 ce417995-dfc9-0310-95a0-acdaff106893
* Refactored the KinematicsFactory:
  * Easier addition of other algorithms
  * Serialisation to/from file of algorithms
  * Documentation updates.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4384 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation updates for 0.22.0 release
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4383 ce417995-dfc9-0310-95a0-acdaff106893
* Leave out ORO_PRAGMA_INTERFACE until it is better tested with # compilers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4382 ce417995-dfc9-0310-95a0-acdaff106893
* Remove FIFO wrappers and condition variables in fosi.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4381 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation updates for 0.22 release
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4380 ce417995-dfc9-0310-95a0-acdaff106893
* Add operator<< for a PropertyBag
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4379 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation updates for 0.22 release
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4378 ce417995-dfc9-0310-95a0-acdaff106893
* Update docs for 0.22.0 release.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4377 ce417995-dfc9-0310-95a0-acdaff106893
* Split KinematicProcess implementation to cxx file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4376 ce417995-dfc9-0310-95a0-acdaff106893
* Renamed the *NS* components to same without 'NS'.
  Added the CartesianProcess to order KinematicProcess with DataFlow component execution.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4375 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4374 ce417995-dfc9-0310-95a0-acdaff106893
* Upon load failure of user's 'DefaultProcess', reload ControlKernelProcess.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4373 ce417995-dfc9-0310-95a0-acdaff106893
* Only enable ListLockFree testing under gnulinux
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4371 ce417995-dfc9-0310-95a0-acdaff106893
* Deprecate locked buffers and old Fifo implementations (2)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4369 ce417995-dfc9-0310-95a0-acdaff106893
* Deprecate locked buffers and old Fifo implementations
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4368 ce417995-dfc9-0310-95a0-acdaff106893
* Preparing changes document for 0.22.0 release
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4353 ce417995-dfc9-0310-95a0-acdaff106893
* update svn server address
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4352 ce417995-dfc9-0310-95a0-acdaff106893
* Remove __attribute_\_((__unused_\_)) since it remains problematic on some GCC versions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4347 ce417995-dfc9-0310-95a0-acdaff106893
* Add operator= to the *C classes for correct copy semantics.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4342 ce417995-dfc9-0310-95a0-acdaff106893
* Clearer error message to user if command is not accepted.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4318 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug #12. Test for object existence and throw name_not_found_exception if not.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4307 ce417995-dfc9-0310-95a0-acdaff106893
* Try to avoid name clashes by quoting the 'unused' attribute
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4299 ce417995-dfc9-0310-95a0-acdaff106893
* Fix endless unload loop for hierarchical state machines.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4298 ce417995-dfc9-0310-95a0-acdaff106893
* fixed KinematicsJointConverter, is now usable
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4292 ce417995-dfc9-0310-95a0-acdaff106893
* Update license information
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4290 ce417995-dfc9-0310-95a0-acdaff106893
* small update wrt added css file and provide user parameter for uploading.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4289 ce417995-dfc9-0310-95a0-acdaff106893
* Misc. header fixes after 'make check-headers'.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4288 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed 'strange' method implementation of reportGet()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4287 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed misuse of property bag
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4286 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation fixes and testing with new docbook stylesheets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4285 ce417995-dfc9-0310-95a0-acdaff106893
* also detect comedi if installed in default path
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4284 ce417995-dfc9-0310-95a0-acdaff106893
* kuka160 changed to Kuka160 for consistency
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4281 ce417995-dfc9-0310-95a0-acdaff106893
* Chapter re-ordering
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4279 ce417995-dfc9-0310-95a0-acdaff106893
* property svn:ignore added for created svn files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4278 ce417995-dfc9-0310-95a0-acdaff106893
* Added 'tentative' lock-free list implementation, but sticked to locked timers to solve synchronisation. At least a semaphore or mutex needs to be added to the lock-free implementation to solve the races between step() and finalize().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4277 ce417995-dfc9-0310-95a0-acdaff106893
* Removed lock-based lists and put ListLockFree implementation in place (EventProcessor).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4276 ce417995-dfc9-0310-95a0-acdaff106893
* Removed lock-based lists and put ListLockFree implementation in place.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4275 ce417995-dfc9-0310-95a0-acdaff106893
* Added 'blanking' during 'apply' which allows to modify the list 'in-place' such that items can be erased with immediate effect during an apply_and_blank, using erase_and_blank.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4274 ce417995-dfc9-0310-95a0-acdaff106893
* Added Process Components Section
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4273 ce417995-dfc9-0310-95a0-acdaff106893
* Consequent properties for 'startupComponents'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4272 ce417995-dfc9-0310-95a0-acdaff106893
* Update diagrams to current code status
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4270 ce417995-dfc9-0310-95a0-acdaff106893
* Updated execution manuals to latest code
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4269 ce417995-dfc9-0310-95a0-acdaff106893
* More informative logging messages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4268 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compilation for newer 'comedilib' versions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4267 ce417995-dfc9-0310-95a0-acdaff106893
* Rename createXXX to setupXXX for consequent naming
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4266 ce417995-dfc9-0310-95a0-acdaff106893
* Consequent processor ordering
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4265 ce417995-dfc9-0310-95a0-acdaff106893
* First execute Transition Program, then Exit Program
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4264 ce417995-dfc9-0310-95a0-acdaff106893
* Accidentally removed LXRT, readded
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4263 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug in jacobianForward/Inverse
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4250 ce417995-dfc9-0310-95a0-acdaff106893
* corba control task
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4232 ce417995-dfc9-0310-95a0-acdaff106893
* update docs to version 0.21.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4231 ce417995-dfc9-0310-95a0-acdaff106893
* add xenomai target
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4230 ce417995-dfc9-0310-95a0-acdaff106893
* Update tests of corelib changes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4229 ce417995-dfc9-0310-95a0-acdaff106893
* add xenomai target
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4228 ce417995-dfc9-0310-95a0-acdaff106893
* add xenomai target
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4227 ce417995-dfc9-0310-95a0-acdaff106893
* Added some doxygen comments
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4226 ce417995-dfc9-0310-95a0-acdaff106893
* fix .cdl touch ordering of idl generated files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4225 ce417995-dfc9-0310-95a0-acdaff106893
* add kinematics components to doxygen headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4224 ce417995-dfc9-0310-95a0-acdaff106893
* Create DefaultProcess on kernel construction,
  fix execution extension cleanup of task.
  + Doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4223 ce417995-dfc9-0310-95a0-acdaff106893
* nicer logger output, fix destructor for child engines
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4222 ce417995-dfc9-0310-95a0-acdaff106893
* sortedlist is only for 32bit archs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4221 ce417995-dfc9-0310-95a0-acdaff106893
* Fix active/running semantics for non periodic tasks
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4220 ce417995-dfc9-0310-95a0-acdaff106893
* nicer logging output
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4219 ce417995-dfc9-0310-95a0-acdaff106893
* forgot active(false) initialization is constructor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4213 ce417995-dfc9-0310-95a0-acdaff106893
* Add Xenomai Port
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4198 ce417995-dfc9-0310-95a0-acdaff106893
* Resolve active/running disambiguity when starting/stopping corelib tasks
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4197 ce417995-dfc9-0310-95a0-acdaff106893
* Set running state to true before initialize().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4195 ce417995-dfc9-0310-95a0-acdaff106893
* First start ExecutionEngine, then try to start programs/states
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4190 ce417995-dfc9-0310-95a0-acdaff106893
* reversed order execution extension and kernelbase extension
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4180 ce417995-dfc9-0310-95a0-acdaff106893
* Detect wrongly ordered Facets for EExt.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4179 ce417995-dfc9-0310-95a0-acdaff106893
* User-friendly includes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4175 ce417995-dfc9-0310-95a0-acdaff106893
* rename fustion to xenomai
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4174 ce417995-dfc9-0310-95a0-acdaff106893
* rename of fusion to xenomai
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4173 ce417995-dfc9-0310-95a0-acdaff106893
* Rename fusion to xenomai
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4172 ce417995-dfc9-0310-95a0-acdaff106893
* Start xenomai port
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4162 ce417995-dfc9-0310-95a0-acdaff106893
* Minor make doc fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4157 ce417995-dfc9-0310-95a0-acdaff106893
* Large update to test refactoring of
  * Execution Engine
  * Events & service
  * Lists
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4156 ce417995-dfc9-0310-95a0-acdaff106893
* Kernel Process Components:
  * The Process has access to all Data objects
  * Kinematics Process is one example.
  Also adopt to Execution Engine of TaskContext.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4155 ce417995-dfc9-0310-95a0-acdaff106893
* The Big Execution Engine Refactoring.
  * Processor: Does not longer exist and is split up
  into the four kinds of processors(events, commands, programs, states)
  * ExecutionEngine: Takes over the responsibility of the old Processor,
  delegates tasks to new smaller processors.
  * StateMachineTask, ProgramTask: A program and state machine have a task
  assigned to them from the very beginning, thus allowing self-commands.
  * CommandC, EventC, MethodC, ConnectionC: manage in C++ these communication
  types, userfriendly creation and destruction.
  * DataSource: evaluate() now returns a boolean.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4154 ce417995-dfc9-0310-95a0-acdaff106893
* Updated Events with new real-time LockFreeList.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4153 ce417995-dfc9-0310-95a0-acdaff106893
* Experimenting with Lock-Free lists.
  * SingleList: Implementation of T. Harris' list. Not used,
  since not suitable for hard real-time
  * ListLockFree: Own implementation, very nifty, but
  only suitable for smaller lists < 100 items.
  * MemoryPool: was a wild idea, but not used.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4152 ce417995-dfc9-0310-95a0-acdaff106893
* Adapted LXRT & GNU/Linux for future thread overrun detection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4151 ce417995-dfc9-0310-95a0-acdaff106893
* PeriodicThreads: infrastructure for thread overruns.
  RunnableInterface: infrastructure for thread owner localisation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4150 ce417995-dfc9-0310-95a0-acdaff106893
* Change execution semantics wrt stop() and breakLoop().
  See updated docs of this class.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4149 ce417995-dfc9-0310-95a0-acdaff106893
* Nicer output for logger warning levels
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4148 ce417995-dfc9-0310-95a0-acdaff106893
* Improved the TaskInterface vs RunnableInterface.
  Detect whether task is running while runnable is deleted.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4147 ce417995-dfc9-0310-95a0-acdaff106893
* new kinematics uses vector<double> instead of double6D... Thanks
  Peter!!!!!!!
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4141 ce417995-dfc9-0310-95a0-acdaff106893
* new kinematics doesn't use double6D but vector<double>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4140 ce417995-dfc9-0310-95a0-acdaff106893
* do not depend on build kernel modules flag
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4111 ce417995-dfc9-0310-95a0-acdaff106893
* Remove dependency such that kernel modules can be disabled
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4110 ce417995-dfc9-0310-95a0-acdaff106893
* Allow disabling of building kernel modules, such that
  Linux 2.6 modules can be built using a separate Makefile.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4109 ce417995-dfc9-0310-95a0-acdaff106893
* updates to MultiVector used by Kinematics
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4106 ce417995-dfc9-0310-95a0-acdaff106893
* Upgrade components to new KinematicsInterface
  Give all cartesian components Execution Facet
  Test Generator safeStop and add it to execution interface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4074 ce417995-dfc9-0310-95a0-acdaff106893
* Upgrade the KinematicsInterface to multi-axis semantics.
  Wrap the old algorithms to new interface.
  Fix wrong singularity handling in some places and add default constructor for singularity to ::None
  Update the interface of KinematicsComponent to be more 'modern' and useful
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4073 ce417995-dfc9-0310-95a0-acdaff106893
* do not compile the *S_T* files, since do not compile under GCC4 and not needed anyway.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4029 ce417995-dfc9-0310-95a0-acdaff106893
* Corrected a bug in the LockFreeControlKernel.hpp and CascadedControlKernel.hpp.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3977 ce417995-dfc9-0310-95a0-acdaff106893
* Lock-free real-time sorted list implementation and ditto real-time lock-free memory pool to manage the memory allocation
  +test cases
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3975 ce417995-dfc9-0310-95a0-acdaff106893
* Test for detecting thread overruns, however, both RTAI and GNU/Linux do not support it, thus test is plainly not conducted
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3974 ce417995-dfc9-0310-95a0-acdaff106893
* Fix memory leak in test
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3973 ce417995-dfc9-0310-95a0-acdaff106893
* Fix race condition in BufferLockFree which occured during highly concurrent access. We require twice as much memory now per thread however.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3972 ce417995-dfc9-0310-95a0-acdaff106893
* Fix kernel initialisation of commands in multiple kernel setups
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3960 ce417995-dfc9-0310-95a0-acdaff106893
* Added test for start/stop of periodic threads
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3950 ce417995-dfc9-0310-95a0-acdaff106893
* Critical fix for repeated start/stop semantics of periodic threads
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3949 ce417995-dfc9-0310-95a0-acdaff106893
* Add rotation/frame inverse and rotation*vector transformations to scripting
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3948 ce417995-dfc9-0310-95a0-acdaff106893
* Fix macro warning
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3947 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed blocking policies and deadlock in BufferLocked
  Added a clear() method for buffers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3922 ce417995-dfc9-0310-95a0-acdaff106893
* Fix LXRT crash, remove 'Global' EventService...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3912 ce417995-dfc9-0310-95a0-acdaff106893
* fix ThreadScope crashes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3892 ce417995-dfc9-0310-95a0-acdaff106893
* Toggle ThreadScope bit on basis of priority
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3884 ce417995-dfc9-0310-95a0-acdaff106893
* virtual software DigitalOutput added
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3880 ce417995-dfc9-0310-95a0-acdaff106893
* allow use of out-of-orocos thread scope
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3877 ce417995-dfc9-0310-95a0-acdaff106893
* allow use of out-of-orocos thread scope
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3876 ce417995-dfc9-0310-95a0-acdaff106893
* make "RefPoint" method const
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3860 ce417995-dfc9-0310-95a0-acdaff106893
* Added test case for event driven state machines
  Minor frames testing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3859 ce417995-dfc9-0310-95a0-acdaff106893
* Required patch for the event-based state machine and
  execution engine refactorings.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3858 ce417995-dfc9-0310-95a0-acdaff106893
* * Introduction of the Execution Engine to manage serialisation
  of activities and to track processors.
  * Orocos Event-based StateMachines are a working go !
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3857 ce417995-dfc9-0310-95a0-acdaff106893
* Fix 'reject valid's
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3856 ce417995-dfc9-0310-95a0-acdaff106893
* * Fixed not-compile bug in EventProcessor when using bool argument for event.
  * Fixed terrible endless loop self-disconnection bug in event impl.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3855 ce417995-dfc9-0310-95a0-acdaff106893
* Added the 'Time' DataSource
  Fixed wrong inversion i n ConditionDSDuration
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3852 ce417995-dfc9-0310-95a0-acdaff106893
* Fix a number of keyword-intrusions in identifiers,
  notably, frame*, vector*, etc and time.
  cleaned the time expressions up in the meantime.
  while ( time > x ) still does not work though...
  timestamp is reset each time.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3846 ce417995-dfc9-0310-95a0-acdaff106893
* Add -lstdc++ flag to test link flags
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3845 ce417995-dfc9-0310-95a0-acdaff106893
* More verbose error reporting if file not found
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3843 ce417995-dfc9-0310-95a0-acdaff106893
* forgot to commit
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3840 ce417995-dfc9-0310-95a0-acdaff106893
* add corba (ace/tao) support package
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3828 ce417995-dfc9-0310-95a0-acdaff106893
* Define data() and method() functions with and without const qualifier for gcc 4.0.2
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3823 ce417995-dfc9-0310-95a0-acdaff106893
* Re-add 'const' in effort to try to fix stuff for newer gcc4 compiler.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3822 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed ORO_PRAGMA_INTERFACE baddness
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3811 ce417995-dfc9-0310-95a0-acdaff106893
* Fix switchOff() error in refactoring code...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3809 ce417995-dfc9-0310-95a0-acdaff106893
* Fix 'empty' pointer checking macros
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3801 ce417995-dfc9-0310-95a0-acdaff106893
* Added the 'AnalogReference' enum to these interfaces
  in order to provide the user comedi-independent way
  of configuring the device.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3800 ce417995-dfc9-0310-95a0-acdaff106893
* Major improvement of Comedi device drivers:
  * No longer a dependency on comedi headers when building your application
  - Split the headers to implementation files
  - Unified inclusion of 'comedi' headers in one file to make further
  upgrades/changes of comedi easier.
  * Improved performance issues with all devices (reducing up-calls,
  caching channels, do not call virtual functions of 'this'. )
  * return 'zero' channels if device is misconfigured, also
  rejecting all method calls if so.
  * Removed 'using namespace' directives from headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3799 ce417995-dfc9-0310-95a0-acdaff106893
* Re-arrange loglevel/module order
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3792 ce417995-dfc9-0310-95a0-acdaff106893
* Added lock-based buffer
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3791 ce417995-dfc9-0310-95a0-acdaff106893
* Added missing include guards
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3790 ce417995-dfc9-0310-95a0-acdaff106893
* Fixing OS Architecture Selection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3788 ce417995-dfc9-0310-95a0-acdaff106893
* Fix crash when trying to connect unconnected handle
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3782 ce417995-dfc9-0310-95a0-acdaff106893
* Remove erroneous help instruction
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3778 ce417995-dfc9-0310-95a0-acdaff106893
* Added gcov flag, updated help messages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3777 ce417995-dfc9-0310-95a0-acdaff106893
* Initial code coverage import
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3776 ce417995-dfc9-0310-95a0-acdaff106893
* Fix gcc3 typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3775 ce417995-dfc9-0310-95a0-acdaff106893
* Removed dependency on boost signals
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3774 ce417995-dfc9-0310-95a0-acdaff106893
* Allow to add 'PropertyBase' objects to AttributeRepository
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3773 ce417995-dfc9-0310-95a0-acdaff106893
* make TC Processor Changeable
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3772 ce417995-dfc9-0310-95a0-acdaff106893
* Always expect 'end of statement'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3771 ce417995-dfc9-0310-95a0-acdaff106893
* Better use of Logger
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3770 ce417995-dfc9-0310-95a0-acdaff106893
* Better error reporting using Logger
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3769 ce417995-dfc9-0310-95a0-acdaff106893
* formatting cleanups
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3768 ce417995-dfc9-0310-95a0-acdaff106893
* fix logging impl wrt passing a string literal, use const char* instead of const string&
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3767 ce417995-dfc9-0310-95a0-acdaff106893
* Extended 'time' comparisons with regular expressions
  instead of 'const' numbers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3764 ce417995-dfc9-0310-95a0-acdaff106893
* Added Condition which evaluates expired time using a DataSource
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3763 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrong termination condition of program.stop() command
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3761 ce417995-dfc9-0310-95a0-acdaff106893
* TaskBrowser Improvements:
  * Add methods to evaluate expressions in current task context
  and to switch task context.
  * Also print properties which are not attributes in 'ls' and tab completion.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3760 ce417995-dfc9-0310-95a0-acdaff106893
* fix wrong variable name
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3752 ce417995-dfc9-0310-95a0-acdaff106893
* Finish the x86_64 port with moving i386 specific files
  to an 'arch' subdir and 'auto-detect' architecture in config tool.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3751 ce417995-dfc9-0310-95a0-acdaff106893
* FIX (all OS's) incorrect calculation of thread period.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3750 ce417995-dfc9-0310-95a0-acdaff106893
* oeps.. I was too fast to commit.. here's the fix..
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3728 ce417995-dfc9-0310-95a0-acdaff106893
* remove cout
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3727 ce417995-dfc9-0310-95a0-acdaff106893
* Extended Logger with [Location] information using the
  Logger::In("Location"); object
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3673 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compiler warning
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3672 ce417995-dfc9-0310-95a0-acdaff106893
* Added pure virtual method getDriveValue(), used by control
  kernel components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3671 ce417995-dfc9-0310-95a0-acdaff106893
* Added Position sensor in getSensorList()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3670 ce417995-dfc9-0310-95a0-acdaff106893
* Made fake devices more flexible to simulate real ones.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3669 ce417995-dfc9-0310-95a0-acdaff106893
* Support for AxisInterface to allow SimulationAxis
  and other implementations to be used.
  Backwards Compatible.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3667 ce417995-dfc9-0310-95a0-acdaff106893
* one little error in oro_system.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3666 ce417995-dfc9-0310-95a0-acdaff106893
* differences for x86_64-systems included in these files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3665 ce417995-dfc9-0310-95a0-acdaff106893
* Guard the boost::graph includes against macros
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3658 ce417995-dfc9-0310-95a0-acdaff106893
* Further undef RTAI macros which conflict with boost::graph
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3656 ce417995-dfc9-0310-95a0-acdaff106893
* Fix 64bit support for RTAI/LXRT _within Orocos\_
  We use the RTAIPosix layer which may not be 64bit safe
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3655 ce417995-dfc9-0310-95a0-acdaff106893
* Add tune to / arch == none (omit) to build options
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3651 ce417995-dfc9-0310-95a0-acdaff106893
* Added athlon64 targets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3650 ce417995-dfc9-0310-95a0-acdaff106893
* Include asm/rtai_lxrt.h instead of redefining rtai_lxrt func.
  may break C++ compilation in some rtai/kernel version configurations
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3649 ce417995-dfc9-0310-95a0-acdaff106893
* oops, wrong comparison of version numbers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3647 ce417995-dfc9-0310-95a0-acdaff106893
* Backwards compatibility to boost 1.31
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3646 ce417995-dfc9-0310-95a0-acdaff106893
* also install modules/; some moron never would have guessed/hoped his software would be packaged someday
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3645 ce417995-dfc9-0310-95a0-acdaff106893
* try to remove crap out of macro namespace
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3644 ce417995-dfc9-0310-95a0-acdaff106893
* set things ready for asm/ directory, wrap oro_bitops functions in agnostic macro
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3643 ce417995-dfc9-0310-95a0-acdaff106893
* fix for AGNOSTIC, do not use internal bitops file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3642 ce417995-dfc9-0310-95a0-acdaff106893
* move evalCommand from protected to public interface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3637 ce417995-dfc9-0310-95a0-acdaff106893
* fix bugs in duplicate code
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3636 ce417995-dfc9-0310-95a0-acdaff106893
* updated comedi detection section
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3635 ce417995-dfc9-0310-95a0-acdaff106893
* fix incompatible pointer types
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3625 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug in configure script
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3624 ce417995-dfc9-0310-95a0-acdaff106893
* alter path of subversion repository
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3623 ce417995-dfc9-0310-95a0-acdaff106893
* Added missing forward declarations.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2837 ce417995-dfc9-0310-95a0-acdaff106893
* Added scopes to class types in headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2836 ce417995-dfc9-0310-95a0-acdaff106893
* Made fusion a 'hardware' target
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2835 ce417995-dfc9-0310-95a0-acdaff106893
* eCos skeletton
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2834 ce417995-dfc9-0310-95a0-acdaff106893
* Scriptable Events implementation in state machines and program scripts
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2833 ce417995-dfc9-0310-95a0-acdaff106893
* Skeletton for fusion OS support
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2832 ce417995-dfc9-0310-95a0-acdaff106893
* Fusion support cdl file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2831 ce417995-dfc9-0310-95a0-acdaff106893
* EventTransitions : ignore 'late' defered event transitions
  when a new state is already entered.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2830 ce417995-dfc9-0310-95a0-acdaff106893
* fix docs for moved svn repos
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2827 ce417995-dfc9-0310-95a0-acdaff106893
* Test+implement self and cross removal in signals implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2818 ce417995-dfc9-0310-95a0-acdaff106893
* Use loop detection in RunnableInterface of Processor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2817 ce417995-dfc9-0310-95a0-acdaff106893
* Added isPeriodic() inspection method
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2816 ce417995-dfc9-0310-95a0-acdaff106893
* Initialized merge tracking via svnmerge with revisions 1-2813 from
  https://svn.mech.kuleuven.be/repos/orocos/orocos-branches/branch-0.20
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2814 ce417995-dfc9-0310-95a0-acdaff106893
* Removed old svnmerge properties
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2813 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen using dot
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2812 ce417995-dfc9-0310-95a0-acdaff106893
* BufferInterface refactoring patch.
  * Added blocking/non blocking policies on full/empty buffer
  * BufferInterface/WriteInterface/ReadInterface have Push(T)/T Pull()
  as methods instead of deprecated char* buffer semantics
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2811 ce417995-dfc9-0310-95a0-acdaff106893
* remove logger :-(
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2801 ce417995-dfc9-0310-95a0-acdaff106893
* add logger
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2796 ce417995-dfc9-0310-95a0-acdaff106893
* Typo fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2787 ce417995-dfc9-0310-95a0-acdaff106893
* Typo fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2786 ce417995-dfc9-0310-95a0-acdaff106893
* Optimize compilation takes -O flag instead of -O0.
  This allows correct use of outb/inb, and possibly other assembly,
  without sacrificing compilation time (like Os or O2 do).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2777 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen typo fixes. replace all <Blah> with \a Blah.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2775 ce417995-dfc9-0310-95a0-acdaff106893
* do not reset timestamp on restart(), must be done by resetTime
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2774 ce417995-dfc9-0310-95a0-acdaff106893
* new event testprogram
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2767 ce417995-dfc9-0310-95a0-acdaff106893
* Add Event Transitions to StateMachine using new event infrastructure
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2766 ce417995-dfc9-0310-95a0-acdaff106893
* Added EventService to TaskContext's interface,
  activate compilation of ES.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2765 ce417995-dfc9-0310-95a0-acdaff106893
* Fix endless loop in cases where TB can not handle listings properly
  (damage reduction)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2764 ce417995-dfc9-0310-95a0-acdaff106893
* Activated new signal/slot Event/Handle backend.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2763 ce417995-dfc9-0310-95a0-acdaff106893
* Split up factory exceptions and inherit from std::exception.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2762 ce417995-dfc9-0310-95a0-acdaff106893
* Added Forward Decl. of ComponentBaseInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2761 ce417995-dfc9-0310-95a0-acdaff106893
* typo fix.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2760 ce417995-dfc9-0310-95a0-acdaff106893
* Corrected namespace usage.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2759 ce417995-dfc9-0310-95a0-acdaff106893
* Fix kindyn manual link + doxy updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2758 ce417995-dfc9-0310-95a0-acdaff106893
* compile fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2756 ce417995-dfc9-0310-95a0-acdaff106893
* update for --with-linux flag.
  Expanded headers section to include all significant locations.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2754 ce417995-dfc9-0310-95a0-acdaff106893
* Modified test to investigate Parser infrastructure overhead.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2753 ce417995-dfc9-0310-95a0-acdaff106893
* fix memleak
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2752 ce417995-dfc9-0310-95a0-acdaff106893
* Successful tests for EventService
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2751 ce417995-dfc9-0310-95a0-acdaff106893
* mlockall patch
  Make mlockall configurable, defaulting to MCL_CURRENT only.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2750 ce417995-dfc9-0310-95a0-acdaff106893
* replace static Mutex as member
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2749 ce417995-dfc9-0310-95a0-acdaff106893
* Tested and working version of EventService
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2748 ce417995-dfc9-0310-95a0-acdaff106893
* Fix using directives
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2747 ce417995-dfc9-0310-95a0-acdaff106893
* Fix using directives, namespace prefixing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2746 ce417995-dfc9-0310-95a0-acdaff106893
* Dispose condition after evaluation to true, to avoid evaluating
  destroyed object.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2745 ce417995-dfc9-0310-95a0-acdaff106893
* Fix using directives
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2744 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen typo fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2743 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen workaround doc of derived Template classes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2742 ce417995-dfc9-0310-95a0-acdaff106893
* Tweaking the signal base class,
  Handle is convertible to handle :-/
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2741 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen typo fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2740 ce417995-dfc9-0310-95a0-acdaff106893
* Added missing using directive
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2739 ce417995-dfc9-0310-95a0-acdaff106893
* Added ReferenceDataSource<T> holding & to external data
  DataSourceGenerator supports boost::ref() for ref to vars.
  DataSourceAdaptor fixed implementation of AssignableDS casting.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2738 ce417995-dfc9-0310-95a0-acdaff106893
* GCC 4.0 Fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2737 ce417995-dfc9-0310-95a0-acdaff106893
* Report runtime error if no marshaller package present.
  Report error if updateProperties failed.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2736 ce417995-dfc9-0310-95a0-acdaff106893
* Added <float> type to TypeInfo. Re-arranged order
  of qualifiers, now succeeding the type name.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2735 ce417995-dfc9-0310-95a0-acdaff106893
* Update PropertyBag semantics change :
  * If the types are different, 'overwrite' with new type,
  delete(!) all old contents and populate target bag with
  copies of new type.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2734 ce417995-dfc9-0310-95a0-acdaff106893
* Event Factories/Service Ready for testing...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2733 ce417995-dfc9-0310-95a0-acdaff106893
* * Corrected svn:ignore property with newline separated file patterns
  * Updated RTAI configuration section of installation manual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2732 ce417995-dfc9-0310-95a0-acdaff106893
* Added svn:ignore to *.jpg and *.png
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2731 ce417995-dfc9-0310-95a0-acdaff106893
* Ignore gcc.cdl file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2730 ce417995-dfc9-0310-95a0-acdaff106893
* Force specifying patched linux kernel path when using RTAI,
  since it wants linux kernel headers, so give them.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2729 ce417995-dfc9-0310-95a0-acdaff106893
* explicit no-warranty file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2728 ce417995-dfc9-0310-95a0-acdaff106893
* Catch exception when wrong filename provided and log to Logger
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2727 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup of the const std::string& DataSource implementation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2726 ce417995-dfc9-0310-95a0-acdaff106893
* Initial EventService Implementation for Events for up to 3 arguments
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2725 ce417995-dfc9-0310-95a0-acdaff106893
* Tested local_allocator and rt_list implementations
  to be used with the signal<> implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2724 ce417995-dfc9-0310-95a0-acdaff106893
* Tested Handle and Signal classes. Implementation to cxx files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2723 ce417995-dfc9-0310-95a0-acdaff106893
* Implementation of signal<> classes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2722 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed wrong preprocessor defines, seems to be a working impl
  of signal<> according to tests/valgrind
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2721 ce417995-dfc9-0310-95a0-acdaff106893
* git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2720 ce417995-dfc9-0310-95a0-acdaff106893
* extra info
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2719 ce417995-dfc9-0310-95a0-acdaff106893
* Add -D_REENTRANT, fix wrong boost/pthread libs, add important note.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2718 ce417995-dfc9-0310-95a0-acdaff106893
* Split operator<< definitions to cxx file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2712 ce417995-dfc9-0310-95a0-acdaff106893
* use orocos logger
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2711 ce417995-dfc9-0310-95a0-acdaff106893
* File renaming to Orocos conventions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2694 ce417995-dfc9-0310-95a0-acdaff106893
* Split signal/slot implementation in multiple header files,
  analogous to boost::signals
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2693 ce417995-dfc9-0310-95a0-acdaff106893
* First version of real-time pool allocator for local,
  non multi-threaded allocations.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2692 ce417995-dfc9-0310-95a0-acdaff106893
* First version of hard realtime connections for signal/slot implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2691 ce417995-dfc9-0310-95a0-acdaff106893
* fix: include frames_io.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2690 ce417995-dfc9-0310-95a0-acdaff106893
* Testing of DataSourceGenerator
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2688 ce417995-dfc9-0310-95a0-acdaff106893
* Only install newer headers and lib
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2687 ce417995-dfc9-0310-95a0-acdaff106893
* This patch fixes several things :
  1. Fix end-of-line sensitivity of the parsers. Statements are now
  ended by an eol or separated by ; on one line.
  2. Fix broken 'const' in 0.20.0 and replace it with parse-time
  evaluated constants.
  3. const, var, param statements can now define multiple variables on one line.
  4. Updated docs with new const semantics.
  5. Fix double6d parsing, leaving an expression on the stack.
  6. Fixed factories taking property arguments : read property values immediately.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2686 ce417995-dfc9-0310-95a0-acdaff106893
* Kicked out Loki ! Use boost::mpl instead.
  Fixed some memleaks upon cleanup if user did not unload components.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2685 ce417995-dfc9-0310-95a0-acdaff106893
* Marshall vector and Double6D to ostream object
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2684 ce417995-dfc9-0310-95a0-acdaff106893
* Misc DataSource doxy updates and make some destructors
  protected.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2683 ce417995-dfc9-0310-95a0-acdaff106893
* Allow returning of reference property
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2682 ce417995-dfc9-0310-95a0-acdaff106893
* Add reentrancy flag for compiling tests
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2679 ce417995-dfc9-0310-95a0-acdaff106893
* Fix non compiling inState function and solve possible race
  conditions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2644 ce417995-dfc9-0310-95a0-acdaff106893
* Check for null set() in AdaptDataSource
  put AdaptDataSource in ORO_Execution namespace instead of detail.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2643 ce417995-dfc9-0310-95a0-acdaff106893
* Backward compatibility fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2641 ce417995-dfc9-0310-95a0-acdaff106893
* new syntax of ParsedStateMachine
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2640 ce417995-dfc9-0310-95a0-acdaff106893
* Added 'run' program in state machine. Adapted transition semantics
  to discussion on mailing list. Cleanup of ParsedStateMachine unused
  code.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2639 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed wrong return value
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2638 ce417995-dfc9-0310-95a0-acdaff106893
* Small improvements, added program listing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2637 ce417995-dfc9-0310-95a0-acdaff106893
* Better finished detection in step mode
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2636 ce417995-dfc9-0310-95a0-acdaff106893
* Splitted DataSourceBase class in separate file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2634 ce417995-dfc9-0310-95a0-acdaff106893
* Fix wrongfully implemented division by zero prevention for integers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2611 ce417995-dfc9-0310-95a0-acdaff106893
* Added string constructor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2610 ce417995-dfc9-0310-95a0-acdaff106893
* Test for TemplateFactory functions
  DispatchTest also checks for dispatching commands
  Fixed some memleaks in test cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2609 ce417995-dfc9-0310-95a0-acdaff106893
* Added emacts tags generation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2608 ce417995-dfc9-0310-95a0-acdaff106893
* ProgramStatus to string methods were moved to Processor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2607 ce417995-dfc9-0310-95a0-acdaff106893
* "spoiled my weekend with coding-patch" :
  * Removed any 'known' (valgrind) memleaks from Program and SM parsers.
  * Applied the AdaptDataSource infrastructure into Operators and TemplateFactories
  * Fixed string assignment capacity change bug
  * Better memory allocation strategies for parser helper classes
  * TaskBrowser improved with 'list progname' command
  * Processor deletes present programs upon destruction
  * Use DataSourceBase::shared_ptr instead of DataSourceBase* whereever possible
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2606 ce417995-dfc9-0310-95a0-acdaff106893
* Stop TimeService if still running.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2605 ce417995-dfc9-0310-95a0-acdaff106893
* Added begin() and end() to PropertyBag
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2604 ce417995-dfc9-0310-95a0-acdaff106893
* Doxy typo fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2603 ce417995-dfc9-0310-95a0-acdaff106893
* Added SimulationVelocitySensor to SimulationAxis class.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2592 ce417995-dfc9-0310-95a0-acdaff106893
* Removed data_number variable from VectorComposition.
  Added MultiVector decomposition for "const MultiVector&".
  Fixed destructor bug in nAxesGenerator components when properties are not read.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2586 ce417995-dfc9-0310-95a0-acdaff106893
* Do not distribute pdfs, small faq update for Linux config
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2584 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2583 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2582 ce417995-dfc9-0310-95a0-acdaff106893
* ComponentConfigurator is no longer a friend.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2581 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2580 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen updates. Fails to document TemplateMemberFactory though :-(
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2579 ce417995-dfc9-0310-95a0-acdaff106893
* Add dependency on OROPKG_SUPPORT_READLINE
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2578 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug in MultiVector composition/decomposition
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2576 ce417995-dfc9-0310-95a0-acdaff106893
* Bugfix in compose and decomposeProperty of an std::vector
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2575 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed return value bug in composeProperty of a Frame.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2572 ce417995-dfc9-0310-95a0-acdaff106893
* No longer use localstore of components. it is private now.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2571 ce417995-dfc9-0310-95a0-acdaff106893
* Fix crash on double add of same value/property
  Fix non-removal of properties when component is unloaded from PropertyExtension
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2570 ce417995-dfc9-0310-95a0-acdaff106893
* small fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2558 ce417995-dfc9-0310-95a0-acdaff106893
* Redirect confusing conflict messages to /dev/null
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2556 ce417995-dfc9-0310-95a0-acdaff106893
* Fix typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2554 ce417995-dfc9-0310-95a0-acdaff106893
* Add gcc to supports for dist
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2552 ce417995-dfc9-0310-95a0-acdaff106893
* Minor adaptations to GCC version detection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2549 ce417995-dfc9-0310-95a0-acdaff106893
* Wrapped #pragma interface in a macro : ORO_PRAGMA_INTERFACE
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2547 ce417995-dfc9-0310-95a0-acdaff106893
* GCC 4.0 support + PRAGMA_INTERFACE macro
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2546 ce417995-dfc9-0310-95a0-acdaff106893
* Detect gcc and compiler flags
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2545 ce417995-dfc9-0310-95a0-acdaff106893
* Detect GCC version and compiler flags
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2544 ce417995-dfc9-0310-95a0-acdaff106893
* Fix copy/paste bug causing segfault
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2543 ce417995-dfc9-0310-95a0-acdaff106893
* Component Properties in Kernel's TC
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2542 ce417995-dfc9-0310-95a0-acdaff106893
* Re-add the DEFAULT_INIT option for frames
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2541 ce417995-dfc9-0310-95a0-acdaff106893
* Added Component Properties to TaskContext
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2540 ce417995-dfc9-0310-95a0-acdaff106893
* * Operators : Do not allow integer div by zero to terminate application, return zero instead
  * TB : TAB complete on this and show PropertyBag with objects.
  * PeerParser : fix advance_on_error not set to zero bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2539 ce417995-dfc9-0310-95a0-acdaff106893
* small layout fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2533 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed dot-operator for 'DataCall' expressions.Small layout changes for TB
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2532 ce417995-dfc9-0310-95a0-acdaff106893
* Fix marshalling of rotations according to configtool
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2531 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed updating of property files for composite types
  better error reporting when updating properties
  Fixed cpf marshaller wrt descriptions of structs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2530 ce417995-dfc9-0310-95a0-acdaff106893
* Small changes + improved output of TB wrt Attributes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2529 ce417995-dfc9-0310-95a0-acdaff106893
* only make jpgs from user pngs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2527 ce417995-dfc9-0310-95a0-acdaff106893
* small updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2526 ce417995-dfc9-0310-95a0-acdaff106893
* * Fix refresh() for PropertyBag updating
  * TB shows values of attributes
  * More verbose error reporting.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2525 ce417995-dfc9-0310-95a0-acdaff106893
* Updated installation manual with some screenshots
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2524 ce417995-dfc9-0310-95a0-acdaff106893
* Added LGPL Headers to new files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2523 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen fix and improved comedi detection help message
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2522 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed Comedi detection with default path
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2521 ce417995-dfc9-0310-95a0-acdaff106893
* Enable Linux Modules, but set default include path to
  big warning message
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2520 ce417995-dfc9-0310-95a0-acdaff106893
* Transition to gif files for PDF output.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2518 ce417995-dfc9-0310-95a0-acdaff106893
* Fix incompatible pointer types
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2517 ce417995-dfc9-0310-95a0-acdaff106893
* Added OROBLD_OS_EXTRA_CFLAGS for RTAI include dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2516 ce417995-dfc9-0310-95a0-acdaff106893
* Added K600
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2515 ce417995-dfc9-0310-95a0-acdaff106893
* Added link to OrocosOverview-05-05.pdf
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2513 ce417995-dfc9-0310-95a0-acdaff106893
* Removed old file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2511 ce417995-dfc9-0310-95a0-acdaff106893
* * Moved doxygen to build dir
  * Improved ecos tools use in makefile
  * Improved pkg upgrading
  * Added release notes for 0.20.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2510 ce417995-dfc9-0310-95a0-acdaff106893
* Prepare docs for Orocos 0.20.0 release
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2509 ce417995-dfc9-0310-95a0-acdaff106893
* update to latest scripts for release 0.20.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2508 ce417995-dfc9-0310-95a0-acdaff106893
* Fix tasks tests : remove sim thread
  fix property tests : include geometry headers
  Added property script-access test in typestest
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2507 ce417995-dfc9-0310-95a0-acdaff106893
* Moved out doxygen into build dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2506 ce417995-dfc9-0310-95a0-acdaff106893
* Namespace docs update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2505 ce417995-dfc9-0310-95a0-acdaff106893
* Updated Estimators to access of Outputs (Expects<>)
  added nbOfChannels methods to sensors/effectors
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2504 ce417995-dfc9-0310-95a0-acdaff106893
* BaseComponents :
  * Updated estimator to read outputs of T-1
  * updated docs for the two controller models
  (input-centric/model-centric) which we support
  Kernel+Extensions :
  * add Properties to TC
  * property-refresh commands
  * fixed possible crashes in KernelConfig
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2503 ce417995-dfc9-0310-95a0-acdaff106893
* Templates updated to new naming scheme ORTCS/ ORCS
  / control-framework / doxygen docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2502 ce417995-dfc9-0310-95a0-acdaff106893
* namespace doc update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2501 ce417995-dfc9-0310-95a0-acdaff106893
* Property Integration :
  * Added PropertyParser to allow scripts to access Properties
  * TB displays Properties
  * docs updated to reflect this
  * Other parsers adapted to integrate propertyparser
  Misc :
  * dot-operator docs
  * GenericTC has virtuals
  * removed some nonsense keywords from reserved keywords
  * Improved parsing+executing of 'typed stuff' in TB
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2500 ce417995-dfc9-0310-95a0-acdaff106893
* Small fixes, doxygen updates and propertyloader uses
  default marshaller from corelib.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2499 ce417995-dfc9-0310-95a0-acdaff106893
* Updated TB section
  Corrected overall typos, improved consistency. Properties
  integration documented
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2498 ce417995-dfc9-0310-95a0-acdaff106893
* Small updates wrt ProgramLoader
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2497 ce417995-dfc9-0310-95a0-acdaff106893
* Moderate cleanups :
  * added operator== support for frames + option to default
  to Equal() in cdl
  * Namespace doc update
  * MotionProperties report errors better.
  * Compile more files by default, since headers are installed
  anyway
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2496 ce417995-dfc9-0310-95a0-acdaff106893
* dependencies update, namespace docs improved
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2495 ce417995-dfc9-0310-95a0-acdaff106893
* ThreadScope support for comedi devices
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2494 ce417995-dfc9-0310-95a0-acdaff106893
* update KM to compile cleanly under gnu/linux
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2493 ce417995-dfc9-0310-95a0-acdaff106893
* Added utility classes for creating dig in/out device
  drivers (thread-safe). namespace+doxygen docs updated
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2492 ce417995-dfc9-0310-95a0-acdaff106893
* Added ParallelPort driver. Can be used as ThreadScope
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2491 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2490 ce417995-dfc9-0310-95a0-acdaff106893
* DOC: added private eventprocessor, opened PeriodicTask,
  expanded Property section, updated Event section for
  correctness, DataSource info in Buffers section
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2489 ce417995-dfc9-0310-95a0-acdaff106893
* Added PropertyBag as type
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2488 ce417995-dfc9-0310-95a0-acdaff106893
* Better namespace doc for corelib
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2487 ce417995-dfc9-0310-95a0-acdaff106893
* Added nbOfExporters querry to decide on usage of a reportserver
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2486 ce417995-dfc9-0310-95a0-acdaff106893
* Small doxygen updates, added deprecated tags
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2485 ce417995-dfc9-0310-95a0-acdaff106893
* Went through the marshallers. CPF remains the most reliable one,
  other remain somewhat broken/untested.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2484 ce417995-dfc9-0310-95a0-acdaff106893
* * Split PropertyBag impl to cxx file
  * Added Property<MultiVector> composition functions
  * Auto-detect geometry properties in CDL file
  * doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2483 ce417995-dfc9-0310-95a0-acdaff106893
* processor() was renamed to getEventProcessor()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2482 ce417995-dfc9-0310-95a0-acdaff106893
* *Added private EventProcessor support for PeriodicTasks.
  *Moved TaskTimer* to detail namespace
  *TaskInterface::processor() renamed to ..::getEventProcessor()
  *re-added TaskInterface::thread() method
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2481 ce417995-dfc9-0310-95a0-acdaff106893
* The big ORO_OS refactoring !
  * All C++ classes are now in 'common'
  * only C functions in os-specific dir
  * CDL : Compiler flags etc moved to common
  * ThreadInterface for periodic and single
  * Thread-Scope support
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2480 ce417995-dfc9-0310-95a0-acdaff106893
* fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2468 ce417995-dfc9-0310-95a0-acdaff106893
* added some comments
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2463 ce417995-dfc9-0310-95a0-acdaff106893
* fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2462 ce417995-dfc9-0310-95a0-acdaff106893
* fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2461 ce417995-dfc9-0310-95a0-acdaff106893
* fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2460 ce417995-dfc9-0310-95a0-acdaff106893
* use oro_logger instead of cerr
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2458 ce417995-dfc9-0310-95a0-acdaff106893
* - rename datatypes
  - fix bug with reference frames
  - use orocos logger instead of cerr
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2456 ce417995-dfc9-0310-95a0-acdaff106893
* remove conversion warning
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2436 ce417995-dfc9-0310-95a0-acdaff106893
* 0.20.0 updates, added testing section to faq
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2435 ce417995-dfc9-0310-95a0-acdaff106893
* Added marshalling to core services
  namespace in PSM, breakloop improvement in ST
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2434 ce417995-dfc9-0310-95a0-acdaff106893
* check-header fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2433 ce417995-dfc9-0310-95a0-acdaff106893
* Documented rt_std namespace
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2432 ce417995-dfc9-0310-95a0-acdaff106893
* Moved more stuff to detail, exclude cxx files from doxygen parsing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2431 ce417995-dfc9-0310-95a0-acdaff106893
* Moved more classes to detail namespace
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2430 ce417995-dfc9-0310-95a0-acdaff106893
* Moved most parsers and implementation classes to namespace detail
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2429 ce417995-dfc9-0310-95a0-acdaff106893
* Moved some user-hidden classes to namespace detail
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2428 ce417995-dfc9-0310-95a0-acdaff106893
* small doc updates, added gnulinux to doxygen
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2427 ce417995-dfc9-0310-95a0-acdaff106893
* update to RTCServices vs RCSoftware
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2426 ce417995-dfc9-0310-95a0-acdaff106893
* changed robot_software to robot_control
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2425 ce417995-dfc9-0310-95a0-acdaff106893
* Added LGPL Headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2424 ce417995-dfc9-0310-95a0-acdaff106893
* small dependency updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2423 ce417995-dfc9-0310-95a0-acdaff106893
* Added control_services and robot_software make targets.
  fixed event test
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2422 ce417995-dfc9-0310-95a0-acdaff106893
* Typo fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2421 ce417995-dfc9-0310-95a0-acdaff106893
* update to higherlevel classes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2420 ce417995-dfc9-0310-95a0-acdaff106893
* Small Event update return values
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2419 ce417995-dfc9-0310-95a0-acdaff106893
* Updated TB section
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2417 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed param bug in PSM
  removed expect identifier in valuechangeparser
  added Ctrl-C detection to TB
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2416 ce417995-dfc9-0310-95a0-acdaff106893
* updated to taskbrowser rework
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2415 ce417995-dfc9-0310-95a0-acdaff106893
* Use ProgramLoader in ExecutionExtension and use parser directly to catch
  exceptions in directkernelinterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2413 ce417995-dfc9-0310-95a0-acdaff106893
* Renamed executeFunction to loadFunction for consistency
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2412 ce417995-dfc9-0310-95a0-acdaff106893
* added getText() function to StateMachine
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2411 ce417995-dfc9-0310-95a0-acdaff106893
* Added display support for Double6D
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2410 ce417995-dfc9-0310-95a0-acdaff106893
* Bug hunting for functions.
  * Implemented 'variable' instantiation for state machines and programs
  * ProgramLoader check for validness of file.
  * Seems to work all now.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2408 ce417995-dfc9-0310-95a0-acdaff106893
* Removed HMIReadline & HMIConsoleOutput
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2407 ce417995-dfc9-0310-95a0-acdaff106893
* * TaskBrowser tracks failure/success of commands
  * moved MapDataSourceFactory to task_context
  * AssignCommand from const to non const attributes
  * TaskBrowser can better classify exceptions of valueparser
  Added fatal semantic exception type.
  * Some internal parser classes moved to detail.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2406 ce417995-dfc9-0310-95a0-acdaff106893
* Kernel DataObjects are now available in the TaskBrowser
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2405 ce417995-dfc9-0310-95a0-acdaff106893
* Removed the deprecated property operations.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2404 ce417995-dfc9-0310-95a0-acdaff106893
* Made DataObjects inherit from AssignableDataSource
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2403 ce417995-dfc9-0310-95a0-acdaff106893
* Added extra types for getType()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2402 ce417995-dfc9-0310-95a0-acdaff106893
* Fix segfault in trying to add 'task' as states peer.
  Add const correctness to StateMachine
  Add getStateMachine() to Processor.
  Virtual start/stop of GTC
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2401 ce417995-dfc9-0310-95a0-acdaff106893
* DataSource support for Properties
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2398 ce417995-dfc9-0310-95a0-acdaff106893
* Improved type deduction for DataSources
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2397 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug in include header
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2396 ce417995-dfc9-0310-95a0-acdaff106893
* Several small bugfixes. Avoid memory allocation in Reporting
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2395 ce417995-dfc9-0310-95a0-acdaff106893
* Finalizing usability improvement of TaskContexts
  * Added GenericTaskContext
  * Added PropertyLoader, ProgramLoader
  * Property support for attributerepository
  * fixed TaskBrowser ignoring commands
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2394 ce417995-dfc9-0310-95a0-acdaff106893
* Improved event test cases
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2390 ce417995-dfc9-0310-95a0-acdaff106893
* Improve geometry input/output streaming functions
  Improve reading property formats for rotations
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2388 ce417995-dfc9-0310-95a0-acdaff106893
* Update to new DataSource in CoreLib
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2387 ce417995-dfc9-0310-95a0-acdaff106893
* The Post-Barcelona parser rework. Code works, need to update docs:
  This patch is waaaayy to big, but need it on server.
  * .dot operator for geometry
  * reworked TaskBrowser
  * DataSource interfaces moved to CoreLib
  * AttributeRepository reworked
  * Numerous bugfixes along the line
  * working on providing some standard functions to interact
  more easily on the TaskContext level.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2386 ce417995-dfc9-0310-95a0-acdaff106893
* Property update/copy/refresh commands and DataSource
  integration (step 1 in removing visitor)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2385 ce417995-dfc9-0310-95a0-acdaff106893
* Moved the DataSource interfaces into CoreLib
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2384 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup double implementation of getTask()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2383 ce417995-dfc9-0310-95a0-acdaff106893
* Kind-of sentry files to indicate which os we are using
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2382 ce417995-dfc9-0310-95a0-acdaff106893
* Fix deadlock bug when running was not set correctly
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2381 ce417995-dfc9-0310-95a0-acdaff106893
* Improved Asyn Event handling in TaskThreads.
  Split+Tested TaskNonPeriodic
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2380 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed big bugs in Syn/asyn Event handling with more
  than 1 argument. Reject asyn events if processor not
  running.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2379 ce417995-dfc9-0310-95a0-acdaff106893
* Improved CalibrationInterface with default implementation.
  Added Calibration script commands to Axis components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2363 ce417995-dfc9-0310-95a0-acdaff106893
* adapted AxisSensor to new AxisInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2362 ce417995-dfc9-0310-95a0-acdaff106893
* Extended AxisInterface with couters and digital inputs, to
  solve the 'homingswitch' problem.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2361 ce417995-dfc9-0310-95a0-acdaff106893
* Use Logger for log messages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2360 ce417995-dfc9-0310-95a0-acdaff106893
* Add rtos_printf to fosi.c
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2359 ce417995-dfc9-0310-95a0-acdaff106893
* Added trajectory for the amplitude
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2346 ce417995-dfc9-0310-95a0-acdaff106893
* Slightly better dependency checking for doc building
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2345 ce417995-dfc9-0310-95a0-acdaff106893
* Added getNSecs() methods to TimeService
  ( patch from Svdb )
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2344 ce417995-dfc9-0310-95a0-acdaff106893
* Added support for gettime of Nsecs.
  ( Patch from Svdb )
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2343 ce417995-dfc9-0310-95a0-acdaff106893
* Added log() methods to HMIConsoleOutput
  Fixed readline implementation to adapt to changes in parsers
  (code copied from TaskBrowser).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2342 ce417995-dfc9-0310-95a0-acdaff106893
* Properly implemented accept/reject of commands and methods
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2341 ce417995-dfc9-0310-95a0-acdaff106893
* slight restructuring of main doxygen page
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2340 ce417995-dfc9-0310-95a0-acdaff106893
* Implement breakLoop in Processor and update some random docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2339 ce417995-dfc9-0310-95a0-acdaff106893
* Implement breakLoop in tasks and events
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2338 ce417995-dfc9-0310-95a0-acdaff106893
* Added and documented the breakLoop() function
  Documented porting of Orocos
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2337 ce417995-dfc9-0310-95a0-acdaff106893
* bye bye components!
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2333 ce417995-dfc9-0310-95a0-acdaff106893
* naxis should not depend on Krypton
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2332 ce417995-dfc9-0310-95a0-acdaff106893
* fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2331 ce417995-dfc9-0310-95a0-acdaff106893
* add testing version of Krypton sensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2330 ce417995-dfc9-0310-95a0-acdaff106893
* add testing version of krypton sensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2329 ce417995-dfc9-0310-95a0-acdaff106893
* nAxesGeneratorCartesianSin up and working
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2327 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed recursive inError
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2324 ce417995-dfc9-0310-95a0-acdaff106893
* Added inError datasource to parstedstatemachine
  small error msg change in TB
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2320 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed bugs in nAxesGeneratorCartesianSin
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2314 ce417995-dfc9-0310-95a0-acdaff106893
* new generator to move the end-effector in a 3D-lissajous with fixed orientation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2313 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed de reporter crash on kernel.stop() + kernel.start().
  Thanks for 'reporting' Wim !
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2312 ce417995-dfc9-0310-95a0-acdaff106893
* fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2308 ce417995-dfc9-0310-95a0-acdaff106893
* add documentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2307 ce417995-dfc9-0310-95a0-acdaff106893
* add documentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2306 ce417995-dfc9-0310-95a0-acdaff106893
* Added refresh() versus update() semantics of Properties, allowing
  more fine grained control of what the user really wants in case the
  property contains a property bag.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2304 ce417995-dfc9-0310-95a0-acdaff106893
* Added GPL Licenses to tests
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2295 ce417995-dfc9-0310-95a0-acdaff106893
* Add LGPL Licenses to files without license info.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2294 ce417995-dfc9-0310-95a0-acdaff106893
* Further syntax fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2293 ce417995-dfc9-0310-95a0-acdaff106893
* script syntax updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2292 ce417995-dfc9-0310-95a0-acdaff106893
* rename ticksGet to getTicks
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2291 ce417995-dfc9-0310-95a0-acdaff106893
* Fix columns in arguments section
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2290 ce417995-dfc9-0310-95a0-acdaff106893
* safer check-headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2289 ce417995-dfc9-0310-95a0-acdaff106893
* more info about arguments
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2287 ce417995-dfc9-0310-95a0-acdaff106893
* rename kuka361 to Kuka361
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2285 ce417995-dfc9-0310-95a0-acdaff106893
* more informative log
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2284 ce417995-dfc9-0310-95a0-acdaff106893
* use orocos logger instead of cout
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2283 ce417995-dfc9-0310-95a0-acdaff106893
* remove assert(0)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2281 ce417995-dfc9-0310-95a0-acdaff106893
* Update propoperty description if none present
  Fix description duplication in CPFDemarshaller in case none given.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2279 ce417995-dfc9-0310-95a0-acdaff106893
* fixed wrong installer url and minor editing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2277 ce417995-dfc9-0310-95a0-acdaff106893
* update installer.db paths
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2276 ce417995-dfc9-0310-95a0-acdaff106893
* Updated package locations
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2275 ce417995-dfc9-0310-95a0-acdaff106893
* Added attribute browsing and completion
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2273 ce417995-dfc9-0310-95a0-acdaff106893
* Doc cleanups, added figures to Events and Commands
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2269 ce417995-dfc9-0310-95a0-acdaff106893
* is replaced by kinematicsfactory
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2268 ce417995-dfc9-0310-95a0-acdaff106893
* it works!!!!
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2267 ce417995-dfc9-0310-95a0-acdaff106893
* remvoe
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2264 ce417995-dfc9-0310-95a0-acdaff106893
* oops, forgot some name-changes again
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2262 ce417995-dfc9-0310-95a0-acdaff106893
* changing names ZXXZXZInverse to mZXXmZXmZ
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2261 ce417995-dfc9-0310-95a0-acdaff106893
* changing names
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2260 ce417995-dfc9-0310-95a0-acdaff106893
* name changed and hpp added
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2259 ce417995-dfc9-0310-95a0-acdaff106893
* Added kinematics properties of kuka160
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2257 ce417995-dfc9-0310-95a0-acdaff106893
* Corrected kinematics ZXXZXZ
  Added ZXXZXZInverse for robots with inverse Z-axes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2256 ce417995-dfc9-0310-95a0-acdaff106893
* Remove no-good section with this.pause()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2255 ce417995-dfc9-0310-95a0-acdaff106893
* make Info msg an Error
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2254 ce417995-dfc9-0310-95a0-acdaff106893
* rename select funtions to selectComponent
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2253 ce417995-dfc9-0310-95a0-acdaff106893
* Fix RTAI version number logging
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2252 ce417995-dfc9-0310-95a0-acdaff106893
* Fix RTAI version number extraction
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2251 ce417995-dfc9-0310-95a0-acdaff106893
* FIX : Add 'task' peer to state machines
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2250 ce417995-dfc9-0310-95a0-acdaff106893
* Better logging of what happens + write all props writes all properties.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2249 ce417995-dfc9-0310-95a0-acdaff106893
* update versions numbers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2245 ce417995-dfc9-0310-95a0-acdaff106893
* fix install bug caused by make distcheck adaptations
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2244 ce417995-dfc9-0310-95a0-acdaff106893
* add kernelclient and requeststate changes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2243 ce417995-dfc9-0310-95a0-acdaff106893
* fix typo ms->s
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2242 ce417995-dfc9-0310-95a0-acdaff106893
* split tasks tests off from core tests
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2241 ce417995-dfc9-0310-95a0-acdaff106893
* updated component names section
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2240 ce417995-dfc9-0310-95a0-acdaff106893
* define ORO_RTAI_CONFIG_VERSION
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2239 ce417995-dfc9-0310-95a0-acdaff106893
* Add version info to Logger output
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2232 ce417995-dfc9-0310-95a0-acdaff106893
* simpeler appstack view
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2226 ce417995-dfc9-0310-95a0-acdaff106893
* break statement and request mode tests
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2225 ce417995-dfc9-0310-95a0-acdaff106893
* Add a maximum number of simulation steps in SimulationThread.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2224 ce417995-dfc9-0310-95a0-acdaff106893
* processor functions got renamed
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2223 ce417995-dfc9-0310-95a0-acdaff106893
* Added break statement documentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2222 ce417995-dfc9-0310-95a0-acdaff106893
* Added 'break' syntax.
  Added on request state change semantics.
  Fixed TaskBrowser to show strings and arrays.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2221 ce417995-dfc9-0310-95a0-acdaff106893
* Added support for on request mode in SM.
  Added break statement in while/for loops
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2220 ce417995-dfc9-0310-95a0-acdaff106893
* Add functors for unary command_ds. Added request mode
  in taskcontext docs. Fixed gcc4.0 error.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2219 ce417995-dfc9-0310-95a0-acdaff106893
* remove old file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2216 ce417995-dfc9-0310-95a0-acdaff106893
* Doc and release testing fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2214 ce417995-dfc9-0310-95a0-acdaff106893
* added more changes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2203 ce417995-dfc9-0310-95a0-acdaff106893
* the big Control Framework patch.
  * Fixed some reporing / property bugs
  * load/select function renames
  * Component Port refactoring
  * Aspect is now Facet
  * Component preloading + LockFree DObj in StandardControlKernel
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2202 ce417995-dfc9-0310-95a0-acdaff106893
* Added virtual destructor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2201 ce417995-dfc9-0310-95a0-acdaff106893
* gcc 4.0 fixes, header checks
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2200 ce417995-dfc9-0310-95a0-acdaff106893
* Removed compiler warning
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2199 ce417995-dfc9-0310-95a0-acdaff106893
* Remove deprecated method from nameserver, add core documentation
  for non periodic tasks
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2198 ce417995-dfc9-0310-95a0-acdaff106893
* Changed deprecated use of Nameserver
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2197 ce417995-dfc9-0310-95a0-acdaff106893
* More header refactoring, not there yet though
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2196 ce417995-dfc9-0310-95a0-acdaff106893
* SingleThread loop() semantics
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2193 ce417995-dfc9-0310-95a0-acdaff106893
* Fix SingleThread usage : replace step() by loop()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2192 ce417995-dfc9-0310-95a0-acdaff106893
* tidying up the docbook paths and Makefiles
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2188 ce417995-dfc9-0310-95a0-acdaff106893
* renamed deprecated ticks/secondsGet() fcns
  omitted LXRT cornercase conversions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2187 ce417995-dfc9-0310-95a0-acdaff106893
* Test updates for TaskNonPeriodics
  Readded function nested call test
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2186 ce417995-dfc9-0310-95a0-acdaff106893
* minor code doc fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2185 ce417995-dfc9-0310-95a0-acdaff106893
* * Made the CompletionProcessor a non periodic task
  * EventProcessor testing, using shared_ptr to allocate semaphores.
  * Add default timer in TimerThread.
  * Update corelib docs for nonperiodic tasks.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2184 ce417995-dfc9-0310-95a0-acdaff106893
* Fix shameless copy constructor bug in CommandComposite
  Small fixes for function arguments parsing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2183 ce417995-dfc9-0310-95a0-acdaff106893
* * Added testcase for blocking tasks
  * Added testcases for call vs do function()
  * Added testcase for blocking eventprocessor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2182 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed non-shallow copied TaskAttributes ( had to modify copy to non const)
  Renamed some parser types to parser names again
  Could not locate the call in call bug, it's still present
  Made the processor have a non periodic (blocking) mode
  Added addAttribute and addConstant helper functions to attributerepos.
  Fixed FunctionGraph::copy to avoid unused start/exit nodes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2181 ce417995-dfc9-0310-95a0-acdaff106893
* Added non periodic Task and non periodic event processor.
  made use of the new loop() method in RunnableInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2180 ce417995-dfc9-0310-95a0-acdaff106893
* Added the C++ Semaphore implementation and fosi functions
  for lxrt and gnulinux
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2179 ce417995-dfc9-0310-95a0-acdaff106893
* fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2176 ce417995-dfc9-0310-95a0-acdaff106893
* add init method
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2174 ce417995-dfc9-0310-95a0-acdaff106893
* add function to get last 'drive' value
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2170 ce417995-dfc9-0310-95a0-acdaff106893
* 2 new funciions: applyvelocity and gotovelocity
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2169 ce417995-dfc9-0310-95a0-acdaff106893
* add function to get last 'drive' value
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2168 ce417995-dfc9-0310-95a0-acdaff106893
* nothing changed.. stupid svn
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2167 ce417995-dfc9-0310-95a0-acdaff106893
* - when trajcetory is finished, it stops smoothly
  - cleanup changes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2166 ce417995-dfc9-0310-95a0-acdaff106893
* Warning deleted in ComediEncoder.cxx
  added reset()-function to nAxesControllerVel
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2163 ce417995-dfc9-0310-95a0-acdaff106893
* fix export function deletion
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2154 ce417995-dfc9-0310-95a0-acdaff106893
* Extended program and function tests
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2152 ce417995-dfc9-0310-95a0-acdaff106893
* commented out some very annoying printouts
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2149 ce417995-dfc9-0310-95a0-acdaff106893
* writeSensor added for homing-use
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2148 ce417995-dfc9-0310-95a0-acdaff106893
* store my release scripts in svn
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2144 ce417995-dfc9-0310-95a0-acdaff106893
* working nAxesGeneratorVel
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2137 ce417995-dfc9-0310-95a0-acdaff106893
* add comment
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2133 ce417995-dfc9-0310-95a0-acdaff106893
* Trapezoidal traject added
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2131 ce417995-dfc9-0310-95a0-acdaff106893
* - use sleep time before measuring offset on joint velocities.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2130 ce417995-dfc9-0310-95a0-acdaff106893
* new algorithm for offset calibration
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2124 ce417995-dfc9-0310-95a0-acdaff106893
* new method for offset calibration
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2122 ce417995-dfc9-0310-95a0-acdaff106893
* - rename commands
  - new implementation to measure offsets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2118 ce417995-dfc9-0310-95a0-acdaff106893
* Added oblibatory missing file in previous commit
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2115 ce417995-dfc9-0310-95a0-acdaff106893
* Property Demarshalling and PropertyExtension Cleanup
  * Removed unnessecary template from CPFDemarshaller,
  resolve filename internally
  * Add Property Commands to PropertyExtension
  * Tidying up + updating the kernel doc
  * added ControlKernelInterface::base() method to resolve KernelBaseFunction
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2114 ce417995-dfc9-0310-95a0-acdaff106893
* More robust error handling if dispatch is rejected by processor.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2113 ce417995-dfc9-0310-95a0-acdaff106893
* Initialise Effector Input and Model ports during load.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2112 ce417995-dfc9-0310-95a0-acdaff106893
* Fix crash when var is not assigned an initial value
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2101 ce417995-dfc9-0310-95a0-acdaff106893
* nAxesGeneratorVel added
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2090 ce417995-dfc9-0310-95a0-acdaff106893
* nAxisGeneratorVel added
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2087 ce417995-dfc9-0310-95a0-acdaff106893
* *Entities : orocos.ent roundup, redirect all references to my
  webpage and rewrite with the catalog.xml files.
  *Makefiles : use one common docrules.mak file for both
  top-level manuals as packages manuals.
  *The packages directory got its own catalog file.
  *images/*.jpg for pdf are fetched from my webpage, since I can not
  find another way to rewrite the uri in the xsl using a catalog :-(
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2085 ce417995-dfc9-0310-95a0-acdaff106893
* Includes cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2084 ce417995-dfc9-0310-95a0-acdaff106893
* Add Property.hpp include to allow instantiation of
  explicit templates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2079 ce417995-dfc9-0310-95a0-acdaff106893
* Add PropertyIntrospection.hpp back in Property.hpp, to avoid compilation errors
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2078 ce417995-dfc9-0310-95a0-acdaff106893
* move jr3 drivers to hardware hotspots
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2077 ce417995-dfc9-0310-95a0-acdaff106893
* removed _very\_ old doxygen file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2076 ce417995-dfc9-0310-95a0-acdaff106893
* Added property decomposition test
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2075 ce417995-dfc9-0310-95a0-acdaff106893
* Re-ordering of the headers for PropertyIntrospection. This
  patch forces you to include PropertyIntrospection.hpp if you intend to
  do introspection. All marshallers etc include this file by themselves
  of course, so impact on users should be minimal
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2073 ce417995-dfc9-0310-95a0-acdaff106893
* remove implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2067 ce417995-dfc9-0310-95a0-acdaff106893
* make code cleaner: remove
  "Sensor<writes<nAxesSensorCartesianPosForceInput_pos_force>>::" before
  Input:Obj()->Get("Wrench", _force_out_DOI))
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2066 ce417995-dfc9-0310-95a0-acdaff106893
* show type of data that cannot be reported
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2063 ce417995-dfc9-0310-95a0-acdaff106893
* fix: use description of std::vector<>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2061 ce417995-dfc9-0310-95a0-acdaff106893
* add using namespace oro_os
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2050 ce417995-dfc9-0310-95a0-acdaff106893
* Add correct include of TimerThread.hpp
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2049 ce417995-dfc9-0310-95a0-acdaff106893
* Try to fix endless looping escape() function
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2048 ce417995-dfc9-0310-95a0-acdaff106893
* Aiaiaiai... this was a pretty stupid one :)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2047 ce417995-dfc9-0310-95a0-acdaff106893
* make check more exact: == instead of >=
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2046 ce417995-dfc9-0310-95a0-acdaff106893
* Fix rename of TaskExecution to TimerThread
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2045 ce417995-dfc9-0310-95a0-acdaff106893
* nicer doc-dist and doc-clean targets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2044 ce417995-dfc9-0310-95a0-acdaff106893
* Completely new doc generation build system.
  * Added XML Catalogs for URI managing
  * Added XML Entity file for entity managing
  * Improved Makefile management by using docrules.mak file
  * Removed all image 'type' info and moved that into the stylesheets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2043 ce417995-dfc9-0310-95a0-acdaff106893
* package-wide doc generation rules
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2042 ce417995-dfc9-0310-95a0-acdaff106893
* Tweak,tweak,tweak,fix,fix,fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2041 ce417995-dfc9-0310-95a0-acdaff106893
* git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2040 ce417995-dfc9-0310-95a0-acdaff106893
* *Only create html version of faq/changes
  *no longer generate orocos-manual.xml, use catalog instead
  for parameterising.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2039 ce417995-dfc9-0310-95a0-acdaff106893
* *use default extension parameter in xsl to select
  which imagetype we are using
  *fix faq comment errors
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2038 ce417995-dfc9-0310-95a0-acdaff106893
* Added Forwarding problem comment
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2037 ce417995-dfc9-0310-95a0-acdaff106893
* Control Framework dia
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2036 ce417995-dfc9-0310-95a0-acdaff106893
* improved, but not fully stabilised documentation generation changes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2035 ce417995-dfc9-0310-95a0-acdaff106893
* rename confusing TaskExecution to TimerThread
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2034 ce417995-dfc9-0310-95a0-acdaff106893
* Removed a #define __KERNEL_\_ bug.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2033 ce417995-dfc9-0310-95a0-acdaff106893
* export all properties that have been read
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2032 ce417995-dfc9-0310-95a0-acdaff106893
* export properties
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2029 ce417995-dfc9-0310-95a0-acdaff106893
* add function to get offsets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2028 ce417995-dfc9-0310-95a0-acdaff106893
* renamed Context to Machine
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2025 ce417995-dfc9-0310-95a0-acdaff106893
* Updated Orocos Overview Documentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2024 ce417995-dfc9-0310-95a0-acdaff106893
* make const&-compatible with new scripting
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2018 ce417995-dfc9-0310-95a0-acdaff106893
* Fix the headerfile include handling
  Lost many hours thanks to a silly copy and paste error! >:-D
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2016 ce417995-dfc9-0310-95a0-acdaff106893
* add include
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2014 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed non-null detection in character parser.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2010 ce417995-dfc9-0310-95a0-acdaff106893
* fixed stop/lock usage of AxisEffector
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2009 ce417995-dfc9-0310-95a0-acdaff106893
* Adapted tests to new processor semantics and
  added array/string type tests
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2007 ce417995-dfc9-0310-95a0-acdaff106893
* removed CORELIB_STATE
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2006 ce417995-dfc9-0310-95a0-acdaff106893
* removed STATES
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2005 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed stop/lock calling of axis
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2004 ce417995-dfc9-0310-95a0-acdaff106893
* Added operator== and operator!= and size storage to MultiVector
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2003 ce417995-dfc9-0310-95a0-acdaff106893
* * Add 'char' type to parser
  * Add array and string size hinting
  * Applied and fixed the const& for containers patch
  * Added double/int operators for convenience
  * Rewrote some type and operator functions to function objects
  * Cleanup of some includes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2002 ce417995-dfc9-0310-95a0-acdaff106893
* Fix broken ConditionOnce implementation.
  Split header and implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1987 ce417995-dfc9-0310-95a0-acdaff106893
* Axis _can\_ fire event when max drive value is exceeded.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1986 ce417995-dfc9-0310-95a0-acdaff106893
* git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1985 ce417995-dfc9-0310-95a0-acdaff106893
* git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1984 ce417995-dfc9-0310-95a0-acdaff106893
* main doxygen page update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1983 ce417995-dfc9-0310-95a0-acdaff106893
* separate manual for control applications
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1982 ce417995-dfc9-0310-95a0-acdaff106893
* Added test for reading/writing state vars
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1981 ce417995-dfc9-0310-95a0-acdaff106893
* Update documentation, parser doc refactoring.
  Removed pessimisations in Processor (ie lists and non-object functors).
  Added a resetting status for StateMachine
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1979 ce417995-dfc9-0310-95a0-acdaff106893
* move files to hardware hotspots
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1973 ce417995-dfc9-0310-95a0-acdaff106893
* use TaskContext for offset of WrenchSensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1971 ce417995-dfc9-0310-95a0-acdaff106893
* add TaksContext to JR3 WrenchSensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1967 ce417995-dfc9-0310-95a0-acdaff106893
* fixes to TaksContext
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1965 ce417995-dfc9-0310-95a0-acdaff106893
* add TaskContext to force sensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1964 ce417995-dfc9-0310-95a0-acdaff106893
* fix on commit Johan
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1963 ce417995-dfc9-0310-95a0-acdaff106893
* fix on commit Johan?
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1961 ce417995-dfc9-0310-95a0-acdaff106893
* Added ZXXZXZ.
  It compiles. Don't know if it works though.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1959 ce417995-dfc9-0310-95a0-acdaff106893
* Removed "using ORO_Corelib::Double6D" from .hpp files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1958 ce417995-dfc9-0310-95a0-acdaff106893
* * Fixed multiple bugs in CommandDispatch
  * Added task attribute setting
  * improved line numbering
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1957 ce417995-dfc9-0310-95a0-acdaff106893
* Removed "using ORO_Geometry::XXX" from MotionProperties.hpp with corresponding changes in the files that include that file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1955 ce417995-dfc9-0310-95a0-acdaff106893
* resolution as variable in construction
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1950 ce417995-dfc9-0310-95a0-acdaff106893
* Added limits to the maximum drive value.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1949 ce417995-dfc9-0310-95a0-acdaff106893
* fix typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1948 ce417995-dfc9-0310-95a0-acdaff106893
* use Wrench to set and add offsets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1945 ce417995-dfc9-0310-95a0-acdaff106893
* Added empty state test
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1944 ce417995-dfc9-0310-95a0-acdaff106893
* New handle() semantics, only handle if no transition succeeded.
  Line numbering fixes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1942 ce417995-dfc9-0310-95a0-acdaff106893
* fix rename to periodicThread
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1937 ce417995-dfc9-0310-95a0-acdaff106893
* fix error-recovery for StateMachines. Implement proper stop semantics.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1933 ce417995-dfc9-0310-95a0-acdaff106893
* remve debugging-cout
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1928 ce417995-dfc9-0310-95a0-acdaff106893
* another attempt at fixing line numbering of SM
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1927 ce417995-dfc9-0310-95a0-acdaff106893
* Use the ProgramGraphParser to parse entry/handle/exit bodies of
  StateMachines. This removes patch also Event stuff from the statemachine parser.
  From now on, all body content must be parsed by the ProgramGraphParser.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1925 ce417995-dfc9-0310-95a0-acdaff106893
* Rename SubContext and RootContext to SubMachine and RootMachine
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1924 ce417995-dfc9-0310-95a0-acdaff106893
* FIX copy line number on state->copy()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1923 ce417995-dfc9-0310-95a0-acdaff106893
* - fixes
  - cout for debugging
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1922 ce417995-dfc9-0310-95a0-acdaff106893
* fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1918 ce417995-dfc9-0310-95a0-acdaff106893
* The Big StateContext Refactoring
  * StateContext + StateContextTree --> StateMachine
  * All occurences of StateContext->StateMachine
  * Added non-atomic StateMachines
  * Removed corelib/state in favour of execution/processor's implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1916 ce417995-dfc9-0310-95a0-acdaff106893
* return line 5 instead of line -1
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1913 ce417995-dfc9-0310-95a0-acdaff106893
* add function to get line of state. Not working yet, just returns -1
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1912 ce417995-dfc9-0310-95a0-acdaff106893
* oef
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1911 ce417995-dfc9-0310-95a0-acdaff106893
* oef
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1910 ce417995-dfc9-0310-95a0-acdaff106893
* oeps
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1909 ce417995-dfc9-0310-95a0-acdaff106893
* oeps..
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1908 ce417995-dfc9-0310-95a0-acdaff106893
* *Add exception catching in SingleThread
  *change wrongfully protected members to private
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1903 ce417995-dfc9-0310-95a0-acdaff106893
* Adapt directkernelinterface to new method/command handling policy
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1901 ce417995-dfc9-0310-95a0-acdaff106893
* should _not\_ use internal variable of SingleThread class
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1900 ce417995-dfc9-0310-95a0-acdaff106893
* further build fixes for kernelserver, fix deps and wrong file
  name extension
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1896 ce417995-dfc9-0310-95a0-acdaff106893
* fix include path
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1895 ce417995-dfc9-0310-95a0-acdaff106893
* Added setKernel implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1892 ce417995-dfc9-0310-95a0-acdaff106893
* template cleanup, made one control kernel template
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1890 ce417995-dfc9-0310-95a0-acdaff106893
* fix header includes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1888 ce417995-dfc9-0310-95a0-acdaff106893
* added missing make target
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1887 ce417995-dfc9-0310-95a0-acdaff106893
* finally got rotten ecostools working
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1886 ce417995-dfc9-0310-95a0-acdaff106893
* File renames to make it work with ecos 8-/
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1885 ce417995-dfc9-0310-95a0-acdaff106893
* Import the kernel_server files which might be relevant.
  Their history goes back to the execution_client.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1884 ce417995-dfc9-0310-95a0-acdaff106893
* rename kernel_components to control_kernel
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1871 ce417995-dfc9-0310-95a0-acdaff106893
* fix constructor signature
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1870 ce417995-dfc9-0310-95a0-acdaff106893
* remove old baseclass initializer in constructor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1869 ce417995-dfc9-0310-95a0-acdaff106893
* change description of packages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1868 ce417995-dfc9-0310-95a0-acdaff106893
* delete (empty?) dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1867 ce417995-dfc9-0310-95a0-acdaff106893
* oei, foute commit.. will be fixed in a minute!
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1866 ce417995-dfc9-0310-95a0-acdaff106893
* moved to control_framework
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1865 ce417995-dfc9-0310-95a0-acdaff106893
* add control kernel components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1864 ce417995-dfc9-0310-95a0-acdaff106893
* rename
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1863 ce417995-dfc9-0310-95a0-acdaff106893
* added control kernel
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1862 ce417995-dfc9-0310-95a0-acdaff106893
* rename
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1861 ce417995-dfc9-0310-95a0-acdaff106893
* add new root folder for control kernel stuff
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1860 ce417995-dfc9-0310-95a0-acdaff106893
* resave dia files to 0.94
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1859 ce417995-dfc9-0310-95a0-acdaff106893
* update dia file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1858 ce417995-dfc9-0310-95a0-acdaff106893
* removed deprecated file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1857 ce417995-dfc9-0310-95a0-acdaff106893
* dia files review and save to 0.94 format
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1856 ce417995-dfc9-0310-95a0-acdaff106893
* dia files resave to dia 0.94
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1855 ce417995-dfc9-0310-95a0-acdaff106893
* dia files review
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1854 ce417995-dfc9-0310-95a0-acdaff106893
* dia files review
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1853 ce417995-dfc9-0310-95a0-acdaff106893
* remove heavily deprecated dia files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1852 ce417995-dfc9-0310-95a0-acdaff106893
* documentation update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1851 ce417995-dfc9-0310-95a0-acdaff106893
* doxygen facelift
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1850 ce417995-dfc9-0310-95a0-acdaff106893
* Updated documentation, removed deprecated file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1849 ce417995-dfc9-0310-95a0-acdaff106893
* fix Tasks typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1848 ce417995-dfc9-0310-95a0-acdaff106893
* Fix mailing list addresses, small faq update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1847 ce417995-dfc9-0310-95a0-acdaff106893
* Fix make html-dist
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1840 ce417995-dfc9-0310-95a0-acdaff106893
* Adapt all doc Makefiles to use the main orocos.xsl and orocos-html.xsl
  stylesheets, in order to have a more uniform layout
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1838 ce417995-dfc9-0310-95a0-acdaff106893
* Effector component reads from Inputs, Models and Outputs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1837 ce417995-dfc9-0310-95a0-acdaff106893
* effector now reads from Inputs, Models and Outputs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1836 ce417995-dfc9-0310-95a0-acdaff106893
* working force sensor calibration and online setting of mass properties
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1834 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed missing method/datasource functor-creators for 3 and 4 arguments
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1832 ce417995-dfc9-0310-95a0-acdaff106893
* log for rotation changes from eurler to RPY
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1831 ce417995-dfc9-0310-95a0-acdaff106893
* scripting uses RPY rotation instead of euler rotation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1829 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed the ecos.db corruption on make db
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1827 ce417995-dfc9-0310-95a0-acdaff106893
* Added test for find(PropertyBag, item)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1824 ce417995-dfc9-0310-95a0-acdaff106893
* Removed unnecessary sleep() in testfunction
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1823 ce417995-dfc9-0310-95a0-acdaff106893
* fix initialize of generator
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1822 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed find function
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1821 ce417995-dfc9-0310-95a0-acdaff106893
* Fix inverted command completion flags for stop() and deactivate()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1820 ce417995-dfc9-0310-95a0-acdaff106893
* make cout more clear
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1818 ce417995-dfc9-0310-95a0-acdaff106893
* Fix subtitle
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1814 ce417995-dfc9-0310-95a0-acdaff106893
* show task period
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1812 ce417995-dfc9-0310-95a0-acdaff106893
* fix missing ECOS_REPOSITORY
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1809 ce417995-dfc9-0310-95a0-acdaff106893
* Added ecosconfig export/import feature
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1808 ce417995-dfc9-0310-95a0-acdaff106893
* made version number an &entity;. Added ecosconfig import/export
  section for upgrading your orocos configuration.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1807 ce417995-dfc9-0310-95a0-acdaff106893
* OS interface requires one implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1806 ce417995-dfc9-0310-95a0-acdaff106893
* correct test-load relative to available time.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1805 ce417995-dfc9-0310-95a0-acdaff106893
* Fix a few cleanup-memleaks.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1804 ce417995-dfc9-0310-95a0-acdaff106893
* Split the tests in smaller files
  Added taskthread test to test task-thread relationship
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1803 ce417995-dfc9-0310-95a0-acdaff106893
* Periodic Tasks : if the Thread stops, stop all tasks of this thread also.
  Had to add start/stop methods to TaskTimerInterface to start/stop all tasks.
  SimulationThread does not stop its tasks to allow inspection ('freeze').
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1802 ce417995-dfc9-0310-95a0-acdaff106893
* Rename start to startup and cleanup to shutdown
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1801 ce417995-dfc9-0310-95a0-acdaff106893
* Fix LOCK_PREFIX
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1800 ce417995-dfc9-0310-95a0-acdaff106893
* In case binding fails, close socket.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1799 ce417995-dfc9-0310-95a0-acdaff106893
* The fix that fixes your code after you removed your
  debugging statements, together with a rt_sem_signal :-((
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1798 ce417995-dfc9-0310-95a0-acdaff106893
* typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1797 ce417995-dfc9-0310-95a0-acdaff106893
* FIX: check_region is deprecated because is prone to race conditions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1796 ce417995-dfc9-0310-95a0-acdaff106893
* Argument and format specifier mismatch
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1795 ce417995-dfc9-0310-95a0-acdaff106893
* Updated to C99
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1794 ce417995-dfc9-0310-95a0-acdaff106893
* FIXES :
  * memleak in gnulinux semaphores
  * thread not responding to semaphore under LXRT
  * added 'volatile' to inter-thread flags.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1793 ce417995-dfc9-0310-95a0-acdaff106893
* Added jr3test kernel module to Linux 2.6 buildsystem
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1790 ce417995-dfc9-0310-95a0-acdaff106893
* Ported to Linux 2.6 buildsystem
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1789 ce417995-dfc9-0310-95a0-acdaff106893
* Ported to Linux 2.6 buildsystem
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1788 ce417995-dfc9-0310-95a0-acdaff106893
* Ported to Linux 2.6 buildsystem
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1787 ce417995-dfc9-0310-95a0-acdaff106893
* Ported to Linux 2.6 buildsystem
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1786 ce417995-dfc9-0310-95a0-acdaff106893
* Ported to Linux 2.6
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1785 ce417995-dfc9-0310-95a0-acdaff106893
* Ported to Linux 2.6
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1784 ce417995-dfc9-0310-95a0-acdaff106893
* Ported to Linux 2.6
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1783 ce417995-dfc9-0310-95a0-acdaff106893
* delete encoderInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1781 ce417995-dfc9-0310-95a0-acdaff106893
* * Improved command acceptance semantics :
  In no case a command is executed if the task's
  processor is not running or not accepting.
  (methods can be called).
  * This also frees the TaskContext using a mutex,
  solving the 200+ mutexes created.
  * Fixed memleak in CommandDispatch
  * Fixed memleak in testcases
  * Added .cdl dependency of Processor on TaskContext
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1779 ce417995-dfc9-0310-95a0-acdaff106893
* Added the latest releases
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1778 ce417995-dfc9-0310-95a0-acdaff106893
* Slightly improved thread init failure detection.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1777 ce417995-dfc9-0310-95a0-acdaff106893
* Fix unchecked addTimer. Task shows critical error if
  task can not be scheduled in given thread.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1776 ce417995-dfc9-0310-95a0-acdaff106893
* remove comedi version 1, and make version 2 default
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1774 ce417995-dfc9-0310-95a0-acdaff106893
* change package system:
  - comedilib is only needed for gnulinux
  - comedi is only needed for lxrt
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1773 ce417995-dfc9-0310-95a0-acdaff106893
* Test updates :
  * add property test
  * fix tasks test (release thread)
  * misc parser test changes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1768 ce417995-dfc9-0310-95a0-acdaff106893
* Added some recent changes / caveats
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1767 ce417995-dfc9-0310-95a0-acdaff106893
* Property review to allow storing const T& values, which results
  in a correct const ref returned when get() is called.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1766 ce417995-dfc9-0310-95a0-acdaff106893
* small code&doc califications
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1765 ce417995-dfc9-0310-95a0-acdaff106893
* fix : #ifdefs for geometry package
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1764 ce417995-dfc9-0310-95a0-acdaff106893
* make apci compile with 2.6 kernels
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1763 ce417995-dfc9-0310-95a0-acdaff106893
* Added parser to controlservices
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1762 ce417995-dfc9-0310-95a0-acdaff106893
* Removed deprecated ReportHandler
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1761 ce417995-dfc9-0310-95a0-acdaff106893
* OS LXRT/GNU : call finalize if exception caught in thread loop.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1758 ce417995-dfc9-0310-95a0-acdaff106893
* fix bug: replace "expect_close" by "')'"
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1757 ce417995-dfc9-0310-95a0-acdaff106893
* CoreLib tasks :
  removed unneeded mutex, give thread name to PriorityThread.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1756 ce417995-dfc9-0310-95a0-acdaff106893
* PeriodicThread reliability improvements for LXRT and GNU/Linux.
  * set try/catch block around thread loop
  * LXRT:correct setscheduler implementation
  * LXRT:correct semaphore two-stage configuration, usage and init failure detections
  * LXRT:fixed reconfiguration bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1755 ce417995-dfc9-0310-95a0-acdaff106893
* Improved packages build targets. dist_packages builds the dist_packages
  template, all_packages the current template and control_services the
  minimal machine control template (without controlkernel, geometry etc)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1754 ce417995-dfc9-0310-95a0-acdaff106893
* add constructor for array (allocates memory at runtime for now)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1747 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed several syntax errors in ComediSubDeviceDIn.hpp
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1744 ce417995-dfc9-0310-95a0-acdaff106893
* use std::vector<double>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1733 ce417995-dfc9-0310-95a0-acdaff106893
* add 'array' to parser, represented by std:vector<double>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1729 ce417995-dfc9-0310-95a0-acdaff106893
* use std:vector
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1728 ce417995-dfc9-0310-95a0-acdaff106893
* remove _ugly\_ cerr's
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1726 ce417995-dfc9-0310-95a0-acdaff106893
* extend index checker to allow use of std::vector<>, by adding argument.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1725 ce417995-dfc9-0310-95a0-acdaff106893
* remove template parameter for index checking function
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1724 ce417995-dfc9-0310-95a0-acdaff106893
* configuration : Improved Execution dependencies and detected boost parser
  db depends on configure in makefile
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1723 ce417995-dfc9-0310-95a0-acdaff106893
* Review of OS manual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1722 ce417995-dfc9-0310-95a0-acdaff106893
* improved parse error messages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1721 ce417995-dfc9-0310-95a0-acdaff106893
* improved parse error messages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1720 ce417995-dfc9-0310-95a0-acdaff106893
* * changes typo fix
  * added architecture/processor selection to OS
  * build-depend on linux kernel module interface for
  canpie and apci kernel modules.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1719 ce417995-dfc9-0310-95a0-acdaff106893
* - uncomment moveto cause scripting has no vector<double>
  - add dirty cerr for debugging
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1712 ce417995-dfc9-0310-95a0-acdaff106893
* Program stepping semantics changed :
  * processor executes as much as possible of a program/function until a condition returns false
  * do nothing using a ConditionOnce
  * methods are always synchronous executed.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1710 ce417995-dfc9-0310-95a0-acdaff106893
* Added GPL Licenses
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1705 ce417995-dfc9-0310-95a0-acdaff106893
* Added LGPL Licenses
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1704 ce417995-dfc9-0310-95a0-acdaff106893
* rename data object interfaces, to avoid problems with reporter
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1699 ce417995-dfc9-0310-95a0-acdaff106893
* automated script to update headers with license info
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1698 ce417995-dfc9-0310-95a0-acdaff106893
* Re-enable isEnabled command for AxisSensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1697 ce417995-dfc9-0310-95a0-acdaff106893
* added controlservices make target
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1695 ce417995-dfc9-0310-95a0-acdaff106893
* ugly cerr for debugging
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1694 ce417995-dfc9-0310-95a0-acdaff106893
* Templates update, extended controlservices template
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1693 ce417995-dfc9-0310-95a0-acdaff106893
* tweaking of doxygen generation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1692 ce417995-dfc9-0310-95a0-acdaff106893
* added #ifdef to conditional compile geometry related code
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1691 ce417995-dfc9-0310-95a0-acdaff106893
* add offset instead of set offset
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1679 ce417995-dfc9-0310-95a0-acdaff106893
* of course we want Axis to inherit from AxisInterface ;-)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1678 ce417995-dfc9-0310-95a0-acdaff106893
* - Use new AxisInterface
  - Merge implementation of Axis and HardwareAxis
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1676 ce417995-dfc9-0310-95a0-acdaff106893
* add function for changing offset
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1675 ce417995-dfc9-0310-95a0-acdaff106893
* new AxisInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1674 ce417995-dfc9-0310-95a0-acdaff106893
* Use new AxisInterface.
  Warning: Parts that include 'homeswitch' and 'isEnabled' are commented out!!!!!!!!!!
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1673 ce417995-dfc9-0310-95a0-acdaff106893
* use new AxisInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1672 ce417995-dfc9-0310-95a0-acdaff106893
* add commands and methods
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1671 ce417995-dfc9-0310-95a0-acdaff106893
* Added simple DataObjectLockFree test
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1670 ce417995-dfc9-0310-95a0-acdaff106893
* * Added volatile qualifiers to pointers in buffers
  * Fixed race condition in DataObjectLockFree
  * uniform (and correct) usage of MAX_THREADS
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1669 ce417995-dfc9-0310-95a0-acdaff106893
* Further typo-fixing of BufferLockFree templates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1661 ce417995-dfc9-0310-95a0-acdaff106893
* Fix external template syntax error (gcc-3.4)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1660 ce417995-dfc9-0310-95a0-acdaff106893
* fix run() implementation typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1659 ce417995-dfc9-0310-95a0-acdaff106893
* more changes updated
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1658 ce417995-dfc9-0310-95a0-acdaff106893
* updated tests to new API
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1657 ce417995-dfc9-0310-95a0-acdaff106893
* Better make check-headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1656 ce417995-dfc9-0310-95a0-acdaff106893
* Increased version number to 0.20.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1655 ce417995-dfc9-0310-95a0-acdaff106893
* The Big Rename :
  * HeartBeatGenerator->TimeService
  * ticksGet/Set -> set/GetTicks & seconds
  * periodGet/Set -> get/setPeriod
  * taskAdd/Remove -> add/removeTask
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1654 ce417995-dfc9-0310-95a0-acdaff106893
* remove printf from Peter
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1653 ce417995-dfc9-0310-95a0-acdaff106893
* fix wrong urls
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1652 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed outdated header
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1651 ce417995-dfc9-0310-95a0-acdaff106893
* Section reordering and TimeService introduction
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1650 ce417995-dfc9-0310-95a0-acdaff106893
* Removed not-used files in OS
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1649 ce417995-dfc9-0310-95a0-acdaff106893
* fix wrong links in xml doc
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1648 ce417995-dfc9-0310-95a0-acdaff106893
* * Added local file parsing to Parser class
  * fixed wrong link in xml docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1647 ce417995-dfc9-0310-95a0-acdaff106893
* Reworked the generation of the Orocos Manual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1646 ce417995-dfc9-0310-95a0-acdaff106893
* removed duplicate file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1645 ce417995-dfc9-0310-95a0-acdaff106893
* include iostream
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1644 ce417995-dfc9-0310-95a0-acdaff106893
* include iostream
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1643 ce417995-dfc9-0310-95a0-acdaff106893
* fix wrong include
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1640 ce417995-dfc9-0310-95a0-acdaff106893
* Fix ';' typos
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1638 ce417995-dfc9-0310-95a0-acdaff106893
* Added more userfriendly usage docs for hardware components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1637 ce417995-dfc9-0310-95a0-acdaff106893
* Improved PeriodicThread step() calling for LXRT&GNU/Linux
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1636 ce417995-dfc9-0310-95a0-acdaff106893
* Added tests for
  * tasktimer and sim/prio task types
  * timing
  Improved other tests to be configuration independent.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1635 ce417995-dfc9-0310-95a0-acdaff106893
* Updated difference between select and start/stop
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1634 ce417995-dfc9-0310-95a0-acdaff106893
* completion funtion is const
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1633 ce417995-dfc9-0310-95a0-acdaff106893
* Renamed TaskTimer files to TaskTimerSequence
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1631 ce417995-dfc9-0310-95a0-acdaff106893
* added compiler-specific comment
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1630 ce417995-dfc9-0310-95a0-acdaff106893
* FIX wrong synchronisation in PeriodicThread
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1629 ce417995-dfc9-0310-95a0-acdaff106893
* add methods and commands to get force sensor data
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1628 ce417995-dfc9-0310-95a0-acdaff106893
* add operator [] for Wrench and Twist
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1627 ce417995-dfc9-0310-95a0-acdaff106893
* - extend parser with Wrench and Twist
  - operators between Frame Wrench Twist and Vector
  - index operators for Wrench Twist and Vector
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1625 ce417995-dfc9-0310-95a0-acdaff106893
* tasks : Refactoring of the periodic task infrastructure
  * The default timer is TaskTimerOneShot which does step()
  all tasks in one tick().
  * The old TaskTimer is renamed to TaskTimerSequencer
  * Start/stop of tasks is now hard-realtime safe.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1624 ce417995-dfc9-0310-95a0-acdaff106893
* Added Seconds_to_nsecs and nsecs_toSeconds function
  for consistent conversion in all of orocos.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1623 ce417995-dfc9-0310-95a0-acdaff106893
* Added proper synchronsation for thread start/stop
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1622 ce417995-dfc9-0310-95a0-acdaff106893
* Experimenting with website stylesheets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1621 ce417995-dfc9-0310-95a0-acdaff106893
* Fix warning about signedness.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1620 ce417995-dfc9-0310-95a0-acdaff106893
* Added "&" marshalling.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1619 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed marshalling of "<" and ">" to CPF files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1618 ce417995-dfc9-0310-95a0-acdaff106893
* DOC Added chunking support and makefile.am improvements
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1611 ce417995-dfc9-0310-95a0-acdaff106893
* IMP look for alternative RTAI Task Names if desired
  is taken.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1607 ce417995-dfc9-0310-95a0-acdaff106893
* FIX missing inline for ticks2timespec
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1606 ce417995-dfc9-0310-95a0-acdaff106893
* svn mv BufferedControlKernel.hpp LockFreeControlKernel.hpp
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1605 ce417995-dfc9-0310-95a0-acdaff106893
* FIX Use the DataObjectInterface from CoreLib and move
  docu to corelib manual. Rename BufferedControlKernel class
  to LockFreeControlKernel
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1604 ce417995-dfc9-0310-95a0-acdaff106893
* FIX Remove cout's so that they do not break HR in CartGenerator
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1603 ce417995-dfc9-0310-95a0-acdaff106893
* FIX adjust member to Event pointer type
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1602 ce417995-dfc9-0310-95a0-acdaff106893
* IMP Update Buffers and DataObjects section
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1601 ce417995-dfc9-0310-95a0-acdaff106893
* FIX update/cleanup buffers, fifo and DataObject implementations
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1600 ce417995-dfc9-0310-95a0-acdaff106893
* FIX remove deprecated file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1599 ce417995-dfc9-0310-95a0-acdaff106893
* FIX typo in example
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1598 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation updates for Orocos 0.20.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1597 ce417995-dfc9-0310-95a0-acdaff106893
* Update to doxygen 1.4
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1596 ce417995-dfc9-0310-95a0-acdaff106893
* Remove artifacts of over-eagerly vi user
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1594 ce417995-dfc9-0310-95a0-acdaff106893
* Buffers cleanup.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1582 ce417995-dfc9-0310-95a0-acdaff106893
* Added <struct> description
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1575 ce417995-dfc9-0310-95a0-acdaff106893
* unsigned int instead of int
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1574 ce417995-dfc9-0310-95a0-acdaff106893
* simplify transformation of center_of_gravity
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1573 ce417995-dfc9-0310-95a0-acdaff106893
* add commands and methods to forcesensor component
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1568 ce417995-dfc9-0310-95a0-acdaff106893
* make if-else move clear by adding {}
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1561 ce417995-dfc9-0310-95a0-acdaff106893
* add method to component
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1559 ce417995-dfc9-0310-95a0-acdaff106893
* fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1554 ce417995-dfc9-0310-95a0-acdaff106893
* add include of ParsedStateContext
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1553 ce417995-dfc9-0310-95a0-acdaff106893
* fix typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1551 ce417995-dfc9-0310-95a0-acdaff106893
* fix typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1550 ce417995-dfc9-0310-95a0-acdaff106893
* fixed typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1549 ce417995-dfc9-0310-95a0-acdaff106893
* rename RealTimeTask to PeriodicTask
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1548 ce417995-dfc9-0310-95a0-acdaff106893
* rename RealTimeTask to PeriodicTask
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1547 ce417995-dfc9-0310-95a0-acdaff106893
* Changed the Logger::flush() semantics ( does not write a new line,
  but does flush all previous lines). And removed the startlock, since
  quite useless.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1543 ce417995-dfc9-0310-95a0-acdaff106893
* add commmand factory
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1531 ce417995-dfc9-0310-95a0-acdaff106893
* rename data types
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1530 ce417995-dfc9-0310-95a0-acdaff106893
* typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1529 ce417995-dfc9-0310-95a0-acdaff106893
* rename classes to nAxesSensorForcesensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1526 ce417995-dfc9-0310-95a0-acdaff106893
* rename file...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1525 ce417995-dfc9-0310-95a0-acdaff106893
* add new sensor to read force sensor directly
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1524 ce417995-dfc9-0310-95a0-acdaff106893
* use offset if force sensor frame. This is the only frame in which the
  offset is constant.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1523 ce417995-dfc9-0310-95a0-acdaff106893
* Fix name resolution typo in RT_TASK init code
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1521 ce417995-dfc9-0310-95a0-acdaff106893
* CAN headerfile fixes and cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1520 ce417995-dfc9-0310-95a0-acdaff106893
* make check-headers target added
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1517 ce417995-dfc9-0310-95a0-acdaff106893
* Headerfile cleanup after make check-headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1516 ce417995-dfc9-0310-95a0-acdaff106893
* Headerfile cleanup after make check-headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1515 ce417995-dfc9-0310-95a0-acdaff106893
* Headerfile cleanup after make check-headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1514 ce417995-dfc9-0310-95a0-acdaff106893
* Headerfile cleanup after make check-headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1513 ce417995-dfc9-0310-95a0-acdaff106893
* Headerfile cleanup after make check-headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1512 ce417995-dfc9-0310-95a0-acdaff106893
* Headerfile cleanup after make check-headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1511 ce417995-dfc9-0310-95a0-acdaff106893
* Fix property compositions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1510 ce417995-dfc9-0310-95a0-acdaff106893
* use offset for force sensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1507 ce417995-dfc9-0310-95a0-acdaff106893
* Attempt to solve wrench/twist composition
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1506 ce417995-dfc9-0310-95a0-acdaff106893
* More singlethread fixes for OS_AGNOSTIC mode
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1504 ce417995-dfc9-0310-95a0-acdaff106893
* Substract offset from measured values
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1503 ce417995-dfc9-0310-95a0-acdaff106893
* renamed RT_TASK to RTOS_TASK
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1502 ce417995-dfc9-0310-95a0-acdaff106893
* Renamed DataObjectBuffered to DataObjectLockFree
  added Event ASYN Policy in docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1500 ce417995-dfc9-0310-95a0-acdaff106893
* changed to event*
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1498 ce417995-dfc9-0310-95a0-acdaff106893
* oeps..didn't compile yet
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1497 ce417995-dfc9-0310-95a0-acdaff106893
* uncomment copy of event reference
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1496 ce417995-dfc9-0310-95a0-acdaff106893
* Added Overrun policy to asynchronous event handlers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1495 ce417995-dfc9-0310-95a0-acdaff106893
* Add GPL license to testcases
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1494 ce417995-dfc9-0310-95a0-acdaff106893
* more testing of bufferlockfree
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1493 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug when write returns false.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1492 ce417995-dfc9-0310-95a0-acdaff106893
* Division from DataObjectInterfaces.hpp to be used
  in corelib
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1490 ce417995-dfc9-0310-95a0-acdaff106893
* Minor typo fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1487 ce417995-dfc9-0310-95a0-acdaff106893
* Suggestions from Herman wrt Priority Inversion
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1486 ce417995-dfc9-0310-95a0-acdaff106893
* Added Orocos FAQ
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1485 ce417995-dfc9-0310-95a0-acdaff106893
* return false when trying to adding new setpoint fails
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1482 ce417995-dfc9-0310-95a0-acdaff106893
* check sensor at construction time
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1481 ce417995-dfc9-0310-95a0-acdaff106893
* start task at construction
  log messages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1479 ce417995-dfc9-0310-95a0-acdaff106893
* Added LGPL copyright for EB.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1475 ce417995-dfc9-0310-95a0-acdaff106893
* use string instead of unsigned int
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1473 ce417995-dfc9-0310-95a0-acdaff106893
* Added missing license info
  Use Logger in CANPieController.cxx
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1472 ce417995-dfc9-0310-95a0-acdaff106893
* Oop, fix typo in PeriodicThread and add
  duplicate rtai name detection to SingleThread
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1471 ce417995-dfc9-0310-95a0-acdaff106893
* Added missing license info and
  Logger to SingleThread
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1470 ce417995-dfc9-0310-95a0-acdaff106893
* Add missing license info
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1469 ce417995-dfc9-0310-95a0-acdaff106893
* Add missing license info
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1468 ce417995-dfc9-0310-95a0-acdaff106893
* Added Logger to SingleThread
  Added missing licenses
  Do not go out for lunch if task name already exists.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1467 ce417995-dfc9-0310-95a0-acdaff106893
* Added a lock-free implementation of a FIFO buffer
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1466 ce417995-dfc9-0310-95a0-acdaff106893
* Added cdl option to disable logging at compile time
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1465 ce417995-dfc9-0310-95a0-acdaff106893
* Added docs for Priority Inversions and Buffers
  vs DataObjects
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1464 ce417995-dfc9-0310-95a0-acdaff106893
* Added some extra Logger::Debug info
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1463 ce417995-dfc9-0310-95a0-acdaff106893
* initialize data types at component loaded
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1461 ce417995-dfc9-0310-95a0-acdaff106893
* use reference to event
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1455 ce417995-dfc9-0310-95a0-acdaff106893
* add implementation of sensor interface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1451 ce417995-dfc9-0310-95a0-acdaff106893
* Added reporting Debug message
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1449 ce417995-dfc9-0310-95a0-acdaff106893
* Allow disabling of Logger by setting
  ORO_LOGLEVEL=-1
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1448 ce417995-dfc9-0310-95a0-acdaff106893
* Added copyright notices to Johan's files.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1447 ce417995-dfc9-0310-95a0-acdaff106893
* Moved wrenchsensor from orocos-trunk to hardware-hotspots in
  orocos-applications
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1446 ce417995-dfc9-0310-95a0-acdaff106893
* Do not start Logger if OROBLD_DISABLE_LOGGING is
  defined
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1441 ce417995-dfc9-0310-95a0-acdaff106893
* Reverted wrongfully changed copyright
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1429 ce417995-dfc9-0310-95a0-acdaff106893
* Update copyright notices to credit correct author
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1428 ce417995-dfc9-0310-95a0-acdaff106893
* Updated accidental copyright notice change in LRL derived code
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1427 ce417995-dfc9-0310-95a0-acdaff106893
* doc xml fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1422 ce417995-dfc9-0310-95a0-acdaff106893
* Pre-release doc updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1419 ce417995-dfc9-0310-95a0-acdaff106893
* *Added Saving of Component Property files
  *Far much better CPF file handling
  *Improved logging for gnulinux target
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1417 ce417995-dfc9-0310-95a0-acdaff106893
* constructor without events
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1416 ce417995-dfc9-0310-95a0-acdaff106893
* const argument for copy constructor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1415 ce417995-dfc9-0310-95a0-acdaff106893
* Make it compile nicely.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1414 ce417995-dfc9-0310-95a0-acdaff106893
* Added highload and maximumload events.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1413 ce417995-dfc9-0310-95a0-acdaff106893
* Added JR3WrenchSensor class.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1412 ce417995-dfc9-0310-95a0-acdaff106893
* Logger starting/stopping is much improved
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1410 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed LXRT+Logger problem (NameServer caused it
  ) Better startup code for Logger. Added more Debug msgs around startup code.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1409 ce417995-dfc9-0310-95a0-acdaff106893
* Fix another wrong log message
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1408 ce417995-dfc9-0310-95a0-acdaff106893
* Do not log before thread is inited.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1407 ce417995-dfc9-0310-95a0-acdaff106893
* OS build fixes on RedHat 8
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1406 ce417995-dfc9-0310-95a0-acdaff106893
* CANPie/Open refactoring of header files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1405 ce417995-dfc9-0310-95a0-acdaff106893
* Initialized merge tracking via svnmerge with revisions 1-1403 from
  http://srv04/svn/orocos/orocos-branches/branch-0.18
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1404 ce417995-dfc9-0310-95a0-acdaff106893
* remove old svnmerge props
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1403 ce417995-dfc9-0310-95a0-acdaff106893
* Added missing revision from branch-0.18 to trunk
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1401 ce417995-dfc9-0310-95a0-acdaff106893
* Merged revisions 1393-1399 via svnmerge from
  http://srv04/svn/orocos/orocos-branches/branch-0.18
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1400 ce417995-dfc9-0310-95a0-acdaff106893
* doc updates and fixed erroneous apci compiler flag which
  assumed it was compiling for current kernel version
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1398 ce417995-dfc9-0310-95a0-acdaff106893
* add ";" to fix bug...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1396 ce417995-dfc9-0310-95a0-acdaff106893
* added component with cartesian force and mass compensation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1395 ce417995-dfc9-0310-95a0-acdaff106893
* svn merge -r1375:1390 ../orocos-branches/branch-0.18/
  Manual synchronisation merge, since 'svnmerge' can
  only track changes after 'init'
  * Doc updates
  * Logger framework
  * TableHeader crashfix
  * Release notes for 0.18.2
  * Processor boost::function alloc fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1394 ce417995-dfc9-0310-95a0-acdaff106893
* Initialized merge tracking via svnmerge with revisions 1-1392 from
  http://srv04/svn/orocos/orocos-branches/branch-0.18
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1393 ce417995-dfc9-0310-95a0-acdaff106893
* merge from orocos-branch/branch-0.18 : -r1357:1374
  * LGPL licenses
  * cleanup() fixes in Program and state parsers
  * Doc and Doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1375 ce417995-dfc9-0310-95a0-acdaff106893
* OS_AGNOSTIC buildfix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1373 ce417995-dfc9-0310-95a0-acdaff106893
* OS_AGNOSTIC build fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1370 ce417995-dfc9-0310-95a0-acdaff106893
* Build fix for acpi in agnostic mode
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1369 ce417995-dfc9-0310-95a0-acdaff106893
* Update LXRT device drivers with INTERNAL flag
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1362 ce417995-dfc9-0310-95a0-acdaff106893
* Bugfix : selected wrong method overload for copy()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1351 ce417995-dfc9-0310-95a0-acdaff106893
* autoconf updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1348 ce417995-dfc9-0310-95a0-acdaff106893
* Merge from branch-0.18 -r 1342:1345
  * More property operations
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1346 ce417995-dfc9-0310-95a0-acdaff106893
* Merge from branch-0.18 : -r1324:1342
  * make install / uninstall
  * doc updates
  * OS_AGNOSTIC option
  * build system updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1344 ce417995-dfc9-0310-95a0-acdaff106893
* removed FrameDifference. Replaced by Diff
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1343 ce417995-dfc9-0310-95a0-acdaff106893
* Fame!
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1337 ce417995-dfc9-0310-95a0-acdaff106893
* Ported to RTnet 0.8.x
  WARNING: Not tested yet (hardware unavailable)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1336 ce417995-dfc9-0310-95a0-acdaff106893
* break -> brake
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1327 ce417995-dfc9-0310-95a0-acdaff106893
* Added Profiling tests (disabled by default)
  updated release notes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1322 ce417995-dfc9-0310-95a0-acdaff106893
* minor include update+clone fix in ConditionExpire
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1321 ce417995-dfc9-0310-95a0-acdaff106893
* Review of OS code :
  * Doc updates, removed kernel references in tekst
  * return -1 upon exception in main()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1320 ce417995-dfc9-0310-95a0-acdaff106893
* Review of CoreLib code :
  * asynchronous event completion does no longer allocate memory
  upon fire( args )
  * PropertyBase::update/copy do no longer dynamic_cast
  on primitive types and are fully thread-safe.
  * TaskEventDriven is now step()ed in asynchronous part
  * HeartBeatGenerator + SimulationThread keeps time
  progress monotonic
  * CoreLib manual thoroughly reviewed
  * Internal interface changes for Tasks (adding const)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1319 ce417995-dfc9-0310-95a0-acdaff106893
* Try to fix missing __u64 type
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1318 ce417995-dfc9-0310-95a0-acdaff106893
* rtnet driver
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1314 ce417995-dfc9-0310-95a0-acdaff106893
* Corrected language typos
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1310 ce417995-dfc9-0310-95a0-acdaff106893
* Last minute changes :
  * install doc updates
  * changed default periodicities of Orocos threads
  * changed PriorityThread Instance() to allow an optional
  periodicity parameter
  * did rt_preemptalways() in MainThread.cxx
  * removed warnings resulting from changes in SensorInterface<>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1309 ce417995-dfc9-0310-95a0-acdaff106893
* Last minute changes for RedHat 8.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1308 ce417995-dfc9-0310-95a0-acdaff106893
* A SensorInterface now inherits from CalibrationInterface
  CalibrationInterface's methods have a default implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1307 ce417995-dfc9-0310-95a0-acdaff106893
* Changes done on lvdpc104
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1306 ce417995-dfc9-0310-95a0-acdaff106893
* Minimalistic configure script tweaking
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1305 ce417995-dfc9-0310-95a0-acdaff106893
* --with-lxrt update in installation manual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1296 ce417995-dfc9-0310-95a0-acdaff106893
* last-minute updates of browser and docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1292 ce417995-dfc9-0310-95a0-acdaff106893
* Overall CANOpen over Beckhoff improvements :
  * no hard coded terminals.
  * better configuration/startup management.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1288 ce417995-dfc9-0310-95a0-acdaff106893
* Tree-wide upgrade of the orocos.xsl files to have nicer pdfs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1285 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation improvements :
  * Tried to do a better job for the Program Processor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1284 ce417995-dfc9-0310-95a0-acdaff106893
* ControlKernel : Added doc about exportProperties
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1283 ce417995-dfc9-0310-95a0-acdaff106893
* * Updated release notes
  * Fixed 3 build errors which slipped through my compiler
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1282 ce417995-dfc9-0310-95a0-acdaff106893
* Reordered sections, hopefully it is more helpfull now
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1281 ce417995-dfc9-0310-95a0-acdaff106893
* Pre-Release testing of Orocos 0.18.0
  - Version number bump
  - Fixed last parser bugs
  - Docbook file syntax fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1280 ce417995-dfc9-0310-95a0-acdaff106893
* Moved the TemplateFactory* files to task_context, as they are very
  usefull for any system, even without parser.
  Updated all the execution docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1279 ce417995-dfc9-0310-95a0-acdaff106893
* Finished the TaskBrowser. Happy with it.
  Parser Exceptions had to be adapted here and there to get the
  semantics right.
  Added TaskBrowser example to taskman.
  Added getState() method for in script states
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1277 ce417995-dfc9-0310-95a0-acdaff106893
* Added default program start()/stop() script commands, managed by the
  program's own TaskContext, such that task.programs.foo.start() is
  now legal.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1276 ce417995-dfc9-0310-95a0-acdaff106893
* Initialise kernel name before initialising extensions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1275 ce417995-dfc9-0310-95a0-acdaff106893
* * Script Programs now also allocate vars on stack
  * Better State Context cleanup in sgparser
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1274 ce417995-dfc9-0310-95a0-acdaff106893
* Cosmetic updates to docs, scripts and TaskBrowser
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1273 ce417995-dfc9-0310-95a0-acdaff106893
* * Added template Datasource factories for the inState command.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1272 ce417995-dfc9-0310-95a0-acdaff106893
* Added two tests for StateContext parsers.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1268 ce417995-dfc9-0310-95a0-acdaff106893
* set package deps right
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1267 ce417995-dfc9-0310-95a0-acdaff106893
* In ExecutionExtension : provide filename, and optionally the
  file text itself when loading progs/states.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1266 ce417995-dfc9-0310-95a0-acdaff106893
* StateContext parser :
  * adapted to new TaskContext semantics
  * possible to send commands from parrent to child SC.
  * Various pretty old bugs were fixed.
  * Added TaskBrowser to browse TaskContexts
  * Added new kind of TemplateCommandFactory for
  storing the 'component' pointer in a datasource.
  * PeerParser : hopefully a more meaningfull implementation,
  but the responsibilities of this parser remain uncertain.
  * TODO : refactor the StateGraphParser and ParsedStateContext.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1265 ce417995-dfc9-0310-95a0-acdaff106893
* Processor :
  * _stops\_ all programs and states when stopped.
  * moved states initcommand to StateContext
  * bugfixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1264 ce417995-dfc9-0310-95a0-acdaff106893
* TaskContext :
  * Added aliasing support
  * AttrRep does not clear repos on destruction, use clear()
  * doc&debug updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1263 ce417995-dfc9-0310-95a0-acdaff106893
* Various fixes when testing the Processor and StateContexts.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1262 ce417995-dfc9-0310-95a0-acdaff106893
* For some reason, on some systems operator-(iter_t, iter_t) does
  not cast "1" to iter_t...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1259 ce417995-dfc9-0310-95a0-acdaff106893
* Merge from orocos-taskcontext -r1256:1257 with trunk :
  * Fix too much reports
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1258 ce417995-dfc9-0310-95a0-acdaff106893
* pure virtual functions for properties, update and export, have to be
  implemented if property extension is used.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1256 ce417995-dfc9-0310-95a0-acdaff106893
* remove old include
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1255 ce417995-dfc9-0310-95a0-acdaff106893
* Remove non existing file includes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1254 ce417995-dfc9-0310-95a0-acdaff106893
* Merge of revisions -r1162:1252 from orocos-branches/orocos-taskcontext
  branch.
  * TaskContext Implementation
  * Doc enhancements
  * Test enhancements
  * DataObjectReporting fixed
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1253 ce417995-dfc9-0310-95a0-acdaff106893
* remove using namespace
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1216 ce417995-dfc9-0310-95a0-acdaff106893
* replace "*0" with "SetToZero"
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1215 ce417995-dfc9-0310-95a0-acdaff106893
* Return correct values at begin and end of profile
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1213 ce417995-dfc9-0310-95a0-acdaff106893
* remove frames_io includes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1212 ce417995-dfc9-0310-95a0-acdaff106893
* fix initialize max_drive_value
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1209 ce417995-dfc9-0310-95a0-acdaff106893
* fix initial position
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1208 ce417995-dfc9-0310-95a0-acdaff106893
* Don't assert when properties have not been read.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1207 ce417995-dfc9-0310-95a0-acdaff106893
* fix initial value
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1206 ce417995-dfc9-0310-95a0-acdaff106893
* Implemented (empty) destructor.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1203 ce417995-dfc9-0310-95a0-acdaff106893
* add offset from mouting plate to end effector
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1201 ce417995-dfc9-0310-95a0-acdaff106893
* refpoint change
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1200 ce417995-dfc9-0310-95a0-acdaff106893
* reference point of twists is world, not EE
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1199 ce417995-dfc9-0310-95a0-acdaff106893
* fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1194 ce417995-dfc9-0310-95a0-acdaff106893
* add gpl header
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1175 ce417995-dfc9-0310-95a0-acdaff106893
* Undo wrong commit
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1161 ce417995-dfc9-0310-95a0-acdaff106893
* switch from trunk to command-method
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1160 ce417995-dfc9-0310-95a0-acdaff106893
* Possible fix for not decomposing the Twist class in
  ControlKernel DataObject Reporting.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1159 ce417995-dfc9-0310-95a0-acdaff106893
* configuration for cartesian components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1158 ce417995-dfc9-0310-95a0-acdaff106893
* new cartesian components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1155 ce417995-dfc9-0310-95a0-acdaff106893
* initialize all vectors, to avoid realtime resize
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1151 ce417995-dfc9-0310-95a0-acdaff106893
* use maximum speed/acceleration if no time is specified
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1145 ce417995-dfc9-0310-95a0-acdaff106893
* sinus generator
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1144 ce417995-dfc9-0310-95a0-acdaff106893
* sinus generator
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1143 ce417995-dfc9-0310-95a0-acdaff106893
* don't try to  compile cartesian yet..
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1142 ce417995-dfc9-0310-95a0-acdaff106893
* rename classes, to match filename
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1140 ce417995-dfc9-0310-95a0-acdaff106893
* fix in datatype
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1138 ce417995-dfc9-0310-95a0-acdaff106893
* fix initialisation of integrator
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1137 ce417995-dfc9-0310-95a0-acdaff106893
* add diff and addDelta functions, implemented by Erwin Aertbelien
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1136 ce417995-dfc9-0310-95a0-acdaff106893
* remove buggy function
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1135 ce417995-dfc9-0310-95a0-acdaff106893
* replace 10E-17 with epsilon (=0.000001, defined in utility.cxx)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1134 ce417995-dfc9-0310-95a0-acdaff106893
* The norm of GetRot() is now angle, and not sin(angle)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1133 ce417995-dfc9-0310-95a0-acdaff106893
* property files of components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1132 ce417995-dfc9-0310-95a0-acdaff106893
* components for n-axis, based on code of Klaas Gadeyne
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1131 ce417995-dfc9-0310-95a0-acdaff106893
* Added HomingInterface, AxisInterface and implementations.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1130 ce417995-dfc9-0310-95a0-acdaff106893
* Removed deprecated interface that wasn't used.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1125 ce417995-dfc9-0310-95a0-acdaff106893
* Removed #include <rtai/config.h>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1124 ce417995-dfc9-0310-95a0-acdaff106893
* Deleted the calibration methods, they are now in CalibrationInterface.hpp
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1093 ce417995-dfc9-0310-95a0-acdaff106893
* fix destructor bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1052 ce417995-dfc9-0310-95a0-acdaff106893
* do not put this stuff in root include dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1051 ce417995-dfc9-0310-95a0-acdaff106893
* forgot task->
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1017 ce417995-dfc9-0310-95a0-acdaff106893
* para too much
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1016 ce417995-dfc9-0310-95a0-acdaff106893
* fix unclear stuff and typos
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1015 ce417995-dfc9-0310-95a0-acdaff106893
* symbol already defined, comedi should be comedilib here
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1014 ce417995-dfc9-0310-95a0-acdaff106893
* added exportProperties implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1008 ce417995-dfc9-0310-95a0-acdaff106893
* Use ecosconfig instead of configtool
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1007 ce417995-dfc9-0310-95a0-acdaff106893
* Merge from orocos-branches/orocos-command-method -r1002:1003 merge
  * Forgotten files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1004 ce417995-dfc9-0310-95a0-acdaff106893
* Merge from orocos-branches/orocos-command-method -r982:997 merge
  Main Changes :
  * Commands return bool to indicate accept/reject
  * Methods are introduced which behave like instant commands
  * Some cdl files have better dependencies
  * Some components have replaced their commands with methods,
  this is however transparant to the user.
  * Programs and Statecontexts can enter the 'error' state
  when a command returns false.
  * A try/catch block was implemented
  * The make distcheck target has been improved
  * An orocos-changes file has been added to provide
  more verbose upgrade info for users.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1002 ce417995-dfc9-0310-95a0-acdaff106893
* Made exportReports a pure virtual in ReportingComponent
  Made DefaultComponents without extensions
  Fixed unknown motion types in reporting
  Made datasources non const again to allow 1to1 mapping
  with methods
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@981 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed two segfaults :
  * Reference counting messup in ConditionParser
  * missplaced braces in ProgramGraphParser do/try statements
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@980 ce417995-dfc9-0310-95a0-acdaff106893
* Obligatory missing file in last commit
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@979 ce417995-dfc9-0310-95a0-acdaff106893
* Further member/method refactoring :
  Added methodfactory in globalfactory
  Adapted files to renamed methods.
  This patch stabilises the refactoring, next phase
  is adding the functionality in the parsers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@978 ce417995-dfc9-0310-95a0-acdaff106893
* GlobalDataSourceFactory refactored in GlobalMemberFactory
  Added future try command
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@977 ce417995-dfc9-0310-95a0-acdaff106893
* Further refactoring of DataSource and Method into Member factories
  hasName --> hasMember
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@976 ce417995-dfc9-0310-95a0-acdaff106893
* Introduced the MethodFactoryInterface
  modified DataSourceFactoryInterface :
  hasData -> hasName, dataNames -> getNames
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@975 ce417995-dfc9-0310-95a0-acdaff106893
* Missing files of previous commit
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@974 ce417995-dfc9-0310-95a0-acdaff106893
* Working towards a unified member factory for the program parser
  factory -> getObjectFactory
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@973 ce417995-dfc9-0310-95a0-acdaff106893
* Unstable commit : moved DataSource to Member
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@972 ce417995-dfc9-0310-95a0-acdaff106893
* Added 3 and 4 arguments to DataSources, in preparation
  of the function() object
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@971 ce417995-dfc9-0310-95a0-acdaff106893
* added doxy to StartStopManager
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@970 ce417995-dfc9-0310-95a0-acdaff106893
* Missing include reported by
  Vandenbroucke Sander <Sander.Vandenbroucke@vandewiele.com>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@966 ce417995-dfc9-0310-95a0-acdaff106893
* Geometry : Fixed shameful C++ syntax errors
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@957 ce417995-dfc9-0310-95a0-acdaff106893
* Geometry : fixed typo in default constructor macros
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@956 ce417995-dfc9-0310-95a0-acdaff106893
* Removed 'next' 'stop' 'end' from reserved words list
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@954 ce417995-dfc9-0310-95a0-acdaff106893
* PID : Added reset methods
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@953 ce417995-dfc9-0310-95a0-acdaff106893
* HMIReadline:
  Prettier help function and parse error carsh fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@952 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel :
  * added start/stop kernel task from within execution
  * stop all components when the kernel is stopped
  8 added executeCommand method to ExecExt
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@951 ce417995-dfc9-0310-95a0-acdaff106893
* Parser/Processor :
  * fixed program self-stop-start bug
  * gave state programs names
  * fixed 'do nothing' bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@950 ce417995-dfc9-0310-95a0-acdaff106893
* Removed outdated events.dia
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@948 ce417995-dfc9-0310-95a0-acdaff106893
* esthetic change for configtool
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@936 ce417995-dfc9-0310-95a0-acdaff106893
* Added missing motioncontrol cdl files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@935 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel : GCC 3.4 fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@934 ce417995-dfc9-0310-95a0-acdaff106893
* Processor :
  * small doc update (exceptions)
  * removed dynamic_cast<> from executeToStop in program
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@933 ce417995-dfc9-0310-95a0-acdaff106893
* Parser:
  * Added support for binary-argument datasources
  * Fixed the function parsing segfault
  * Fixed double6d six-ary constructor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@932 ce417995-dfc9-0310-95a0-acdaff106893
* Upgrade of RTAI/canpie device driver for sja1000.
  We use two kernel threads for sending/receiving
  can messages to avoid fifo overruns.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@929 ce417995-dfc9-0310-95a0-acdaff106893
* Added more DEBUG statements and checked for each kind
  of interrupt.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@928 ce417995-dfc9-0310-95a0-acdaff106893
* Improved program_text listing and linenumbering
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@926 ce417995-dfc9-0310-95a0-acdaff106893
* updated templates to reflect new motion_control
  directory structure
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@925 ce417995-dfc9-0310-95a0-acdaff106893
* Restructuring motion_control - PHASE 2
  * moved current to common/current
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@924 ce417995-dfc9-0310-95a0-acdaff106893
* Restructuring the motion_control directory :
  * Added axis and cartesian subpackages
  * PHASE 1 : move files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@923 ce417995-dfc9-0310-95a0-acdaff106893
* HMIConsoleOutput:
  Added setPrompt method
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@922 ce417995-dfc9-0310-95a0-acdaff106893
* LXRT:
  Typo fix in getuid() code
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@921 ce417995-dfc9-0310-95a0-acdaff106893
* * Public State and Program status through Processor enums.
  * getName on StateDescription
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@920 ce417995-dfc9-0310-95a0-acdaff106893
* Added getName to StateInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@919 ce417995-dfc9-0310-95a0-acdaff106893
* Check for root uid in startup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@918 ce417995-dfc9-0310-95a0-acdaff106893
* Adapted ExecutionExtension to improved program processor/
  parser
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@914 ce417995-dfc9-0310-95a0-acdaff106893
* Program Parser:
  * Allow multiple programs in one file
  * Save program source files
  * Fixed segfault with parallel commands
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@913 ce417995-dfc9-0310-95a0-acdaff106893
* Processor :
  * Better program script stepping and start-stop semantics
  * Fixed composite command reset() bug
  * Programs keep their source text (relative to their line numbers )
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@912 ce417995-dfc9-0310-95a0-acdaff106893
* HMIConsoleOutput : Added enable/disable color
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@911 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed bug in GetRPY().
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@909 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed wrong Aynchronous Stop implementation of
  PeriodicThread in LXRT
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@908 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed the recursive configure invocations, needs cleanup though
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@906 ce417995-dfc9-0310-95a0-acdaff106893
* packages configure : bugfix
  replace enableval with withval
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@905 ce417995-dfc9-0310-95a0-acdaff106893
* Cleanup of the StateContext Interface
  Introduced activate/deactivate
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@903 ce417995-dfc9-0310-95a0-acdaff106893
* *Added "FeedForward" to SetPoint DataObject of PID_Controller
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@902 ce417995-dfc9-0310-95a0-acdaff106893
* Console :
  * Added propper exception detection code
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@901 ce417995-dfc9-0310-95a0-acdaff106893
* Geometry :
  Set default constructors of vectors and rotations.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@900 ce417995-dfc9-0310-95a0-acdaff106893
* Processor :
  * Fixed faulty checkUnload implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@899 ce417995-dfc9-0310-95a0-acdaff106893
* State Context :
  * Propper parent/child implementation
  Commands :
  * better error message
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@898 ce417995-dfc9-0310-95a0-acdaff106893
* Execution Extension :
  * Moved statecontext_load_exception to Processor as program_load_exception
  * Adapted to new start/stop SC semantics
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@896 ce417995-dfc9-0310-95a0-acdaff106893
* Program Processor & Parser:
  * Rewrote the Processor State Context command processing
  * Syntax reporting in ProgramGraphParser through exceptions
  * Better CommandParser syntax errors
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@895 ce417995-dfc9-0310-95a0-acdaff106893
* make the exception system more specific, so that we can not only get a textual representation of the error, but can also find out in the calling code what the error was...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@891 ce417995-dfc9-0310-95a0-acdaff106893
* nullchecks: current can be 0 now...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@890 ce417995-dfc9-0310-95a0-acdaff106893
* parser doc error fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@888 ce417995-dfc9-0310-95a0-acdaff106893
* fix wrong commit
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@884 ce417995-dfc9-0310-95a0-acdaff106893
* fix the other iterator type as well
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@882 ce417995-dfc9-0310-95a0-acdaff106893
* CoreLib-doc changed preemptable to preemptible
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@880 ce417995-dfc9-0310-95a0-acdaff106893
* * Better configuration detection from main
  configure script.
  * Added a small device drivers section to
  installation manual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@879 ce417995-dfc9-0310-95a0-acdaff106893
* RTAI detection package
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@878 ce417995-dfc9-0310-95a0-acdaff106893
* Packages :
  * Better system detection using configure script
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@877 ce417995-dfc9-0310-95a0-acdaff106893
* LXRT :
  * PeriodicThread fixes
  * package uses configure script info
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@876 ce417995-dfc9-0310-95a0-acdaff106893
* Library Detection : Refactored detection mechanisms
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@875 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel :
  * getTask/setTask removal from extensions
  * Extension Interface cleanups
  * added getKernelName to KernelBaseFunction
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@874 ce417995-dfc9-0310-95a0-acdaff106893
* Removed old TestCase application from trunk
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@873 ce417995-dfc9-0310-95a0-acdaff106893
* make the name_iterator work properly ( std::string is not an iterator_category )
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@872 ce417995-dfc9-0310-95a0-acdaff106893
* RunnableInterface :
  * undo wrong fix on rev 870
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@871 ce417995-dfc9-0310-95a0-acdaff106893
* Removed old get/setTask() functions, implemented
  in RunnableInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@870 ce417995-dfc9-0310-95a0-acdaff106893
* improve the Parser::parseCommand interface for retrieving the error message, and for not needing to pass a writable string...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@869 ce417995-dfc9-0310-95a0-acdaff106893
* add the methods Processor::isCommandProcessed and Processor::abandonCommand
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@868 ce417995-dfc9-0310-95a0-acdaff106893
* Data Objects:
  * made data default constructed
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@867 ce417995-dfc9-0310-95a0-acdaff106893
* prevent quite some wrong errors about various keywords not being valid identifiers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@866 ce417995-dfc9-0310-95a0-acdaff106893
* prevent a wrong error about done not being a valid identifier
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@865 ce417995-dfc9-0310-95a0-acdaff106893
* Events  :
  * Made (A)synchronous event connect/disconnect thread-safe.
  * Self-disconnect is allowed using a recursive mutex
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@864 ce417995-dfc9-0310-95a0-acdaff106893
* Motion Control :
  * Fix rawValue command readout
  * Only write ChannelValues if user requested so
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@863 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel :
  * Added startup/shutdown Component semantics
  * Extended the Kernel commands
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@862 ce417995-dfc9-0310-95a0-acdaff106893
* ignore config.h.in
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@861 ce417995-dfc9-0310-95a0-acdaff106893
* prevent some crashes by doing copying and parser cleanup properly
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@860 ce417995-dfc9-0310-95a0-acdaff106893
* Improve some interfaces ( return error messages on parsing, allow
  for deleting state contexts, ... ) and fix some memory bugs in
  StateGraphParser...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@858 ce417995-dfc9-0310-95a0-acdaff106893
* document state preconditions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@857 ce417995-dfc9-0310-95a0-acdaff106893
* PID_Controller :
  Fix uninitialized control values
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@856 ce417995-dfc9-0310-95a0-acdaff106893
* * Installation Docs update + build system fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@855 ce417995-dfc9-0310-95a0-acdaff106893
* Updated manual with better ExecutionExtension drawing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@854 ce417995-dfc9-0310-95a0-acdaff106893
* typeof -> __typeof\_\_
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@853 ce417995-dfc9-0310-95a0-acdaff106893
* this file is generated by autoheader as part of the build process..
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@852 ce417995-dfc9-0310-95a0-acdaff106893
* svn:ignore += readline.cdl
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@851 ce417995-dfc9-0310-95a0-acdaff106893
* boost/signals.hpp -> boost/signal.hpp
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@850 ce417995-dfc9-0310-95a0-acdaff106893
* fixed slipped-in merge conflict in dist template
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@849 ce417995-dfc9-0310-95a0-acdaff106893
* ignore Makefile.in
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@848 ce417995-dfc9-0310-95a0-acdaff106893
* make it work: AC_CONFIG stuff must be before AM_INIT_AUTOMAKE
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@847 ce417995-dfc9-0310-95a0-acdaff106893
* Merged in changes from orocos-domi Branch :
  * Hierarchical State Machines
  * ProgramGraph refactored implementation
  * Overall Parser Improvements
  * StateContext Start/Stop semantics added
  * New Copy/Clone implementation of conditions/commands/data sources
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@846 ce417995-dfc9-0310-95a0-acdaff106893
* Orocos Build System :
  * Go fully automake-style with build/packages
  instead of build/packages-TARGET
  * Documentation update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@841 ce417995-dfc9-0310-95a0-acdaff106893
* Added a test for asyn events in task and
  completion processor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@840 ce417995-dfc9-0310-95a0-acdaff106893
* More meaningfull messages for configure script
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@839 ce417995-dfc9-0310-95a0-acdaff106893
* Removed can device driver from default setup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@838 ce417995-dfc9-0310-95a0-acdaff106893
* Execution :
  * Moved to new Event Implementation
  * Overall compilation fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@837 ce417995-dfc9-0310-95a0-acdaff106893
* Geometry :
  * removed duplicate files : rotation2, frames2 and vector2.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@836 ce417995-dfc9-0310-95a0-acdaff106893
* Kernel Components :
  * Moved over to new Event implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@835 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel :
  * Removed deprecated kernel implementations
  * Updated support component docs
  * Doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@834 ce417995-dfc9-0310-95a0-acdaff106893
* Device Drivers :
  * Cleanup of deprecated files
  * Compilation fixes for FakeEncoder, AnalogSensor,
  EndPositionDetector and EncoderPositionSensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@833 ce417995-dfc9-0310-95a0-acdaff106893
* Device Interface :
  * Removed deprecated, confusing files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@832 ce417995-dfc9-0310-95a0-acdaff106893
* Orocos OS :
  * Cleanup of deprecated files
  * PeriodicThread::start() checks return value of initialize
  * introduction of MutexRecursive
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@831 ce417995-dfc9-0310-95a0-acdaff106893
* Corelib :
  * New Event infrastructure based on boost::signal
  * CompletionProcessor and NonRealTimeThread are again decoupled
  * Any thread can do a completion of an event.
  * Overall compilation fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@830 ce417995-dfc9-0310-95a0-acdaff106893
* Added testsuite for corelib
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@809 ce417995-dfc9-0310-95a0-acdaff106893
* * defaulted apci/lxrt to RTAI 3.0
  * fixed jr3 wrong include
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@792 ce417995-dfc9-0310-95a0-acdaff106893
* * Even better boostrap.sh detection
  * appendix reordering in control-kernel docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@791 ce417995-dfc9-0310-95a0-acdaff106893
* Added more authors
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@783 ce417995-dfc9-0310-95a0-acdaff106893
* Added last minute changes from 0.16.0 branch
  revisions r777-r780
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@782 ce417995-dfc9-0310-95a0-acdaff106893
* * Changed the title of the manual to be more professional
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@776 ce417995-dfc9-0310-95a0-acdaff106893
* Prepare for release :
  * Release notes, authors, last-minute fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@774 ce417995-dfc9-0310-95a0-acdaff106893
* Base Docs : Fix wrong dependency in Makefile
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@772 ce417995-dfc9-0310-95a0-acdaff106893
* Program Parser :
  * Change 'kernel' to 'Kernel' and 'engine' to "Execution"
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@771 ce417995-dfc9-0310-95a0-acdaff106893
* ControlKernel : Adapt old-style kernel to new API
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@768 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel :
  Further refactoring to fix the extension configuration.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@767 ce417995-dfc9-0310-95a0-acdaff106893
* removed comedi support from dist, users must download
  package seperately
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@765 ce417995-dfc9-0310-95a0-acdaff106893
* All new .hpp .cxx :
  * Added LGPL Header
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@764 ce417995-dfc9-0310-95a0-acdaff106893
* Dist : switched to dist-packages template
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@763 ce417995-dfc9-0310-95a0-acdaff106893
* Configure : Added the readline detection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@762 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel :
  * Fixed Extension nameserver pollution
  * Removed select/deselect Support
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@761 ce417995-dfc9-0310-95a0-acdaff106893
* Installer : Improved configuration of packages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@760 ce417995-dfc9-0310-95a0-acdaff106893
* removed jr3 and apci from dist
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@758 ce417995-dfc9-0310-95a0-acdaff106893
* Copy of allpackages, but some removed for dist
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@757 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel :
  Support Components do not startup/restart/shutdown
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@752 ce417995-dfc9-0310-95a0-acdaff106893
* fix mem leak
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@750 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel: small spelling fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@749 ce417995-dfc9-0310-95a0-acdaff106893
* some minor fixlets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@748 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel :
  * Changed ModuleControlInterface to DataFlowInterface
  * selecting can happen again any time
  * Doc update for converting old components to new
  * Removed old examples
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@747 ce417995-dfc9-0310-95a0-acdaff106893
* minor spelling fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@746 ce417995-dfc9-0310-95a0-acdaff106893
* ControlKernel Doc :
  * Added some explenation about what selection really is
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@745 ce417995-dfc9-0310-95a0-acdaff106893
* Parser Doc :
  * Modified example for correctness
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@744 ce417995-dfc9-0310-95a0-acdaff106893
* Parser Doc :
  * Removed old documents
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@743 ce417995-dfc9-0310-95a0-acdaff106893
* All Components :
  * The constructor gets an optional argument denoting the string name
  So that the user can easily override it.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@742 ce417995-dfc9-0310-95a0-acdaff106893
* A slightly more verbose description for property updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@739 ce417995-dfc9-0310-95a0-acdaff106893
* Device drivers compile fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@738 ce417995-dfc9-0310-95a0-acdaff106893
* make subversion ignore some files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@737 ce417995-dfc9-0310-95a0-acdaff106893
* make subversion ignore some files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@736 ce417995-dfc9-0310-95a0-acdaff106893
* make subversion ignore some files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@735 ce417995-dfc9-0310-95a0-acdaff106893
* ecosconfig template only needs to be run in new_packages, not in all_packages, because it will override user configuration
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@734 ce417995-dfc9-0310-95a0-acdaff106893
* Fix compile failure caused by a missing #include
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@733 ce417995-dfc9-0310-95a0-acdaff106893
* Corelib/Doc :
  * updated makefile
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@732 ce417995-dfc9-0310-95a0-acdaff106893
* Fix deactivated property
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@731 ce417995-dfc9-0310-95a0-acdaff106893
* Installation Manual:
  * Some clarifications about bootstrap.sh
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@730 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation cleanup in base/doc dir
  * Removed old irelevant files
  * added the orocos-manual.xml.in file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@729 ce417995-dfc9-0310-95a0-acdaff106893
* Addeed missing doc files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@728 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation update :
  * All xml files are articles
  * Adapted to work with xinclude
  * All packages contains now truly all packages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@727 ce417995-dfc9-0310-95a0-acdaff106893
* HMI :
  Fixed uninitialized pointer
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@726 ce417995-dfc9-0310-95a0-acdaff106893
* fixed missing description tag
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@725 ce417995-dfc9-0310-95a0-acdaff106893
* Parent file for All Orocos Documentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@724 ce417995-dfc9-0310-95a0-acdaff106893
* CoreLib Commands :
  added the newCommandFunctor factory function
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@723 ce417995-dfc9-0310-95a0-acdaff106893
* Processor :
  * Added commandfunctor docs
  * fixed figures
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@722 ce417995-dfc9-0310-95a0-acdaff106893
* CoreLib - Commands
  Renamed CommandFunction to CommandFunctor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@721 ce417995-dfc9-0310-95a0-acdaff106893
* Hardware Components :
  * documentation improvements
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@720 ce417995-dfc9-0310-95a0-acdaff106893
* Process Control :
  * Cleanup of PID controller and partial antiwindup fix
  * typo fixes in cdl files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@719 ce417995-dfc9-0310-95a0-acdaff106893
* MotionControl :
  * Added example cpf file for APGenerator
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@718 ce417995-dfc9-0310-95a0-acdaff106893
* Motion Control :
  * Major doc update for Axis* Components
  * Added remove* methods to sensor, effector
  * cdl description updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@717 ce417995-dfc9-0310-95a0-acdaff106893
* Geometry :
  * Initialised trajectory parameters to zero
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@716 ce417995-dfc9-0310-95a0-acdaff106893
* Execution :
  * slight cdl file update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@715 ce417995-dfc9-0310-95a0-acdaff106893
* ControlKernel :
  * cdl description updates+ check for valid priorities.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@714 ce417995-dfc9-0310-95a0-acdaff106893
* CoreLib :
  * cdl description updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@713 ce417995-dfc9-0310-95a0-acdaff106893
* Properties :
  *Implemented proper vector<double> composition/decomposition
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@712 ce417995-dfc9-0310-95a0-acdaff106893
* Command Factory :
  * Fix command argument type mismatch reported by SVDB
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@711 ce417995-dfc9-0310-95a0-acdaff106893
* Base :
  * removed src directory
  * less strict automake requirements
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@706 ce417995-dfc9-0310-95a0-acdaff106893
* Hardware Components :
  * Changed ChannelMeasurements to ChannelValues
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@705 ce417995-dfc9-0310-95a0-acdaff106893
* Process Control :
  * Added PID Controller (in testing)
  * Added Property files for P\_ and PID_Controller
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@704 ce417995-dfc9-0310-95a0-acdaff106893
* Motion Control :
  * Changed "ChannelMeasurements" to "ChannelValues"
  * componentStartup for AxisSensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@703 ce417995-dfc9-0310-95a0-acdaff106893
* ControlKernel :
  * ReportingExtension Doc update
  * small EE fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@702 ce417995-dfc9-0310-95a0-acdaff106893
* CoreLib :
  * Explicit Instantiations of MultiVector<>
  * General separate compilation enhancements for Properties
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@701 ce417995-dfc9-0310-95a0-acdaff106893
* Device Interface :
  * Minor Documentation updates
  * Added a nameserver to EncoderInterface
  * Separate compilation of headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@700 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel :
  * Introduced new style Buffered and Cascade Control Kernels
  * Finished Component reloading cycle
  * Various internal improvements
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@699 ce417995-dfc9-0310-95a0-acdaff106893
* Generic Hardware Components :
  * Changed to template-less implementation
  * Fixed obligatory Channels bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@698 ce417995-dfc9-0310-95a0-acdaff106893
* Common Components :
  * Added a libreadline HMI input processor
  * Moved to template-less component implementation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@697 ce417995-dfc9-0310-95a0-acdaff106893
* Process Control Components
  * Cleanup P_Controller implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@696 ce417995-dfc9-0310-95a0-acdaff106893
* Motion Control Components :
  * Converted to template-less Components
  * Removed deprecated components
  * Testing of Axis* Components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@695 ce417995-dfc9-0310-95a0-acdaff106893
* Device Drivers :
  * Fixed limits/out of range detection and correction mechanisms
  * Fixed BeckhoffDOut.switchOff() bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@694 ce417995-dfc9-0310-95a0-acdaff106893
* Program Parser :
  * Added more verbose syntax checking
  * Added the for( ; ; ) statement
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@693 ce417995-dfc9-0310-95a0-acdaff106893
* Process Control Components :
  * completely moved over to new kernel infrastructure.
  * Fixed the SignalGenerator Commands (reported by S. Vdb )
  * Renamed Channel_P_Controller to P_Controller
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@692 ce417995-dfc9-0310-95a0-acdaff106893
* Control Kernel
  * Rewrote the ControlKernel docs for new kernel infrastructure
  * Cascading moves over to new infrastructure
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@691 ce417995-dfc9-0310-95a0-acdaff106893
* ExecutionExtension:
  * Programs get a name from the script itself
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@690 ce417995-dfc9-0310-95a0-acdaff106893
* Program Parser
  * Added better syntax error detection in program scripts
  * Added while and if/then/else statement to script language
  * Better parser headerfile management
  * Removed the goto statement and labels (got to much flames)
  (goto next replaced by 'continue')
  * As usual, updated the docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@689 ce417995-dfc9-0310-95a0-acdaff106893
* Program Processor :
  * Programs must have a name now
  * Added the if .. then .. else statement
  and added the while (...) statement
  to the program-graph factory
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@688 ce417995-dfc9-0310-95a0-acdaff106893
* * Various warning fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@687 ce417995-dfc9-0310-95a0-acdaff106893
* removed non working drive software limits
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@686 ce417995-dfc9-0310-95a0-acdaff106893
* * Online Manual cleanup , removing outdated docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@685 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed DataObject FrontEnd code to use the correct
  interface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@684 ce417995-dfc9-0310-95a0-acdaff106893
* SJA 1000 canpie for lxrt cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@683 ce417995-dfc9-0310-95a0-acdaff106893
* updated lvd template
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@681 ce417995-dfc9-0310-95a0-acdaff106893
* KinematicsComponent:
  * Added pragma interface/implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@680 ce417995-dfc9-0310-95a0-acdaff106893
* Geometry:
  * Added explicit template instantiations for common
  Geometry Properties
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@679 ce417995-dfc9-0310-95a0-acdaff106893
* DistanceSensor:
  * Added CalibrationInterface methods
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@678 ce417995-dfc9-0310-95a0-acdaff106893
* Device Interface:
  * Merged CalibrationInterface with SensorInterface<>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@677 ce417995-dfc9-0310-95a0-acdaff106893
* CoreLib:
  * Split headers in interface and implementation
  * Generated explicit instantiations of common property types
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@676 ce417995-dfc9-0310-95a0-acdaff106893
* Hardware Components :
  * Separate Compilation
  * Changed dynamic adding of sensors using kernel->reload
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@675 ce417995-dfc9-0310-95a0-acdaff106893
* Common Components:
  * Separate compilation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@674 ce417995-dfc9-0310-95a0-acdaff106893
* Process Control Components :
  * Separate compilation
  * Fixed SignalGenerator and -Tracker
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@673 ce417995-dfc9-0310-95a0-acdaff106893
* Motion Control Components :
  * Separate compilation of all components
  * Corrected missing headers
  * Corrected non compiling code
  * gcc 3.4 and 3.3 tests
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@672 ce417995-dfc9-0310-95a0-acdaff106893
* * new generation ControlKernel
  * Split KernelInterfaces.hpp in multiple files
  * Introduced the 'new' StandardControlKernel (using NextGenKernel)
  * Finished facilities for independent component compilation
  * Split headers into interface and implementation files
  * gcc 3.4 and 3.3 testing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@671 ce417995-dfc9-0310-95a0-acdaff106893
* * AxisEffector, AxisSensor, GenericEffector, GenericSensor,
  HMIConsoleInput, HMIConsoleOutput : explicit template
  instantiation in a .cxx file. This still allows non
  gcc compilers to use only the header file.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@670 ce417995-dfc9-0310-95a0-acdaff106893
* removed double definition of 'max'
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@669 ce417995-dfc9-0310-95a0-acdaff106893
* fix missing const in GenericSensor::isOn()
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@668 ce417995-dfc9-0310-95a0-acdaff106893
* * Added the MakeExtension<> Helper class
  * Fixed NameSubClass DataObject NameServer bugs
  * Fixed missing update() methods
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@667 ce417995-dfc9-0310-95a0-acdaff106893
* * Added HMI for the new generation kernel with separate compilation
  of components. The new version is called *Impl, so the original
  kernel uses remain.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@666 ce417995-dfc9-0310-95a0-acdaff106893
* Tested with GCC 3.4
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@665 ce417995-dfc9-0310-95a0-acdaff106893
* Tested Kernel Components with gcc 3.4
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@664 ce417995-dfc9-0310-95a0-acdaff106893
* Introducing the NextGen Control Kernels,
  using 'almost' standalone components which
  allows separate compilation.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@663 ce417995-dfc9-0310-95a0-acdaff106893
* Introduced a solution to fix RedHat i386
  atomicness
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@662 ce417995-dfc9-0310-95a0-acdaff106893
* *Added section about support components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@661 ce417995-dfc9-0310-95a0-acdaff106893
* gcc 3.4 updates
  svn test fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@660 ce417995-dfc9-0310-95a0-acdaff106893
* gcc 3.4 fixes
  removed deprecated trajectory class
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@659 ce417995-dfc9-0310-95a0-acdaff106893
* GCC 3.4 updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@658 ce417995-dfc9-0310-95a0-acdaff106893
* * Added an emit event command
  * doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@657 ce417995-dfc9-0310-95a0-acdaff106893
* Docu updates on Tasks
  Multivector operators
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@656 ce417995-dfc9-0310-95a0-acdaff106893
* doxygen update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@655 ce417995-dfc9-0310-95a0-acdaff106893
* * GCC3.4 fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@654 ce417995-dfc9-0310-95a0-acdaff106893
* * Removed the getName() method
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@653 ce417995-dfc9-0310-95a0-acdaff106893
* * GCC 3.4 fixes
  * Added support for sub-indexing the double6d type
  * updated docs with mbsc comments
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@652 ce417995-dfc9-0310-95a0-acdaff106893
* * removed the getName method of commands
  * added the program name
  * fixed to late reset of conditions in graph traversing
  * GCC 3.4 fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@651 ce417995-dfc9-0310-95a0-acdaff106893
* * Compiled with GCC 3.4
  * Updated docs with comments of mbsc
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@650 ce417995-dfc9-0310-95a0-acdaff106893
* script for generating lgpl headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@647 ce417995-dfc9-0310-95a0-acdaff106893
* * inserted missing using namespace ORO_Execution (fix by: "Andrea Consonni")
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@646 ce417995-dfc9-0310-95a0-acdaff106893
* * make use of the stepped/continuous state contexts in ExecExt
  * fix wrongly implemented implicit termination conditions on ExecExt commands
  * Added the isSelected() method call to the ComponentBaseInterface
  * updated the docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@645 ce417995-dfc9-0310-95a0-acdaff106893
* * implement stepped vs continuous mode for StateContexts
  in the Processor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@644 ce417995-dfc9-0310-95a0-acdaff106893
* * Moved the CalibrationInterface to the device_interface package
  * Start using calibration in EncoderPositionSensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@643 ce417995-dfc9-0310-95a0-acdaff106893
* Removed the Any-Transition from the StateContext.
  It was ambiguous in its specification and implementation.
  It can still be simulated (the correct way that is) using
  the normal transitionSet method.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@636 ce417995-dfc9-0310-95a0-acdaff106893
* k600 cdl file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@629 ce417995-dfc9-0310-95a0-acdaff106893
* version change to 0.14.2
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@618 ce417995-dfc9-0310-95a0-acdaff106893
* Added 0.14.2 release notes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@617 ce417995-dfc9-0310-95a0-acdaff106893
* Added the LGPL
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@613 ce417995-dfc9-0310-95a0-acdaff106893
* fixed bugs reported by
  "Andrea Consonni" <conandre at tin it>
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@610 ce417995-dfc9-0310-95a0-acdaff106893
* * fixed license 'typo'
  * fixed memleak in breakset.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@608 ce417995-dfc9-0310-95a0-acdaff106893
* Changed GPL to LGPL
  added LGPL to cxx files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@607 ce417995-dfc9-0310-95a0-acdaff106893
* this include cannot work
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@606 ce417995-dfc9-0310-95a0-acdaff106893
* Put this where it belongs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@605 ce417995-dfc9-0310-95a0-acdaff106893
* Move away from orocos apps.  This is not xytable specific code
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@604 ce417995-dfc9-0310-95a0-acdaff106893
* Move this from orocos-apps, as it is general code for k600 and not PMA
  xytable specific
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@603 ce417995-dfc9-0310-95a0-acdaff106893
* git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@602 ce417995-dfc9-0310-95a0-acdaff106893
* driver files for krypton k600 measurement device
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@601 ce417995-dfc9-0310-95a0-acdaff106893
* removed system control for now
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@598 ce417995-dfc9-0310-95a0-acdaff106893
* renamed template
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@597 ce417995-dfc9-0310-95a0-acdaff106893
* * added FS headers
  * package gen looks for existing version number in current repos
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@595 ce417995-dfc9-0310-95a0-acdaff106893
* makefile cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@594 ce417995-dfc9-0310-95a0-acdaff106893
* * fixed Clone() mess for velocity profiles
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@592 ce417995-dfc9-0310-95a0-acdaff106893
* fixed 'return delete' bug
  typo/layout fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@589 ce417995-dfc9-0310-95a0-acdaff106893
* fixed uninitialised pointer
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@588 ce417995-dfc9-0310-95a0-acdaff106893
* Removed -g flag
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@587 ce417995-dfc9-0310-95a0-acdaff106893
* better make instructions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@586 ce417995-dfc9-0310-95a0-acdaff106893
* aesthetic updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@585 ce417995-dfc9-0310-95a0-acdaff106893
* * rename to DataSourceFactoryInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@584 ce417995-dfc9-0310-95a0-acdaff106893
* * renamed DataSourceFactory to DataSourceFactoryInterface
  * Prettier HMIConsoleInput ( also data sources )
  * HMIConsoleOutput prints now 4 types of messages (string, bool, int, double)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@583 ce417995-dfc9-0310-95a0-acdaff106893
* * stressed 'const' requirement on termination conditions and Data Sources
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@582 ce417995-dfc9-0310-95a0-acdaff106893
* * Renamed DataSourceFactory to DataSourceFactoryInterface
  * Split DataSourceFactoryInterface and GlobalDataSourceFactory
  in two header files
  * Added DataSource browsing support
  * fixed resulting include directives
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@581 ce417995-dfc9-0310-95a0-acdaff106893
* * Deprecated (removed :-] ) the Component::nameserver
  * Removed the load[Component]( name ) functions
  * Moved the kernel Execution Commands and Data to the KernelBaseFunction
  * Fixed KernelConfig null pointer
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@579 ce417995-dfc9-0310-95a0-acdaff106893
* fixed two compile time bugs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@578 ce417995-dfc9-0310-95a0-acdaff106893
* *Doxygen updates
  * Added EE commands to GenericEffector and GenericSensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@577 ce417995-dfc9-0310-95a0-acdaff106893
* moved the docbook .xml files to the correct .sgml extension
  updated Makefile for building html docs (ps/pdf don't work)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@576 ce417995-dfc9-0310-95a0-acdaff106893
* Added generic hardware docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@575 ce417995-dfc9-0310-95a0-acdaff106893
* * doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@574 ce417995-dfc9-0310-95a0-acdaff106893
* removed applications/testcase
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@572 ce417995-dfc9-0310-95a0-acdaff106893
* Added Free Software License
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@571 ce417995-dfc9-0310-95a0-acdaff106893
* small docu/Makefile updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@570 ce417995-dfc9-0310-95a0-acdaff106893
* Added Herman's Orocos Documents
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@569 ce417995-dfc9-0310-95a0-acdaff106893
* * layout/doc changes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@568 ce417995-dfc9-0310-95a0-acdaff106893
* changed Component Thread to Periodic Thread
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@567 ce417995-dfc9-0310-95a0-acdaff106893
* fixed RTAI 3.x support
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@566 ce417995-dfc9-0310-95a0-acdaff106893
* * finished the Axis rework
  * moved breaks from AnalogDrive back to Axis
  * Added usefull sensors, which can be added to the Axis
  * Added a calibrationInterface ( not completed yet )
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@565 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@564 ce417995-dfc9-0310-95a0-acdaff106893
* * Changed the 'select' semantics to only select in running kernels
  * Added the "ConfigureOnLoad" property for the PropertyExtension
  * Fixed the half-way initialize bug when kernel start fails
  * Added the "StartupComponents" kernel property
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@563 ce417995-dfc9-0310-95a0-acdaff106893
* moved the Axis stuff to motion control
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@562 ce417995-dfc9-0310-95a0-acdaff106893
* * tested position generator
  * Added execution engine commands
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@561 ce417995-dfc9-0310-95a0-acdaff106893
* * fixed crash bug in input when help was requested
  * added colorisation to output messages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@560 ce417995-dfc9-0310-95a0-acdaff106893
* * tested and verified first version of AxisSensor/Effector
  * updated GenericSensor with changed device interface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@559 ce417995-dfc9-0310-95a0-acdaff106893
* * Added support for 3 arguments commands
  * fixed the not initialized pointer conditions in StateGraphs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@558 ce417995-dfc9-0310-95a0-acdaff106893
* update to new SensorInterface API
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@556 ce417995-dfc9-0310-95a0-acdaff106893
* Added command+browsing support
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@554 ce417995-dfc9-0310-95a0-acdaff106893
* Added Command Browsing support
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@553 ce417995-dfc9-0310-95a0-acdaff106893
* added few 0.14.0 features
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@552 ce417995-dfc9-0310-95a0-acdaff106893
* updated docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@551 ce417995-dfc9-0310-95a0-acdaff106893
* Doxygen and documentation updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@550 ce417995-dfc9-0310-95a0-acdaff106893
* Mainly doxygen updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@549 ce417995-dfc9-0310-95a0-acdaff106893
* added doxy comments
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@548 ce417995-dfc9-0310-95a0-acdaff106893
* added SingleThread.hpp in headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@547 ce417995-dfc9-0310-95a0-acdaff106893
* slight statecontext update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@546 ce417995-dfc9-0310-95a0-acdaff106893
* removed obsolete file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@545 ce417995-dfc9-0310-95a0-acdaff106893
* restructured for configuring kernel
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@544 ce417995-dfc9-0310-95a0-acdaff106893
* just-before-release doc updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@543 ce417995-dfc9-0310-95a0-acdaff106893
* fixed missing parent
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@542 ce417995-dfc9-0310-95a0-acdaff106893
* bumped version to 0.14.0 (not official yet)
  added missing file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@539 ce417995-dfc9-0310-95a0-acdaff106893
* Added Free Software License to these files
  bumped to version 0.14.0 (not official yet)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@538 ce417995-dfc9-0310-95a0-acdaff106893
* component naming improved, fixed example layout
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@537 ce417995-dfc9-0310-95a0-acdaff106893
* added names to old style components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@536 ce417995-dfc9-0310-95a0-acdaff106893
* fixed typo causing cascade kernel not to work
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@535 ce417995-dfc9-0310-95a0-acdaff106893
* fixed inverted number_of_args error
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@534 ce417995-dfc9-0310-95a0-acdaff106893
* small changes which were caused by the valgrind+pthread
  debugging day
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@526 ce417995-dfc9-0310-95a0-acdaff106893
* * fixed nan for zero-movement path
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@525 ce417995-dfc9-0310-95a0-acdaff106893
* * fixed safetystop in CartesianNSGenerator
  * HMI components have console\_[input|output] name
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@524 ce417995-dfc9-0310-95a0-acdaff106893
* * fixed fallback select segfault bug
  * implemented ordered transitions
  * numerous memleak cleanups
  * typo in ProcessorInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@523 ce417995-dfc9-0310-95a0-acdaff106893
* * execution extension interface methods return bool
  * fixed numerous memory leaks with XML and property bags
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@522 ce417995-dfc9-0310-95a0-acdaff106893
* *Added transition priorities to states, so that the
  transition evaluation order is deterministic.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@521 ce417995-dfc9-0310-95a0-acdaff106893
* fixed the numerous XMLString::transcode and other memory leaks
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@520 ce417995-dfc9-0310-95a0-acdaff106893
* Restructured the marshalling directory, preparing to
  make .cxx files out of .hpp files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@519 ce417995-dfc9-0310-95a0-acdaff106893
* fixed memory leak
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@518 ce417995-dfc9-0310-95a0-acdaff106893
* * bugfix forgetting de-init xml environment
  * better exception handling
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@517 ce417995-dfc9-0310-95a0-acdaff106893
* Made Component names mandatory
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@516 ce417995-dfc9-0310-95a0-acdaff106893
* *Added experimental path_line from twist constructor
  * To be tested !
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@503 ce417995-dfc9-0310-95a0-acdaff106893
* * core re-arranging
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@502 ce417995-dfc9-0310-95a0-acdaff106893
* * programs are now controlled by "name"
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@501 ce417995-dfc9-0310-95a0-acdaff106893
* * fixed wrong kernel examples
  * added more ExecExt examples and corrections
  * removed some unclear parts
  * added Loki copyright notice
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@500 ce417995-dfc9-0310-95a0-acdaff106893
* changed signal_processing by process_control
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@499 ce417995-dfc9-0310-95a0-acdaff106893
* doc update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@498 ce417995-dfc9-0310-95a0-acdaff106893
* Added isProgram/StateContextRunning methods
  * doc update
  * code cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@497 ce417995-dfc9-0310-95a0-acdaff106893
* * added virtual destructors everywhere
  * doc reformatting
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@496 ce417995-dfc9-0310-95a0-acdaff106893
* * Changed Drive to AnalogDrive
  * Added AnalogSensor reading
  * Many semantic changes in Axis and Drive
  * usability of A/D IO improved
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@495 ce417995-dfc9-0310-95a0-acdaff106893
* Added fake device driver implementations,
  implementing a part of device interfaces
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@494 ce417995-dfc9-0310-95a0-acdaff106893
* Adaptation to the CoreLib RunnableInterface
  Adaptation to changing device interfaces
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@493 ce417995-dfc9-0310-95a0-acdaff106893
* * made sensorinterface usable
  * code cleanups
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@492 ce417995-dfc9-0310-95a0-acdaff106893
* A P controller on channel level
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@491 ce417995-dfc9-0310-95a0-acdaff106893
* a simple move generator for multiple axes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@490 ce417995-dfc9-0310-95a0-acdaff106893
* * Axis level effector and sensor (commands to be added)
  * Generic HW fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@489 ce417995-dfc9-0310-95a0-acdaff106893
* changes to AnalogDrive
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@479 ce417995-dfc9-0310-95a0-acdaff106893
* fixed double name overwriting
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@473 ce417995-dfc9-0310-95a0-acdaff106893
* Added functionobject wrapper for commands
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@469 ce417995-dfc9-0310-95a0-acdaff106893
* forgot this cdl file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@468 ce417995-dfc9-0310-95a0-acdaff106893
* Added the analog 'channel' implementations
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@467 ce417995-dfc9-0310-95a0-acdaff106893
* debugging, doc fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@466 ce417995-dfc9-0310-95a0-acdaff106893
* BIG changes :
  * switched to loki's typelist implementation (copyright/license remains)
  * The DataObject::Get(void) method returns now a copy instead of a const ref
  this is far more thread safe.
  * DataObject composition is halfway user usability (make it also a typelist)
  ComposeDataObjects<D1, D2, D3...>
  * Reporting DataObject implementation
  * removed Kernel and Component name change in cpf files (way to messy)
  * changed the prefix/name semantics :
  name : is the name of the kernel and always given, is used as the default prefix.
  prefix: use this to have access to the dataobjects of another kernel (prefixes
  can be common).
  * Added saner error reporting where it crashed on my head :-)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@465 ce417995-dfc9-0310-95a0-acdaff106893
* updated with new packages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@464 ce417995-dfc9-0310-95a0-acdaff106893
* * Used line numbering support
  * Support for nullary condition checking
  * support for binary functors
  * support for final states
  * changed a little bit syntax
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@463 ce417995-dfc9-0310-95a0-acdaff106893
* removed old processor states
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@462 ce417995-dfc9-0310-95a0-acdaff106893
* Rewritten processor. I am dropping the Processor
  States and introduce Program or State states, so
  that we can track multiple programs and states.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@461 ce417995-dfc9-0310-95a0-acdaff106893
* *Added the position tracker
  *split the components in separate files
  *docu update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@460 ce417995-dfc9-0310-95a0-acdaff106893
* components for signal processing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@459 ce417995-dfc9-0310-95a0-acdaff106893
* Kernel Components for accessing any kind of hardware
  which is known in the ORO_DeviceInterface.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@458 ce417995-dfc9-0310-95a0-acdaff106893
* Some common control kernel components, like
  a Console Based HMI
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@457 ce417995-dfc9-0310-95a0-acdaff106893
* Initial signal processing library
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@456 ce417995-dfc9-0310-95a0-acdaff106893
* replaced s/ComponentThreaded/PeriodicThread/g
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@449 ce417995-dfc9-0310-95a0-acdaff106893
* Renaming of the ComponentThreaded To PeriodicThread
  Docs adapted in os dir
  Compiles on my pc.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@448 ce417995-dfc9-0310-95a0-acdaff106893
* * Added unsigned int marshalling
  * Added std::vector composition/decomposition
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@447 ce417995-dfc9-0310-95a0-acdaff106893
* Added the notion of a Final state
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@446 ce417995-dfc9-0310-95a0-acdaff106893
* File rename of ComponentThreaded to PeriodicThread
  Class rename is next commit
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@445 ce417995-dfc9-0310-95a0-acdaff106893
* An introspector which places the results of introspection
  in a propertybag.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@414 ce417995-dfc9-0310-95a0-acdaff106893
* forgot to make destructor virtual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@413 ce417995-dfc9-0310-95a0-acdaff106893
* make destructor virtual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@412 ce417995-dfc9-0310-95a0-acdaff106893
* removed very old files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@389 ce417995-dfc9-0310-95a0-acdaff106893
* removed a plain wrong comparison
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@387 ce417995-dfc9-0310-95a0-acdaff106893
* forgot to return true
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@386 ce417995-dfc9-0310-95a0-acdaff106893
* use the optional updateKernelProperties again.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@382 ce417995-dfc9-0310-95a0-acdaff106893
* fixed some updateProperty ambiguities
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@381 ce417995-dfc9-0310-95a0-acdaff106893
* devices_lxrt.h and devices_lxrt.c are renamed since deprecated.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@372 ce417995-dfc9-0310-95a0-acdaff106893
* Added offsets and transformationset
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@371 ce417995-dfc9-0310-95a0-acdaff106893
* Changed include flags
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@370 ce417995-dfc9-0310-95a0-acdaff106893
* Removed EncoderIncremental compilation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@369 ce417995-dfc9-0310-95a0-acdaff106893
* Devices_lxrt files are deprecated.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@368 ce417995-dfc9-0310-95a0-acdaff106893
* Added JR3 settransform
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@367 ce417995-dfc9-0310-95a0-acdaff106893
* fixed comment typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@366 ce417995-dfc9-0310-95a0-acdaff106893
* Another documentation roundup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@365 ce417995-dfc9-0310-95a0-acdaff106893
* Some Docu + code cleanup.
  Added dirac velocity profile ( step on position ).
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@354 ce417995-dfc9-0310-95a0-acdaff106893
* Deleted EncoderAbsolute and EncoderIncrementalapci1710.cxx
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@334 ce417995-dfc9-0310-95a0-acdaff106893
* there can be only one
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@333 ce417995-dfc9-0310-95a0-acdaff106893
* there can be only one
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@332 ce417995-dfc9-0310-95a0-acdaff106893
* there can be only one
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@331 ce417995-dfc9-0310-95a0-acdaff106893
* preliminary attempt for PositionInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@330 ce417995-dfc9-0310-95a0-acdaff106893
* preliminary attempt for PositionInterface where position sensor is an encoder
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@329 ce417995-dfc9-0310-95a0-acdaff106893
* preliminary attempt for PositionInterface where position sensor is an encoder
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@328 ce417995-dfc9-0310-95a0-acdaff106893
* comediencoder instead of comediIncrementalEncoder: herit from new and unique encoder interface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@327 ce417995-dfc9-0310-95a0-acdaff106893
* deprecated, only use new and unique encoder interface from now on
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@326 ce417995-dfc9-0310-95a0-acdaff106893
* deprecated, only use new and unique encoder interface from now on
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@325 ce417995-dfc9-0310-95a0-acdaff106893
* herit from new and unique encoder interface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@324 ce417995-dfc9-0310-95a0-acdaff106893
* herit from new and unique encoder interface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@323 ce417995-dfc9-0310-95a0-acdaff106893
* *version bump to 0.13.0
  *better config detection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@322 ce417995-dfc9-0310-95a0-acdaff106893
* *Build system updates
  * better detecting of xerces
  * added link in api intro
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@321 ce417995-dfc9-0310-95a0-acdaff106893
* more userfriendly info
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@320 ce417995-dfc9-0310-95a0-acdaff106893
* * small code/doc cleanups
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@319 ce417995-dfc9-0310-95a0-acdaff106893
* * Property Operations thread-safety cleanup
  * fixes based on DataObject reporting in Control Kernel
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@318 ce417995-dfc9-0310-95a0-acdaff106893
* nameserver cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@317 ce417995-dfc9-0310-95a0-acdaff106893
* * Added DataObject Reporting, tested to be working
  * KernelName in xml config is now respected.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@316 ce417995-dfc9-0310-95a0-acdaff106893
* Updated docs with pictures
  Added reporting DataObjects
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@315 ce417995-dfc9-0310-95a0-acdaff106893
* Fix rtos_printf statement
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@311 ce417995-dfc9-0310-95a0-acdaff106893
* Fix bug:  Semafore must be signalled before calling rt_task_delete
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@310 ce417995-dfc9-0310-95a0-acdaff106893
* forgot to post sem
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@309 ce417995-dfc9-0310-95a0-acdaff106893
* Removed ComponentOneShot and added the SingleThread
  for gnu/linux.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@308 ce417995-dfc9-0310-95a0-acdaff106893
* Added Single Thread support
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@307 ce417995-dfc9-0310-95a0-acdaff106893
* modified the script to allow pre-release testing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@303 ce417995-dfc9-0310-95a0-acdaff106893
* rtos_printf has moved
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@302 ce417995-dfc9-0310-95a0-acdaff106893
* driver now part of comedi
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@301 ce417995-dfc9-0310-95a0-acdaff106893
* The new NEWS file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@298 ce417995-dfc9-0310-95a0-acdaff106893
* deleted the empty file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@297 ce417995-dfc9-0310-95a0-acdaff106893
* version bump to 0.12.0
  make clean_packages removes the libtarget.a file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@296 ce417995-dfc9-0310-95a0-acdaff106893
* docbook improvements, using stylesheet
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@295 ce417995-dfc9-0310-95a0-acdaff106893
* fixed typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@294 ce417995-dfc9-0310-95a0-acdaff106893
* workaround a strange configtool bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@293 ce417995-dfc9-0310-95a0-acdaff106893
* Updated the descriptions per package.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@290 ce417995-dfc9-0310-95a0-acdaff106893
* Added missing descriptions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@289 ce417995-dfc9-0310-95a0-acdaff106893
* Docu gen fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@288 ce417995-dfc9-0310-95a0-acdaff106893
* report crash solved,
  ports for nameserved DOs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@287 ce417995-dfc9-0310-95a0-acdaff106893
* added standard-control-kernel.* generation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@286 ce417995-dfc9-0310-95a0-acdaff106893
* Docu generation fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@285 ce417995-dfc9-0310-95a0-acdaff106893
* docu generation fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@284 ce417995-dfc9-0310-95a0-acdaff106893
* * bumped version number
  * packaging improvements
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@283 ce417995-dfc9-0310-95a0-acdaff106893
* *Docu generation fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@282 ce417995-dfc9-0310-95a0-acdaff106893
* * Updated parser with big example
  * added ValueChange parsing in states
  * testing and bug fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@281 ce417995-dfc9-0310-95a0-acdaff106893
* Added version 0.12.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@280 ce417995-dfc9-0310-95a0-acdaff106893
* Revised document by hb
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@279 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed long overflow
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@277 ce417995-dfc9-0310-95a0-acdaff106893
* Did proper implementation of nameserving.
  copied old version to CartesianNSExample.hpp
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@276 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed non virtual destructor bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@273 ce417995-dfc9-0310-95a0-acdaff106893
* Added homing setframe command
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@272 ce417995-dfc9-0310-95a0-acdaff106893
* * Fixed grave 'only last transition is stored' bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@270 ce417995-dfc9-0310-95a0-acdaff106893
* * include flag fix
  * include fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@269 ce417995-dfc9-0310-95a0-acdaff106893
* execution package macro detection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@268 ce417995-dfc9-0310-95a0-acdaff106893
* xml stylesheets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@267 ce417995-dfc9-0310-95a0-acdaff106893
* * xml stylesheets
  * code cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@266 ce417995-dfc9-0310-95a0-acdaff106893
* typo fix for device_drivers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@265 ce417995-dfc9-0310-95a0-acdaff106893
* using xml stylesheet
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@264 ce417995-dfc9-0310-95a0-acdaff106893
* Corrected build number generation !
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@263 ce417995-dfc9-0310-95a0-acdaff106893
* using orocos stylesheet for docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@262 ce417995-dfc9-0310-95a0-acdaff106893
* * Reporting headerless-ness
  * Reporting copy intervals (still buggy, default works)
  * small doc updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@261 ce417995-dfc9-0310-95a0-acdaff106893
* Slight rewrite of the MarshallConfiguration
  To allow empty headers
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@260 ce417995-dfc9-0310-95a0-acdaff106893
* Added EulerZYX motion properties support
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@259 ce417995-dfc9-0310-95a0-acdaff106893
* Added xml example files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@258 ce417995-dfc9-0310-95a0-acdaff106893
* *checking for python and tcl
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@256 ce417995-dfc9-0310-95a0-acdaff106893
* * Removed boost dependency
  * slight docu update about threading
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@255 ce417995-dfc9-0310-95a0-acdaff106893
* more sane distribution default (added minimal template)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@254 ce417995-dfc9-0310-95a0-acdaff106893
* * StateGraph Parser syntax checking improved
  * template typo fix
  * compile without -g
  * state has still strange bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@253 ce417995-dfc9-0310-95a0-acdaff106893
* * unsigned comparison fix
  * added checking for kernel components in EE
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@252 ce417995-dfc9-0310-95a0-acdaff106893
* Added the common devicedrivers stuff to the template
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@251 ce417995-dfc9-0310-95a0-acdaff106893
* Driver is now accepted into comedi.  Slight API changes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@248 ce417995-dfc9-0310-95a0-acdaff106893
* Driver is now accepted into comedi
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@247 ce417995-dfc9-0310-95a0-acdaff106893
* Added OROINT_DEVICE_DRIVERS_JR3.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@246 ce417995-dfc9-0310-95a0-acdaff106893
* Major change to EncoderSSIapci1710.
  Smaller change of apci <--> lxrt.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@245 ce417995-dfc9-0310-95a0-acdaff106893
* Added bool invert
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@244 ce417995-dfc9-0310-95a0-acdaff106893
* remove evil config.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@242 ce417995-dfc9-0310-95a0-acdaff106893
* remove evil config.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@241 ce417995-dfc9-0310-95a0-acdaff106893
* remove evil config.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@240 ce417995-dfc9-0310-95a0-acdaff106893
* remove evil config.h
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@239 ce417995-dfc9-0310-95a0-acdaff106893
* typo fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@238 ce417995-dfc9-0310-95a0-acdaff106893
* Added comedi include option
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@237 ce417995-dfc9-0310-95a0-acdaff106893
* documentation update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@236 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation updates for States
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@235 ce417995-dfc9-0310-95a0-acdaff106893
* APCI KM compilation for LXRT
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@234 ce417995-dfc9-0310-95a0-acdaff106893
* Added OROINT_DEVICE_DRIVERS_APCI1032
  and OROINT_DEVICE_DRIVERS_APCI2200
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@233 ce417995-dfc9-0310-95a0-acdaff106893
* Added our own XSL stylesheet for fop
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@232 ce417995-dfc9-0310-95a0-acdaff106893
* Added priority-thread examples
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@231 ce417995-dfc9-0310-95a0-acdaff106893
* Shortened the HB test, fixed the 'easter egg' bug :-)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@230 ce417995-dfc9-0310-95a0-acdaff106893
* Thank you klaas for this fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@229 ce417995-dfc9-0310-95a0-acdaff106893
* corrected makefile deps for pdf generation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@228 ce417995-dfc9-0310-95a0-acdaff106893
* removed compiler warning
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@227 ce417995-dfc9-0310-95a0-acdaff106893
* Program+State testing of these components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@226 ce417995-dfc9-0310-95a0-acdaff106893
* empty name now allowed for thread creation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@225 ce417995-dfc9-0310-95a0-acdaff106893
* Evil fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@224 ce417995-dfc9-0310-95a0-acdaff106893
* Adaptation to the new RunnableInterface in CoreLib
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@223 ce417995-dfc9-0310-95a0-acdaff106893
* compilation cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@222 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation generation fix for fop
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@221 ce417995-dfc9-0310-95a0-acdaff106893
* Taskinfrastructure is now better of with a new
  RunnableInterface and TaskInterface. The former keeps
  track of the TaskInterface running it.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@220 ce417995-dfc9-0310-95a0-acdaff106893
* Compile fixes for the PriorityThread
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@219 ce417995-dfc9-0310-95a0-acdaff106893
* Better state machine implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@218 ce417995-dfc9-0310-95a0-acdaff106893
* Added the generic priority thread for
  people who need more than 3 threads.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@217 ce417995-dfc9-0310-95a0-acdaff106893
* * PropertySequence mess cleanup
  * Rest is mainly indentation formatting
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@216 ce417995-dfc9-0310-95a0-acdaff106893
* * State Graph Parser written.
  * Removed old Program files
  * Docs need to be updated
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@215 ce417995-dfc9-0310-95a0-acdaff106893
* Program Processor Completely Rewritten
  * All is now done by Boost::graph
  * Program States And Programs supported
  * Docs need to be rewritten...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@214 ce417995-dfc9-0310-95a0-acdaff106893
* * Added Execution Extension StateGraph parsing
  * Added Kernel Command Execution from scripts
  * Changed the PropertyExtension to support many components
  ( property file format changed )
  * Reindenting the KernelInterfaces by accident :-)
  * Added the SupportComponent for Kernel Integration
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@213 ce417995-dfc9-0310-95a0-acdaff106893
* * orocos-install.tcl fixes
  * slicker install docs
  * release 0.10.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@211 ce417995-dfc9-0310-95a0-acdaff106893
* * Device Interface documentation update
  * CoreLib requires boost
  * orocos-install.tcl preconfigure fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@210 ce417995-dfc9-0310-95a0-acdaff106893
* Added eCos tools and eCos install for Orocos
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@209 ce417995-dfc9-0310-95a0-acdaff106893
* small rc1 release fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@204 ce417995-dfc9-0310-95a0-acdaff106893
* RTAI version selection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@203 ce417995-dfc9-0310-95a0-acdaff106893
* bootstrapping and more generic make targets
  boost::graph detection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@201 ce417995-dfc9-0310-95a0-acdaff106893
* Updated installation instructions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@200 ce417995-dfc9-0310-95a0-acdaff106893
* Release candidate fixes :
  * Boost_graph detection
  * more generic make targets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@199 ce417995-dfc9-0310-95a0-acdaff106893
* Ported (while keeping backward compatible) to RTAI 3.0
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@198 ce417995-dfc9-0310-95a0-acdaff106893
* renaming
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@197 ce417995-dfc9-0310-95a0-acdaff106893
* moved boost graph
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@196 ce417995-dfc9-0310-95a0-acdaff106893
* boost graph detection
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@195 ce417995-dfc9-0310-95a0-acdaff106893
* release tweaking of build scripts
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@194 ce417995-dfc9-0310-95a0-acdaff106893
* template updates for release
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@193 ce417995-dfc9-0310-95a0-acdaff106893
* updated docs for release
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@192 ce417995-dfc9-0310-95a0-acdaff106893
* release templates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@191 ce417995-dfc9-0310-95a0-acdaff106893
* renaming the underscore
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@190 ce417995-dfc9-0310-95a0-acdaff106893
* Added distribution-wise templates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@189 ce417995-dfc9-0310-95a0-acdaff106893
* Added Free Software Copyright notice.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@185 ce417995-dfc9-0310-95a0-acdaff106893
* Added possibly :-) missing files (I really don't know !)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@184 ce417995-dfc9-0310-95a0-acdaff106893
* Added namespace descriptions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@183 ce417995-dfc9-0310-95a0-acdaff106893
* Removed debugging code
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@182 ce417995-dfc9-0310-95a0-acdaff106893
* * argc, argv typo fixed * --> ** for argv
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@181 ce417995-dfc9-0310-95a0-acdaff106893
* * mostly using the OROINT_STDIOSTREAM macro where needed
  * traphalf SetMax fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@180 ce417995-dfc9-0310-95a0-acdaff106893
* * removed execution specific files
  * commands and conditions are clonable now
  * Better XML parsing error descriptions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@179 ce417995-dfc9-0310-95a0-acdaff106893
* * a bit more helpful error tracing
  * KernelConfig is no longer templated
  * split KernelConfig in two files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@178 ce417995-dfc9-0310-95a0-acdaff106893
* Extension cleanup, file refactoring.
  ExecutionExtension has now an interval property
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@176 ce417995-dfc9-0310-95a0-acdaff106893
* * The parser now uses the ProgramGraph for
  building Programs.
  * fixed time bug
  * functions parsing support
  * program or function cloning support
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@175 ce417995-dfc9-0310-95a0-acdaff106893
* * The old Program is replaced by Boost::graph ProgramGraph
  * Functions are supported
  * time bug fixed
  * support for return statement
  * Olde code removed
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@174 ce417995-dfc9-0310-95a0-acdaff106893
* parser integration with control_kernel
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@173 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed ownership issues
  Return values in state transitions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@172 ce417995-dfc9-0310-95a0-acdaff106893
* Execution update to current code (is working now)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@171 ce417995-dfc9-0310-95a0-acdaff106893
* scriptable component
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@170 ce417995-dfc9-0310-95a0-acdaff106893
* renaming of StartUp to Startup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@168 ce417995-dfc9-0310-95a0-acdaff106893
* Added makefile
  Added NS Components
  Dataobject definitions with component definitions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@167 ce417995-dfc9-0310-95a0-acdaff106893
* componentStartUp -> componentStartup
  const bugfix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@166 ce417995-dfc9-0310-95a0-acdaff106893
* * DataBuffer rewritten, is now more efficient
  * Fixed cascading/ns compilation
  * updated docs to reflect that
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@164 ce417995-dfc9-0310-95a0-acdaff106893
* Added the CascadeNSControlKernel and names to
  DataObjects in general.
  Not tested yet, so does not compile probably.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@162 ce417995-dfc9-0310-95a0-acdaff106893
* First implementation of model based and cascade
  control kernel
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@161 ce417995-dfc9-0310-95a0-acdaff106893
* added more binary types to be recognised in the package
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@160 ce417995-dfc9-0310-95a0-acdaff106893
* compile fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@159 ce417995-dfc9-0310-95a0-acdaff106893
* * Changed DefaultControlKernel to StandardControlKernel
  * Added first cascading/modelbased kernels
  * kernel refactoring cleaned up
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@158 ce417995-dfc9-0310-95a0-acdaff106893
* Renamed to NS instead of Names
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@156 ce417995-dfc9-0310-95a0-acdaff106893
* * ComponentLoaded and componentStartUp return bool now
  * docs updated to reflect that
  * Overall cleaner startup/shutdown handling in case of failures.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@155 ce417995-dfc9-0310-95a0-acdaff106893
* many document changes, validated most xml files,
  fixed ps/pdf image problem.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@154 ce417995-dfc9-0310-95a0-acdaff106893
* compile fixes due to geometry changes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@151 ce417995-dfc9-0310-95a0-acdaff106893
* small doc updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@150 ce417995-dfc9-0310-95a0-acdaff106893
* generate ps
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@149 ce417995-dfc9-0310-95a0-acdaff106893
* doc updates, still bad namespace page in html due
  to long templates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@148 ce417995-dfc9-0310-95a0-acdaff106893
* doc updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@147 ce417995-dfc9-0310-95a0-acdaff106893
* Changed HB testcase
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@146 ce417995-dfc9-0310-95a0-acdaff106893
* documentation updates
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@145 ce417995-dfc9-0310-95a0-acdaff106893
* fixed some nameserving bugs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@144 ce417995-dfc9-0310-95a0-acdaff106893
* * Added NamesKernel Chapter
  * fixed some validation errors in xmldoc
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@143 ce417995-dfc9-0310-95a0-acdaff106893
* * First officially working NamesKernel.
  * Kernel.hpp is now replaced by DefaultControlKernel.hpp
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@142 ce417995-dfc9-0310-95a0-acdaff106893
* doc improvements
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@141 ce417995-dfc9-0310-95a0-acdaff106893
* * major documentation enhancements
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@140 ce417995-dfc9-0310-95a0-acdaff106893
* doxygen docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@139 ce417995-dfc9-0310-95a0-acdaff106893
* CHANGED NAMESPACE CBDeviceDriver to ORO_DeviceDriver
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@138 ce417995-dfc9-0310-95a0-acdaff106893
* * removed old SwitchHoming
  * started HW server
  * added doxygen docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@137 ce417995-dfc9-0310-95a0-acdaff106893
* doxygen docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@136 ce417995-dfc9-0310-95a0-acdaff106893
* Added main doxygen page
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@135 ce417995-dfc9-0310-95a0-acdaff106893
* crosslinks to manual
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@134 ce417995-dfc9-0310-95a0-acdaff106893
* Added documentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@133 ce417995-dfc9-0310-95a0-acdaff106893
* * fixed virtual overload warning
  * added doxygen mainpage
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@132 ce417995-dfc9-0310-95a0-acdaff106893
* Added Doxygen mainpages
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@131 ce417995-dfc9-0310-95a0-acdaff106893
* cleanup and added docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@130 ce417995-dfc9-0310-95a0-acdaff106893
* removed testfile
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@129 ce417995-dfc9-0310-95a0-acdaff106893
* test
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@128 ce417995-dfc9-0310-95a0-acdaff106893
* test
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@127 ce417995-dfc9-0310-95a0-acdaff106893
* tesr
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@126 ce417995-dfc9-0310-95a0-acdaff106893
* test commit
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@125 ce417995-dfc9-0310-95a0-acdaff106893
* test commit
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@124 ce417995-dfc9-0310-95a0-acdaff106893
* * fix for wrong rtai_config.h inclusion
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@123 ce417995-dfc9-0310-95a0-acdaff106893
* proc docs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@122 ce417995-dfc9-0310-95a0-acdaff106893
* doc added
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@121 ce417995-dfc9-0310-95a0-acdaff106893
* restructuring main doc file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@120 ce417995-dfc9-0310-95a0-acdaff106893
* Adapt to better and new API
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@119 ce417995-dfc9-0310-95a0-acdaff106893
* wrong header path
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@118 ce417995-dfc9-0310-95a0-acdaff106893
* namespace fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@117 ce417995-dfc9-0310-95a0-acdaff106893
* Also compile Distancesensor
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@116 ce417995-dfc9-0310-95a0-acdaff106893
* fix some header and macro stuff
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@115 ce417995-dfc9-0310-95a0-acdaff106893
* Uncommented "using namespace CAN"
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@114 ce417995-dfc9-0310-95a0-acdaff106893
* Changed axis to use EncoderInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@113 ce417995-dfc9-0310-95a0-acdaff106893
* Added the generic EncoderInterface
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@112 ce417995-dfc9-0310-95a0-acdaff106893
* fixed typo bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@111 ce417995-dfc9-0310-95a0-acdaff106893
* changes suggested by Herman
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@110 ce417995-dfc9-0310-95a0-acdaff106893
* Added close/connect methods to the Event API.
  Fixed some old null pointer bugs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@109 ce417995-dfc9-0310-95a0-acdaff106893
* last renaming errors removed (ie it compiles)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@108 ce417995-dfc9-0310-95a0-acdaff106893
* leftover renames of geometry in src directory
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@107 ce417995-dfc9-0310-95a0-acdaff106893
* renaming of geometry classes
  geometry* -> path*
  motionprofile* -> velocityprofile*
  orientation* ->rotational_interpolation*
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@106 ce417995-dfc9-0310-95a0-acdaff106893
* Renamed the files (not yet classes) to represent
  saner name choices of classes.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@105 ce417995-dfc9-0310-95a0-acdaff106893
* userfriendlyness bugfixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@104 ce417995-dfc9-0310-95a0-acdaff106893
* userfriendlyness bugfixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@103 ce417995-dfc9-0310-95a0-acdaff106893
* added lvd targets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@102 ce417995-dfc9-0310-95a0-acdaff106893
* fixed numerous typo  bugfixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@101 ce417995-dfc9-0310-95a0-acdaff106893
* callibration bugfix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@100 ce417995-dfc9-0310-95a0-acdaff106893
* extended lvd template
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@99 ce417995-dfc9-0310-95a0-acdaff106893
* doc+bugfixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@98 ce417995-dfc9-0310-95a0-acdaff106893
* added sync to canbus interface
  nodeguard bugfix
  din initialisation
  coupler initialisation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@97 ce417995-dfc9-0310-95a0-acdaff106893
* interrupt counting
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@96 ce417995-dfc9-0310-95a0-acdaff106893
* Added Beckhoff Specific encoder
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@95 ce417995-dfc9-0310-95a0-acdaff106893
* added setmax functions to traphalf
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@94 ce417995-dfc9-0310-95a0-acdaff106893
* Device Drivers fixes for LVD setup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@93 ce417995-dfc9-0310-95a0-acdaff106893
* cleaned up geometry dependencies
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@92 ce417995-dfc9-0310-95a0-acdaff106893
* added (temporary)  Makefiles for documentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@90 ce417995-dfc9-0310-95a0-acdaff106893
* fix CVS/SVN typo again
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@89 ce417995-dfc9-0310-95a0-acdaff106893
* fix typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@88 ce417995-dfc9-0310-95a0-acdaff106893
* added missing targets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@87 ce417995-dfc9-0310-95a0-acdaff106893
* Documentation cleanup.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@86 ce417995-dfc9-0310-95a0-acdaff106893
* brushing out old descriptions.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@85 ce417995-dfc9-0310-95a0-acdaff106893
* added revision number +  title change
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@84 ce417995-dfc9-0310-95a0-acdaff106893
* added PPstates picture
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@83 ce417995-dfc9-0310-95a0-acdaff106893
* dia files cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@82 ce417995-dfc9-0310-95a0-acdaff106893
* explained ORO_main a bit more
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@81 ce417995-dfc9-0310-95a0-acdaff106893
* * fixed namespace bug in MotionProperties
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@80 ce417995-dfc9-0310-95a0-acdaff106893
* Added documentation
  Compile fixes for Serial321
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@79 ce417995-dfc9-0310-95a0-acdaff106893
* small cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@78 ce417995-dfc9-0310-95a0-acdaff106893
* Compilation & Linking Bugfixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@77 ce417995-dfc9-0310-95a0-acdaff106893
* removed unneeded method
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@76 ce417995-dfc9-0310-95a0-acdaff106893
* KernelBaseExtension renamed to KernelBaseFunction
  Fixes to be compliant with the docs :-)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@75 ce417995-dfc9-0310-95a0-acdaff106893
* Compilation fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@74 ce417995-dfc9-0310-95a0-acdaff106893
* Ordering motioncontrol components
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@73 ce417995-dfc9-0310-95a0-acdaff106893
* Added componentconfigurator (was forgotten)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@72 ce417995-dfc9-0310-95a0-acdaff106893
* compile bugfixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@71 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes for invalid DocBook
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@70 ce417995-dfc9-0310-95a0-acdaff106893
* Prefix path is not used...
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@69 ce417995-dfc9-0310-95a0-acdaff106893
* Added an _easy\_ setup script :-)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@68 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes for std::
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@67 ce417995-dfc9-0310-95a0-acdaff106893
* document cleanup and restructuring
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@66 ce417995-dfc9-0310-95a0-acdaff106893
* Added the picture + some small restructuring
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@65 ce417995-dfc9-0310-95a0-acdaff106893
* First revision of the os documentation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@64 ce417995-dfc9-0310-95a0-acdaff106893
* initial copy of the orocos-os document from corelib
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@63 ce417995-dfc9-0310-95a0-acdaff106893
* added doc dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@62 ce417995-dfc9-0310-95a0-acdaff106893
* first isolated description of DI
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@61 ce417995-dfc9-0310-95a0-acdaff106893
* created common doc dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@60 ce417995-dfc9-0310-95a0-acdaff106893
* added doc dir
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@59 ce417995-dfc9-0310-95a0-acdaff106893
* Double dispatching explained
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@58 ce417995-dfc9-0310-95a0-acdaff106893
* Renamed to proper filename (corelib)
  added makefile
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@57 ce417995-dfc9-0310-95a0-acdaff106893
* moved from the base doc directory to here.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@56 ce417995-dfc9-0310-95a0-acdaff106893
* installation restructuring the sections
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@55 ce417995-dfc9-0310-95a0-acdaff106893
* cpF -> File not Format
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@54 ce417995-dfc9-0310-95a0-acdaff106893
* documentation restructuring
  splitting of overview to installation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@53 ce417995-dfc9-0310-95a0-acdaff106893
* fixed dep rules
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@52 ce417995-dfc9-0310-95a0-acdaff106893
* Feedback from Herman
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@51 ce417995-dfc9-0310-95a0-acdaff106893
* Fix for reference to bibliography
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@50 ce417995-dfc9-0310-95a0-acdaff106893
* Typo in parallelL
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@49 ce417995-dfc9-0310-95a0-acdaff106893
* ".cdl xml file" in context of properties should be CPF file
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@48 ce417995-dfc9-0310-95a0-acdaff106893
* cpf is an abbreviation, so uppercase
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@47 ce417995-dfc9-0310-95a0-acdaff106893
* CPF Component Property File, information added
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@46 ce417995-dfc9-0310-95a0-acdaff106893
* Renaming of last ".cpp" files to ".cxx"
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@45 ce417995-dfc9-0310-95a0-acdaff106893
* Removing generated files and old CVS dirs
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@44 ce417995-dfc9-0310-95a0-acdaff106893
* moved files to correct directories
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@43 ce417995-dfc9-0310-95a0-acdaff106893
* more philo and intro !
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@42 ce417995-dfc9-0310-95a0-acdaff106893
* * Added nameserver section
  * minor cleanups
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@41 ce417995-dfc9-0310-95a0-acdaff106893
* added select/load mechanism
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@40 ce417995-dfc9-0310-95a0-acdaff106893
* updated select/load mechanism
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@39 ce417995-dfc9-0310-95a0-acdaff106893
* kernel-component interaction scheme
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@38 ce417995-dfc9-0310-95a0-acdaff106893
* Added component life cycle description
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@37 ce417995-dfc9-0310-95a0-acdaff106893
* better kernel API concerning component life cycle
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@36 ce417995-dfc9-0310-95a0-acdaff106893
* Two helper tasks
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@35 ce417995-dfc9-0310-95a0-acdaff106893
* Stop thread before deleting it or deleting its data
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@34 ce417995-dfc9-0310-95a0-acdaff106893
* * many bugfixes and testing
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@33 ce417995-dfc9-0310-95a0-acdaff106893
* * bugfixes in lvd driver
  * API change to _U32 for user functions
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@32 ce417995-dfc9-0310-95a0-acdaff106893
* better build-environment buildup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@31 ce417995-dfc9-0310-95a0-acdaff106893
* small configurator fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@30 ce417995-dfc9-0310-95a0-acdaff106893
* Fixes to make use of new corelib functionality
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@29 ce417995-dfc9-0310-95a0-acdaff106893
* new EventInterrupt implementation (dummy for GNU/L)
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@28 ce417995-dfc9-0310-95a0-acdaff106893
* new EventInterrupt implementation
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@27 ce417995-dfc9-0310-95a0-acdaff106893
* EventInterrupt cleanups/rewriting for LXRT
  using rtai_usi
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@26 ce417995-dfc9-0310-95a0-acdaff106893
* code cleanup and moved CP header to cxx files
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@25 ce417995-dfc9-0310-95a0-acdaff106893
* Provided interface in common for Interrupt-based events
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@24 ce417995-dfc9-0310-95a0-acdaff106893
* CANOpenBus fixes
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@23 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed Configurator status bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@22 ce417995-dfc9-0310-95a0-acdaff106893
* added virtual destructors
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@21 ce417995-dfc9-0310-95a0-acdaff106893
* added lvd template
  added marshalling to default
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@20 ce417995-dfc9-0310-95a0-acdaff106893
* Fixed dynamic event creation semaphore leftover
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@19 ce417995-dfc9-0310-95a0-acdaff106893
* Added state package + comments
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@18 ce417995-dfc9-0310-95a0-acdaff106893
* Added Autostart feature of CP
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@17 ce417995-dfc9-0310-95a0-acdaff106893
* removed redundant include
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@16 ce417995-dfc9-0310-95a0-acdaff106893
* fixed RealTimeTask renaming
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@15 ce417995-dfc9-0310-95a0-acdaff106893
* * Added auto-thread-start feature
  * Fixed dynamic-registration bug
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@14 ce417995-dfc9-0310-95a0-acdaff106893
* include typo fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@13 ce417995-dfc9-0310-95a0-acdaff106893
* include bugfix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@12 ce417995-dfc9-0310-95a0-acdaff106893
* quick cleaning and update
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@11 ce417995-dfc9-0310-95a0-acdaff106893
* fixed revision number typo
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@10 ce417995-dfc9-0310-95a0-acdaff106893
* typo fix
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@9 ce417995-dfc9-0310-95a0-acdaff106893
* admin files + executable properties
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@8 ce417995-dfc9-0310-95a0-acdaff106893
* saner makefile + make dist targets
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@7 ce417995-dfc9-0310-95a0-acdaff106893
* forgot -f flag on rm
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@6 ce417995-dfc9-0310-95a0-acdaff106893
* saner db management, suitable for svn users and package users.
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@5 ce417995-dfc9-0310-95a0-acdaff106893
* further cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@4 ce417995-dfc9-0310-95a0-acdaff106893
* cleanup
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@3 ce417995-dfc9-0310-95a0-acdaff106893
* forgotten commits of old trunk
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@2 ce417995-dfc9-0310-95a0-acdaff106893
* Initial import of orocos-trunk
  git-svn-id: https://svn.mech.kuleuven.be/repos/orocos/orocos-trunk@1 ce417995-dfc9-0310-95a0-acdaff106893
* Contributors: Adolfo Rodriguez Tsouroukdissian, Adolfo Rodríguez Tsouroukdissian, Butch Slayer, Charles Lesire-Cabaniols, Daniel Kühn, Eli Reekmans, Fabian Wiesel, Janosch Machowinski, Jean Sreng, Johannes Meyer, Jon B, Jonathan Bohren, Klaas Gadeyne, Markus Klotzbuecher, Mathieu Gautier, Matthias Goldhoorn, Paul Chavent, Peter, Peter Nemeth, Peter Soetens, Philippe Hamelin, Pierre Willenbrock, Piotr Trojanek, Ruben Smits, S Roderick, Simon Pelletier-Thibault, Stephen Roderick, Steven Bellens, Steven Kauffmann, Sylvain Joyeux, Theo Devries, Thomas Roehr, Uwe Kindler, Willy Lambert, ddevries, eaertbel, iMoby, jrutgeer, kgadeyne, kiwi.net@mac.com, m0117248, orocos@dpinol.com, pissaris, psoetens, ressac, rsmits, tdelaet, virtual, wmeeusse
