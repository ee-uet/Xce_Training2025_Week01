SCRIPTS = script1.sh script2.sh script3.sh
check: script1_check script2_check script3_check

script1_check: script1.sh
		bash -n script1.sh

script2_check: script2.sh
		bash -n script2.sh

script3_check: script3.sh
		bash -n script3.sh

test: script1.sh script2.sh script3.sh
        	./script1.sh
        	./script2.sh
	        ./script3.sh
        	@echo "All scripts ran successfully"
