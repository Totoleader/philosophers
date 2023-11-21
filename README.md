# philosophers
This project has for goal to solve the dining philosophers problem and to learn how multithreading works

Major problems for this project:
* Avoiding data races
* Performance

  Data race is problems that happens when multiple threads try to acces the same value at the same time.
  Example, one thread is changing the value of a variable and an other thread tries to read it at the same time,
  such an occurence will lead to a corruption of the data. To solve this problem I had to reduce the visibility
  between threads and only share variable that are necessery, and then protect the ones the do need to be shared
  with mutexes.

  Pushing the performance of the program was another big issue, after working on different version of the project
  I found that the best way to handle the death of philosophers was to create an other thread that watches if any
  philosopher is dead in a while loop. This way philosophers themselves don't have to worry about checking if they
  are still alive or not and for any **n** number of philosophers you will always have only **n + 1** philosophers.
  Another way to increase performance was to use system calls that tells threads to wait and give priority back to
  other threads while they do so.
  
<img src="rendu/philo-demo.gif">
