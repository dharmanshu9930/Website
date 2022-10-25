def isVowel(ch):
	return (ch == 'a' or ch == 'e' or
			ch == 'i' or ch == 'o' or
def calcDiff(str):
	str = str.lower()
	count_vowels = 0
	count_conso = 0
	consec_conso = 0
	hard_words = 0
	easy_words = 0
	for i in range(0, len(str)):
		
		if(str[i]!= " " and isVowel(str[i])):
			
			count_vowels += 1
			consec_conso = 0
			

		elif(str[i] != " "):
			count_conso += 1
			consec_conso += 1


		if(consec_conso == 4):
			hrad_words += 1


			while(i < len(str) and str[i] != " "):
				i += 1
				

			count_conso = 0
			count_vowels = 0
			consec_conso = 0
		elif(i < len(str) and (str[i] == ' ' or
						i == len(str) - 1)):
							

			if(count_conso > count_vowels):
				hard_words += 1
			else:
				easy_words += 1


			count_conso = 0
			count_vowels = 0
			consec_conso = 0
			

	return (5 * hard_words + 3 * easy_words)

if __name__=="__main__":
	str = "I am a geek"
	str2 = "We are geeks"
	print(calcDiff(str))
	print(calcDiff(str2))


