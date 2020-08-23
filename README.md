# Comand-Line-Interpreter

For	this project,	we	implement	a	program	which	will	execute	a	given	
command(s)	as	command	line	arguments	to	the	program.	is	supports	
input,	output	and	error	redirection	and	pipes.	However,	instead	of	using	the	
symbols	used	by	the	shell,	it	will	use	the	following	symbols:
LT for <
GT for >
GTGT for >>
GTAMP for >&
PIPE for |

Some	examples	are	given	below (the	corresponding	shell	command	is	given	first,	
followed	by	the	project	3	command	which	gives the	same	result):<br />
Shell	Command:	 $	ls <br />
Project	3: $	./proj3	silent	ls<br />
Shell	Command: $	ls	-al<br />
Project	3: $./proj3	silent	ls	–al<br />
Shell	Command: $	ls	>	out<br />
Project	3: $./proj3	silent	ls	GT	out<br />
Shell	Command: $	ls	>>	out<br />
Project	3: $./proj3	silent	ls	GTGT	out<br />
Shell	Command: $	wc	<	input	>	output<br />
Project	3: $./proj3	silent	wc	LT	input	GT	out<br />
Shell Command: $	ls	>&	out<br />
Project	3: $./proj3	silent	ls	GTAMP	out<br />
Shell	Command: $	ls	|	wc<br />
Project	3: $./proj3	silent	ls	PIPE	wc<br />
Shell	Command: $	ls	|	wc	|	wc	>	out<br />
Project	3: $./proj3	silent	ls	PIPE	wc	PIPE	wc	GT	out	<br />

A	few	test	runs :

$		./proj3	silent	ls<br />
makefile		out		proj3		proj3.c		proj3.o<br />
Command(s)	execution	complete.<br />
$	./proj3	silent	ls	PIPE	wc<br />
					5							5						35<br />
Command(s)	execution	complete.<br />
$	./proj3	verbose	ls	PIPE	wc<br />
					5							5						35<br />
ls								:	23533<br />
wc								:	23534<br />
Command(s)	execution	complete.

![](screenshots/1.png)
![](screenshots/2.png)
![](screenshots/3.png)
![](screenshots/4.png)
![](screenshots/5.png)
![](screenshots/6.png)
![](screenshots/7.png)
