#!/bin/bash

################################# Lab#01 #############################

########################### Task#01 #################
########## Task1.1 ########
echo "Hello , Word!"
########### Task#1.2 ######
echo "Enter username"
read name
echo "Assala o alikum $name how are you?"

############ Task#1.3 ######
echo "Enter 2 numbers :"
num1=$1
num2=$2
echo "Sum of 2 numbers is : $((num1+num2))"
################################### TASK#02 #########################
######### task#2.1 #########
echo "Enter a number to whome we want to check either even or not"
read num
if (( $num%2==0 ));then
	echo "Number is even"
else
	echo "Number is odd"
fi



########## task#2.2 #########
num=$1
for i in 1 2 3 4 5 6 7 8 9 10
do
	echo "Multiples of $num are : $((num * i))"
done

############# task#2.3 #########
random_number=$((RANDOM %10+1))


guess=0
while [ $guess -ne $random_number ]
do      echo "Enter a guess "
	read guess
	if [ $guess -lt $random_number ]; then
		echo "Guess is less then random number"
	elif [ $guess -gt $random_number ]; then
		echo "Your guess is greater then the random number"
	else
		echo "Comngratulations! U guessed corect number"
	fi
done

########################################### TASK#3 ########################

###############3 Task#3.1 ##############

function fictorial() {
n=$1
if [ $n -eq 0 -o $n -eq 1 ];then
	echo "Fictorial of $n is : 1"
else
	result=1
	for((i=2;i<=n;i++))
do
	result=$((result*i))
done
	echo "Fictorial of $n is :$result"
fi

}
fictorial $1
#################### Task#3.2 #########



fruits=("Apple" "Banana" "Gava")
function fruit() {
echo "${fruits[@]}"
}
fruits+=("Mango")
fruit
################## Task#3.3 ###########

declare -A capitals

capitals["Pakistan"]="Islamabad"
capitals["India"]="Deli"
capitals["Japan"]="Tokyo"

function capital() { 

	read country
	
	if [[ -v capitals[$country] ]]; then
		echo "$country - ${capitals[$country]}"
	else
		echo "$country not exist in list"
	fi
}
capital



################################# TASK#4 ################################

####################### Task#4.1 ############
i=0
while IFS= read -r line;
do
	echo " processing :$i   $line"
	i=$((i+1))
done < "text.txt"

###############3 Task#4.2 #################

File="script.log"
read username
read action
timestamp=$(date "+%Y-%m-%d %H:%M:%S")
echo "$timestamp - $username  $action" >> $File
echo "Data successfully written in script.log file go and check it out"

count=0
while IFS= read -r line;
do
	username_field=$(echo "$line" | awk '{print $4}')
	echo $username_field
	count=$((count+1))
done < $File
echo "Toatal no of lines in Script.log file are :$count"

echo "Action count per user :"
awk '{count[$4]++} END {for (user in count) print user " : " count[user]}' "$File"

#################### Task#4.3 #############
SOURCE_DIRECTRY="/mnt/c/Users/JK Traders Hall Road/Desktop/LAB#01"
BACKUP_NAME="backup_$(date +%Y-%m-%d).tar.gz"
DESTINATION_DIRECTRY="/mnt/c/Users/JK Traders Hall Road/Documents/backup"

if [ -d "$SOURCE_DIRECTRY" ]; then
	tar -czvf "$DESTINATION_DIRECTRY/$BACKUP_NAME" "$SOURCE_DIRECTRY"
	echo "Backup created Successfully! $DESTINATION_DIRECTRY/$BACKUP_NAME"
else
	echo "ERROR! Directry '$SOURCE_DIRECTRY\' does not exist."
	exit 1
fi

#################### TASK#5.1 ##################
all: program

program: main.o functions.o
	gcc main.o functions.o -o program

main.o: main.c functions.h
	gcc -c main.c

functions.o: functions.c functions.h
	gcc -c functions.c

clean:
	rm -f *.o program


#################### Task#5.2 ##################33
################################ Task#5.2 #############################
CC=gcc
CFLAGS= -Wall -g

SRCS= main.c functions.c utils.c              ##can use SRCS=$(wildcard *.c) it will find all .c files automatically
OBJS= $(SRCS:.c=.o)
TARGET=program

.PHONY:all clean debug

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD ##Pattern Rule
-include $(OBJS:.o=.d)
debug: $(CFLAGS) += -O0 ##This tells the compiletr to not do the optimizations on code cuz this optimization make debuging hard.
debug: $(TARGET)
	@echo "Compiled $(TARGET) with debuging sysmbols"
clean:
	rm -f $(OBJS) $(TARGET) *.d

########################## TASK#5.3 ##################################
SCRIPTS_DIR=my_shell_scripts/scripts
TESTS_DIR=my_shell_scripts/tests
INSTALL_DIR=/mnt/c/Users/JK\ Traders\ Hall\ Road/Desktop/backup

check:
	@echo "Checking all scripts for syntax checking..."
	@for script in $(SCRIPTS_DIR)/*.sh ; do \
		echo "Checking $$script"; \
		bash -n $$script || exit 1; \
	done
	@echo "All Scripts passed the syntax check!"

test:
	@echo "Running tests..."
	@for test in $(TESTS_DIR)/*.sh ; do \
		echo "Running $$test"; \
		bash $$test || exit 1; \
	done
	@echo "All Tests passed!"

install:
	@echo "Installing Scripts to $(INSTALL_DIR)..."
	@for script in $(SCRIPTS_DIR)/*.sh ; do \
		cp $$script $(INSTALL_DIR); \
		chmod +x $(INSTALL_DIR)/$$(basename $$script); \
	done
	@echo "Installation complete!"

.PHONY: check test install

















