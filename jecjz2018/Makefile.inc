APPL_COBJS += balancer.o balancer_param.o

APPL_CXXOBJS += Driver.o Runner.o ControlManager.o InstrumentPanel.o BalancerCpp.o MotorControl.o TailControl.o PID.o Color.o StartSwitch.o RunningDistance.o SonarDistance.o RunningTime.o
SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif
