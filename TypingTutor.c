#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
char original_text[500];
char input_text[500];
int choice;
time_t start_time,end_time;
double time_taken;
double time_in_minutes;
float accuracy;
float WPM;
int total_chars;
int correct;
int wrong;
char list_of_paragraphs[][1000]={"In today’s fast-paced world, technology has become an inseparable part of our daily lives, influencing how we communicate, learn, and even think. From the moment we wake up to the sound of an alarm on our smartphones to the time we scroll through social media before going to bed, digital devices surround us constantly. ",

"While this advancement has made many tasks easier and more efficient, it has also introduced new challenges that require careful consideration. One of the most significant benefits of technology is its ability to connect people across the globe instantly. A message can travel thousands of miles in seconds, allowing individuals to stay in touch regardless of distance. This has strengthened relationships and enabled collaboration in ways that were once unimaginable. However, this constant connectivity can sometimes lead to overdependence, where people feel anxious without access to their devices.",

" Another important aspect is the role of technology in education. Online learning platforms, digital classrooms, and virtual resources have made knowledge more accessible than ever before. Students can now learn at their own pace, revisit lessons, and explore subjects beyond traditional textbooks. Despite these advantages, excessive screen time can affect concentration and reduce face-to-face interaction, which is equally important for personal development. Moreover, the rapid growth of technology has raised concerns about privacy and data security. With so much personal information being shared online, individuals must be cautious about how they use digital platforms.",

" Companies and developers also carry the responsibility of ensuring that user data is protected and not misused. In addition, automation and artificial intelligence are transforming industries by increasing productivity and reducing human effort in repetitive tasks. While this creates new opportunities, it also raises questions about job security and the need for new skills in the workforce. People must adapt and continuously learn to stay relevant in this evolving environment. Ultimately, technology is neither entirely good nor bad; it depends on how we choose to use it.",

" By maintaining a balance between digital and real-world interactions, we can enjoy the benefits while minimizing the drawbacks. Developing healthy habits, such as limiting screen time and prioritizing meaningful connections, can help individuals lead more fulfilling lives. As innovation continues to shape the future, it is essential to approach technology with awareness and responsibility, ensuring that it serves as a tool for progress rather than a source of distraction or harm."};

 char list_of_words[][50]={"cat","dog","sun","pen","book","computer","monitor","internet","program","language","synchronization","communication","productivity","architecture"};

char list_of_sentences[][200]={"The cat sits on the mat.","The quick brown fox jumps over the lazy dog.","I like to eat apples.","She has a red pen","We play in the park","The sun is very bright.","Typing every day improves your speed and accuracy.","Practice makes a person more confident and skilled.","Learning new skills takes time and patience","Computers help us complete tasks efficiently.","Technology is constantly evolving and shaping our daily lives.","Consistent practice can significantly improve typing speed and reduce errors.",
"Understanding programming concepts requires logic, patience, and dedication.","Artificial intelligence is transforming industries across the world.","Maintaining focus while typing helps in achieving better accuracy and performance."};

void load_text()
{
int index;
	if(choice==1)
	{
		int n=sizeof(list_of_words)/sizeof(list_of_words[0]);
		index=rand()%n;
		strcpy(original_text,list_of_words[index]);
		
	}
	else if(choice==2)
	{
		 int n = sizeof(list_of_sentences) / sizeof(list_of_sentences[0]);
		index=rand()%n;
		strcpy(original_text,list_of_sentences[index]);
	}
	else if(choice==3)
	{
		int n = sizeof(list_of_paragraphs) / sizeof(list_of_paragraphs[0]);
		index=rand()%n;
		strcpy(original_text,list_of_paragraphs[index]);
		
	}

}
void display_text(){
	
	printf("%s\n",original_text);
}
void startTimer() {
    start_time = time(NULL);
}
void stop_timer() {
    end_time = time(NULL);
}
void get_user_text(){
	getchar();
	printf("Start typing:\n");
	  startTimer();  
        fgets(input_text, sizeof(input_text), stdin);  
	 stop_timer();  
        input_text[strcspn(input_text, "\n")] = '\0';
    }

   

double getTimeTaken() {
    return difftime(end_time,start_time) ;
}

void compare_text()
{
        correct=0;
        wrong=0;
	int i=0;
	while((original_text[i]!='\0') ||(input_text[i]!='\0'))
	{
		if(original_text[i]==input_text[i])
			correct++;
		else
			wrong++;
		i++;
	}
}

void calculate_results(){

 total_chars = correct + wrong;
if (total_chars == 0) total_chars = 1;
 accuracy=((float)correct/total_chars)*100;
 time_taken= getTimeTaken();
 time_in_minutes=time_taken/60.0;
if (time_in_minutes == 0) time_in_minutes = 0.01;
 int word_typed=total_chars/5;
  WPM=word_typed/time_in_minutes;
}
void display_results(){
printf("Time Taken: %.2f seconds\n",time_taken);
printf("Total characters: %d\n",total_chars);
printf("Correct characters :%d\n",correct);
printf("Mistakes : %d\n",wrong);
printf("Accuracy : %.2f%%\n",accuracy);
printf("Typing speed(WPM): %.2f\n",WPM);	
}

int main()
{
srand(time(0));
char ch;
do{
printf("==============================================\n");
printf("---------- WELCOME TO TYPING TUTOR -----------\n");
printf("==============================================\n");
printf("========== TYPING TUTOR ==========\n");
printf("Rules:\n");
printf("\n");
printf("1. A sentence will be displayed on the screen.\n");
printf("2. Type the sentence exactly as shown.\n");
printf("3. Press ENTER after completing the sentence.\n");
printf("4. Your typing time will start when text is displayed.\n");
printf("5. Your typing time will stop when you press ENTER.\n");
printf("\n");
printf("6. Accuracy is based on:\n");
printf(" \t\tCorrect characters typed\n");
 printf("\t\t-Wrong characters will count as errors\n\n");
printf("7. Speed is calculated in WPM (Words Per Minute):\n");
printf("\t\t - 1 word = 5 characters\n\n");

printf("8. Do not use backspace excessively (optional rule if you want).\n");
printf("9. Extra or missing characters will reduce accuracy.\n");
printf("10. Try to type as fast and accurately as possible.\n\n");
printf("----------------------------------\n");
printf("Press ENTER to start...\n");
printf("Enter the mode of tutor:\n");
printf("1.Easy\n2.Medium\n3.Hard\n");
scanf("%d",&choice);
load_text();
display_text();
get_user_text();
compare_text();
calculate_results();
display_results();
printf("\nDo you want ot play again?(y/n): ");
scanf(" %c", &ch);
}while(ch=='y'||ch=='Y');
printf("Thank you for using typing tutor\n");

return 0;
}