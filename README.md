<h1 align=center>
	<b>minishell</b>
</h1>

<h2 align=center>
	 <i>42cursus' project #8</i>
</h2>

<p align=center>
	The <b>minishell</b> project was done in collaboration with <a href="https://github.com/FaustoFaggion">Fausto Faggion</a>, a follow cadet at 42. Together, we aimed to create a program that emulates the default behaviour of a shell script command line prompt, executing binaries throught pipes and conditionals, dealing with environment variables and manipulating files through redirections and heredocs. This was the most complex project that we had to dwell upon so far, not only because of its code complexity, but more so bacause it is really hard to know when to stop: Minishell can be infinite, and is, by all means, always incomplete.

---
<div align=center>
<h2>
	Final score
</h2>
<img src=https://github.com/caroldaniel/caroldaniel-utils/blob/edfb245d0adad2ee2a22aba2e9318bc8a28ea937/minishell_grade.png alt="cado-car's 42Project Score"/>
<h4>Completed + Bonus</h4>
<img src=https://github.com/caroldaniel/caroldaniel-utils/blob/edfb245d0adad2ee2a22aba2e9318bc8a28ea937/minishellm.png alt="cado-car's 42Project Badge"/>
</div>

---

<h3 align=center>
Mandatory
</h3>

> Your shell should: 
> - Display a prompt when waiting for a new command. 
> - Have a working history. 
> - Search and launch the right executable (based on the PATH variable or using a relative or an absolute path). 
> - Not use more than one global variable. Think about it. You will have to explain its purpose. 
> - Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon). 
> - Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence. 
> - Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollarsign).
> - Implement redirections: 
> 	- < should redirect input. 
> 	- \> should redirect output. 
> 	- << should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history! 
> 	- \>> should redirect output in append mode. 
> - Implement pipes ( | character). The output of each command in the pipeline is connected to the input of the next command via a pipe. 
> - Handle environment variables ( $ followed by a sequence of characters) which should expand to their values. 
> - Handle $? which should expand to the exit status of the most recently executed foreground pipeline. 
> - Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash. 
> - Ininteractive mode: 
> 	- <b>ctrl-C</b> displays a new prompt on a new line. 
> 	- <b>ctrl-D</b> exits the shell. 
> 	- <b>ctrl-\ </b>does nothing. 
> - Your shell must implement the following builtins: 
> 	- <b>echo</b> with option -n 
> 	- <b>cd</b> with only a relative or absolute path 
> 	- <b>pwd</b> with no options 
> 	- <b>export</b> with no options 
> 	- <b>unset</b> with no options 
> 	- <b>env</b> with no options or arguments 
> 	- <b>exit</b> with no options

<h3 align=center>
Bonus
</h3>

> Your program has to implement: 
> - && and || with parenthesis for priorities.
> - Wildcards * should work for the current working directory.

---

<h2>
The project
</h2>

The main idea behind minishell is the ability to decipher what is being written on the prompt by the user, translating it into a structure of data that will be easily understandable by the computer, and therefore appropriately executed. 

The goal is to be as organized and throughful as possible. In order to develop a program that succeeds in this endeavor, we developed a general guideline for the program's workflow:

- As the minishell is initialized, so is the main structure that will centralize all the data that will be necessary for the program to run: exit codes, environ list, command and parser structs - all in one place;
- During the minishell's initialization, all environment variables of the parent's process will need to be stored and easily accessed. We used a hashtable to do the job;
- Then, we will need to open the terminal (in a infinite loop - don't sue!) in order to ask the user for a new line to be interpreted;
- In the loop, we must first change the input signals (ctrl-C, ctrl-D and ctrl-\\);
- Then, we create a prompt message (all personalized as we so wish) and open the terminal for the user's input;
- When finished by the user, the program will then proceed to throw the line to the parser function: Tokenize the line (break it into meaningful tokens), analyse it by lexemas, and the syntatically. The order of the words written must make sense, otherwise a syntax error shall appear, and a new line must be prompted;
- If everything seemes correct, then we must proceed to transform the tokens into command tables: break the tokens into command strutures, in which we will need to analyse what is command, what is redirection, etc;
- Expand all variables, tildes, quotes and wildcards. Make sure everything is working accordingly to the original shell;
- Once the command table is complete, we can finaly start the execution!
- Define the redirections (including prompting for the heredocs as they appear);
- Create the pipes when necessary;
- Execute the commands - by forking the process when necessary - some commands - especially those manipulating environment variables, shall be executed only in the parent process so the changes stick;
- Once it's done, a new line shall be prompted, and the program shall start its process all over again.

---
<h2>
Usage
</h2>

### Requirements
 

### Instructions

Clone this repository in your local computer:

```sh
$> git clone https://github.com/caroldaniel/42sp-cursus-minishell.git path/to/minishell
```

In your local repository, run `make`

```sh
$> make 
```

> `make` suports 6 flags:
> - `make install` makes sure your system has all the prerequisites for running the program
> - `make all` or simply `make` compiles fdf in its mandatory format
> - `make clean` deletes the `.o` files generated during compilation
> - `make fclean` deletes the `.o` and the `fdf` file generated
> - `make re` executes `fclean` and `all` in sequence, recompiling the program
> - `make leak` executes valgrind to check for any possible leaks and puts it into a log file

To run `minishell`, type:
```sh
./minishell
```
