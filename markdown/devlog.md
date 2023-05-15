# Development Log

## References



## Defining Issue/Mission statement

Create an environment that will allow for faster and easier code development

### Issues

* Robot access
	* We don't have unlimited time to test solutions on the robot. When we are at meetings or have access to the robot, we want to maximize that time, and currently testing programs that can be easily simulated take up much of the time because of the difficult debugging process.
* Debugging/logging tools
	* Currently aren't able to "rerun" or simulate past runs of code. The V5 system doesn't allow any way to replay a run where a bug in the programming occurred and view the internal state of the program for more effective debugging.
	* Testing can't be visualized effectively after testing. There is no solution within the V5 ecosystem that provides an elegant solution to view robot program state, input values, or output values in the V5 ecosystem currently. 
	* Live debugging is impractical in current V5 ecosystem. The V5 controller doesn't support high bandwidth, or low latency wirelessly. This limits the practicality of using the controller to debug because of the lack of volume and delay in the values coming from the V5 brain
* Competition matches
	* Quickly debugging robot code at competitions is difficult given the time constraints between matches (Often less than 30 minutes)
	* Errors that only show up during matches can be hard to debug without proper hardware, and having access to this hardware and time during a competition is often impossible and a simulator can replicate issues and make problem solving easier

### Define

We concluded that the most difficult issue in the VEX ecosystem is data logging/replay, and lack of adequate simulation. By creating a tool that would allow for simulation of possible robot hardware, and the ability to replay data from the V5 brain in such a simulator debugging code can be more effective because of decreased robot time requirements. To aid development of code when the robot is driving a live dashboard that could show the internal robot and sensor/output states would increase the effectiveness of debugging time on the robot. 

### Goals

* Be able to simulate robot subsystems, such as drivetrains and lifts in a basic simulator
* Be able to view live data from the robot in a user friendly way
* Be able to record, graph, and replay data from previous robot runs and matches in a simulator

### Ideate

#### Wirelessly relaying live data

To relay live data from the robot to another device we have a few options. Effectively transmitting data must have little to no noticeable lag, not require extensive use of robot resources, and have enough bandwidth to support live updating at 30-100 frames per second. 

* V5 Controller
	* Info:
		* Max bandwidth: 3.2 KB/s ([jpearman, VEX Forum](https://www.vexforum.com/t/suggestion-make-wireless-downloading-available-now/52155/7))
		* Max framerate: 50ms 
	* Pros:
	* Cons:
		* **Not enough bandwidth**
		* **Restricted Framerate**
		* Might impact user controllability
			* Sending more data through the controller imposes extra overhead for user input and could cause lag

#### Recording	



#### Simulating and replaying

### Choosing a graphics library



#### Requirements



#### Live debugging