#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

bool imperfectPalidromeCheck(char word[],int len) {
    int flag=0,j=len-1;
    for (int i = 0; i < j; i++,j--)
    {
        if (word[i]==word[j])
        {
            continue;
        }
        else							// CHECKING THE FIRST AND LAST ELEMENT EACH TIME AND CALCULATING UNCOMMON PAIRS
        {
            flag++;
        }
    }
    
    if (flag==1)
    {
        return true;					// IF THERE IS ONLY ONE NON-COMMON PAIR, THEN IT IS IMPERFECT
    }
    else
	{
		return false;
	}      
}
bool superAnagramCheck(char arr[],int len,int secondWordPointer) {
	bool flag = false;
	for (int i = 0; i < secondWordPointer; i++)
	{
		flag = false;
		for (int j=secondWordPointer+1; j < len+2; j++)
		{
			if (arr[i]==arr[j])
			{											// COMPARING CHARACTERS IF ANYONE OF THEM USES DIFFERENT
				flag=true;
				break;	
			}
		}
		if (flag==false)
		{
			return false;								// RETURNS FALSE IF DIFFERENT CHARACTERS DETECTED
		}
	}
	if (flag==true)
	{
		char distinctArray[100];
		int distinct=1;  
		distinctArray[0]=arr[0];
		for (int i = 0; i < secondWordPointer ; i++)
		{
			for (int j = 0; j < distinct; j++)
			{
				if (arr[i]==distinctArray[j])		   // FINDING DISTINCT CHARACTERS FROM FIRST WORD
				{
					break;
				}
				else if(j==distinct-1 && arr[i]!=distinctArray[j])
				{
					distinctArray[distinct]=arr[i];		// CALCULATING SIZE OF DISTINCT 1 ARRAY
					distinct++;
				}
				
			}
			
		}
		
		char distinctArray2[100];
		int distinct2=1;  
		distinctArray2[0]=arr[secondWordPointer+1];
		for (int i = secondWordPointer+1; i < len ; i++)
		{
			for (int j = 0; j < distinct2; j++)
			{											// FINDING DISTINCT CHARACTERS FROM SECOND WORD
				if (arr[i]==distinctArray2[j])
				{
					break;
				}
				else if(j==distinct2-1 && arr[i]!=distinctArray2[j])
				{
					distinctArray2[distinct2]=arr[i];		// CALCULATING SIZE OF DISTINCT 2 ARRAY
					distinct2++;
				}
				
			}
			
		}
		int freq[100];
		int frequency;
		for (int i = 0; i < distinct; i++)
		{
			frequency=0;
			for (int j = 0; j < secondWordPointer; j++)
			{
				if (distinctArray[i]==arr[j])				// CALCULATING FREQUENCY OF 1st DISTINCT ARRAY
				{
					frequency++;
				}  
			}
			freq[i]=frequency;  
		}
		int freq2[100];
		int frequency2;
		for (int i = 0; i < distinct2; i++)
		{
			frequency2=0;
			for (int j = secondWordPointer+1; j < len; j++)
			{
				if (distinctArray2[i]==arr[j])				// CALCULATING FREQUENCY OF 2nd DISTINCT ARRAY
				{
					frequency2++;
				}  
			}
			freq2[i]=frequency2;  
		}
		int change = 0;
		for (int i = 0; i < distinct; i++)
		{
			unsigned int indvidual = freq[i]-freq2[i];		// CHECKING TOTAL FREQUENCY CHANGE
			change+=indvidual;
		}
		if (change<0)
		{
			change=change-(change*2);						// CONVERTING (IN ANY CASE) NEGATIVE ANSWER TO POSITIVE
		}
		
		if (change>2)
		{
			return false;									// IF GREATER THAN 2, THEN RETURNING FALSE OTHERWISE TRUE
		}
	}
	return true;
}
void inputFromFile() {
	string wordsInput; int len,secondWordPointer;   
    ifstream textFile("text.txt");
    if (textFile.is_open())
    {
        while ( getline (textFile,wordsInput))    // TAKING INPUT CONTINUSUALLY AND CHECKING FOR EACH INPUT 
        {
            len = wordsInput.length();
            char originalArray[100];
            for (int i = 0; i < len; i++)
            {
                if (wordsInput[i]=='\0')
                {
                    break;						  // CONVERTING STRING INTO A CHARACTER ARRAY 
                }
                originalArray[i]=wordsInput[i];
            }

			// SEPERATING OUT WORDS //

			for (secondWordPointer = 0; secondWordPointer < len; secondWordPointer++)
        	{
				if (originalArray[secondWordPointer]==' ')
				{
					break;						// CALCULATING POINTER WHICH IS AT START OF SECOND WORD
				}
        	}
			char word1[20],word2[20];
			int word1Size=secondWordPointer,word2Size=len-secondWordPointer-1;
			for (int i = 0; i < secondWordPointer; i++)
			{
				word1[i]=originalArray[i];
			}
			int j = secondWordPointer+1;		// STORING FIRST AND SECOND WORD IN DIFFERENT CHAR ARRAYS
			for (int i = 0; i < word2Size; i++)
			{
				word2[i]=originalArray[j];
				j++;
			}	
			if (imperfectPalidromeCheck(word1,word1Size))
			{
				cout<<"yes ";
			}
			else
			{									// CALLING FUNCTION AND CHECKING IMPERFECT PALINDROME FOR FIRST WORD
				cout<<"no ";
			}
			if (imperfectPalidromeCheck(word2,word2Size))
			{
				cout<<"yes ";
			}
			else								// CALLING FUNCTION AND CHECKING IMPERFECT PALINDROME FOR SECOND WORD
			{
				cout<<"no ";
			}
			


			if (superAnagramCheck(originalArray,len,secondWordPointer))
			{
				cout<<"yes";
			}
			else								// CALLING FUNCTION TO CHECK IF A STRING IS SUPER ANAGRAM OR NOT
			{
				cout<<"no";
			}
			cout<<endl;
        }
    }
	else
	{
		cout<<"Unable to open file!";
	}
    textFile.close();
}

int main() {
	inputFromFile();
}