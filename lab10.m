 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 % Assignment:  Lab 10
 % Lab Section: 11453
 % Description: This program inputs numbers from a testdata file then finds how may numbers can be divided down to a target integer
 % Programmers: Dante Sanaei dsanaei@purdue.edu
 %              Marcus Miller mill1867@purdue.edu
 %              Dylan Kerr kerr32@purdue.edu
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fh = fopen('testdata', 'r');			%imports the test data into a file handle of fh
if (fh ~= -1)
	target = fscanf(fh,'%d',1);			%finds the target value
	totalSum = 0;						%initalize the total sum to 0
	first = 1;							%initialize the first logical value to 1
	while(~feof(fh))					%runs through each number
		currentInt = fscanf(fh,'%d',1);		%current number that is being looped
	   	division = currentInt;				%initialize division
	    while(division > 0)					%loop to see if th division works
	      	division = floor(division) / 2;
		  	if (floor(division) == target && first)
				totalSum = totalSum + 1;	%updates sum
				fprintf('Values that reduce to the target [%d]:', target)
				fprintf(' %d ', currentInt)
				first = 0;				%updates first
		  	elseif(floor(division) == target && ~first)
    			fprintf(' %d ', currentInt)
				totalSum = totalSum + 1;
			end
	    end
	    if (currentInt == target && first)
	    	fprintf('Values that reduce to the target [%d]:', target)
	    	fprintf(' %d ', currentInt)
	    	totalSum = totalSum + 1;
	    	first = 0;
	    elseif(currentInt == target && ~first)
	    	fprintf(' %d ', currentInt)
	    	totalSum = totalSum + 1;
	    end

	end
	if (totalSum == 0)
		fprintf('None of the present data can be reduced to the target.\n')
	else
		fprintf('\nTotal number of values reduced to the target: %d\n', totalSum);
	end
else
  fprintf('test\n');
end
  

