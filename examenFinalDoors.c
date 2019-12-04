/****************************************************************************
*
*						FINAL BATTLE (EXAM 001)
*
*					Student name: Victor Sabariego
*                          Group: 1A
*
*****************************************************************************/

#include <stdio.h>		// TODO: Used for functions:
#include <stdlib.h>		// TODO: Used for functions:
#include <time.h>		// Used for function time()

void DrawTitle();
void DrawGargole();
void DrawCrazyRat();
void DrawSkeleton();
void DrawPlayerEnemyLife(int pLife, int eLife);

int main()
{
	// Game variables declaration
	//-----------------------------
	int playerLife = 50;
	int playerAttack;
	int playerAction;
	int playerEscape = 'x';
	int enemyLife = 0;
	int enemyType = -1;
	int enemyAttack;
	int totalGold = 0;
	int enemyGold;
	char startKey;
	
      
	// Basic game logic
	//-------------------
	// TODO: Init random seed based on current time
    srand(time(NULL));
    
	DrawTitle(); 	// Draw main title
	
	printf("You are lost in the woods, the most horrible creatures are chasing you...\n");
	printf("Something is approaching, you can feel it, it's time to do your best!\n");
	
	printf("\nPress X to exit or any other key to START: ");
	scanf("%c", &startKey);
	getchar();
	
	// TODO: Check if X or any other key has been pressed
	
	// NOTE: At t his point starts a game LOOP
    
    while (startKey != 'x')
    {       

	playerEscape = 0;			// Initialize playerEscape for the loop
	
	// Get a random enemy
	enemyType = rand() % 3;		// Get a random integer number between 0 and 2
	
	// TODO: Depending on enemyType, draw the right enemy, display the right message and set enemyLife 
    // enemyType = 0  -->  enemyLife = 20 + rand() % 10;
	// enemyType = 1  -->  enemyLife = 40 + rand() % 20;
	// enemyType = 2  -->  enemyLife = 80 + rand() % 40;
    if (enemyType == 0){
        DrawGargole();
        enemyLife = 20 + rand() % 10;
    }
    if (enemyType == 1){
        DrawCrazyRat();
        enemyLife = 40 + rand() % 20;
    }
    if (enemyType == 2){
        DrawSkeleton();
        enemyLife = 80 + rand() % 40;
    }

    // EXTRA: Balance enemies life
	
	DrawPlayerEnemyLife(playerLife, enemyLife);
	
	printf("\n\nPress ENTER to START BATTLE! \n");
	getchar();
	
	// NOTE: At this point starts a battle LOOP
        while (enemyLife > 0 && playerLife > 0 && playerEscape == 0){
            // TODO: Show available actions (attack, defend, escape) and read player selection 
            printf("Actions =\n");
            printf("1-Attack\n");
            printf("2-Defend\n");
            printf("3-Escape\n");
            scanf("%d", &playerAction);
            getchar();
            
           
            // EXTRA: Balance player attack power and enemies attack power
            playerAttack = rand() % 14 + 6;		// Player attack power is always between 6 and 20
            
            // TODO: Set enemy attack power (enemyAttack), it depends on enemyType
            // enemyType = 0  -->  value between 2 and 10
            // enemyType = 1  -->  value between 4 and 16
            // enemyType = 2  -->  value between 6 and 22
            if(enemyType == 0)
            {
                enemyAttack = rand () % 8 + 2;
            }
            else if(enemyType == 1)
            {
                enemyAttack = rand () % 12 + 4;
            } 
            else if(enemyType == 2)
            {
                enemyAttack = rand () % 16 + 6;
            }
            
            // Depending on choosen action, different things happen
            //------------------------------------------------------
            if (playerAction == 1)			// Attack
            {
                // TODO: Implement attack logic
                
                // playerAttack and enemyAttack are compared, 
                // if playerAttack is greater (or equal), enemy receives de full hit (all playerAttack damage) and player only receives enemyAttack/2 damage.
                if(playerAttack >= enemyAttack)
                {
                    enemyLife -= playerAttack;
                    playerLife -= enemyAttack/2;
                }
                // if enemyAttack is greater, player receives de full hit and enemy only receives playerAttack/2 damage.
                if(enemyAttack > playerAttack)
                {
                    playerLife -= enemyAttack;
                    enemyLife -= playerAttack/2;
                }
                
            }
            else if (playerAction == 2)		// Defend
            {
                // TODO: Implement defend logic
                playerLife -= enemyAttack/3;
                playerLife += 6;
                // enemy receives no damage, player receives enemyAttack/3 damage but also recovers +6 life points

            }
            else if (playerAction == 3)		// Escape
            {
                // TODO: Implement escape logic
                
                // player has a 50% probability to escape:
                playerEscape = rand() % 2;
            
                // if escape, player receives no damage, if not, player receives full damage (show messages)
                if(playerEscape == 1)
                {
                    printf("ESCAPASTE!");
                    
                }
                if(playerEscape == 2) 
                {
                    printf("No pudiste escapar");
                    playerLife -= enemyAttack;
                }
            }
            else
            {
                // EXTRA: Any idea?
                printf("try again");
            }
            
            // Print on screen player/enemy attacks (only if player didn't escape)
            if (playerEscape == 0)
            {
                // TODO: Print player/enemy attack power
                printf("\nPlayer Attack = %i", playerAttack);
                printf("\nEnemy Attack = %i", enemyAttack);
                
                DrawPlayerEnemyLife(playerLife, enemyLife);
                
                printf("\n\nPress ENTER to CONTINUE! \n");
                getchar();
            }
            
            // Check player/enemy life to see if player died or enemy died
            if (playerLife <= 0)
            {
                printf("\nOuch! You died... YOU DIED!!!\n");
                
                printf("\nGAME OVER...\n");
            }
            else if (enemyLife <= 0)
            {
                printf("GREAT! You beat the monster... YOU BEAT THE MONSTER!!!\n");
                
                printf("\nCONGRATULATIONS...\n");
            
                enemyGold = 100 + enemyType * 200 + rand() % 100;
                printf("\nMonster drop a bag with money... You get +%i of Gold!\n", enemyGold);
                
                int lifePotion = rand() % 30 + 10;
                
                printf("Monster also drop a life potion... You get +%i of Life\n", lifePotion);
            
                totalGold += enemyGold;
                playerLife += lifePotion;
            }
        }
	// TODO: At this point, if player or enemy are not dead and player didn't escape, return to battle LOOP...

	printf("\nPress X to exit or any other key to fight another ENEMY: ");
	scanf("%c", &startKey);
	getchar();
	
	// NOTE: At this point, if X is pressed finish, if not, get a new FIGHT!
	
	printf("\nPLAYER TOTAL GOLD: %i\n", totalGold);

	printf("\nGAME OVER");
	getchar();

	// EXTRA: Add some clear-screen and some colors
    system("cls");
	
	return 0;
    }
}

void DrawTitle()
{
	printf("\n");
	printf("            787288778   42    87     87     882      20               \n");
	printf("          78887 78887 7885  2887    887   7228887  7888               \n");
	printf("           280         882   8807   887  88   788   480               \n");
	printf("           788722      482   88  97 887  88   588   784               \n");
	printf("           788  7      487   887  75887  88 77788   289               \n");
	printf("           788         082   887    887  882   88   784               \n");
	printf("           7884        8887  8887   888  881  7885  488  797          \n");
	printf("            77         77    77     77   77    77   727227            \n");
	printf("     784887      484     752820770   774078 97   8        477888 82   \n");
	printf("   7888 78887  7228887 707 28 7888 25  80 7887 488      2888  4888    \n");
	printf("    288   12  88    88     88      7  289      788       88           \n");
	printf("    788 780   88   288     88         784       88       884727       \n");
	printf("    788  4887 88777788     88         284       88       887          \n");
	printf("    788   784 885   88     88   72    284   77  88       88           \n");
	printf("   7888   45  880   888    888729     7888742   887 725  0884 7787    \n");
	printf("     77215    72    27      722         712     222557    722155      \n");
	printf("\n");		
}

void DrawGargole()
{
	printf("\n");
	printf("                 .;                    ;,.                  \n");
	printf("               ##-,.xX              =x-.=+#,                \n");
	printf("                  =#X -=           x ,XX  .                 \n");
	printf("         =-===       X- +X-;--;,+x, #       -===-           \n");
	printf("      =X-      ##    #X  .      .  .#    =#=      #X        \n");
	printf("     =  .= -+,   ,; x  +- -X; +x  +- ;= +    += .=   +      \n");
	printf("   #+ ++-=.#x .#;  -  #; * .###  * #-  ,  X+ -#=.=-X. #x    \n");
	printf("   #=X#+  -#  x-##  .xX-   +#+#    #x=  =#+=- +x   ##+x#    \n");
	printf("       #X;X  #x  Xx  .-=++x    =x+x=-   #, .#+ -x;#,        \n");
	printf("        ,#+ xx   ;   ###++=    -=+###-  -    #. ##          \n");
	printf("         Xx++X#x x#  ###+  x###   ###, -#.,X#+++X           \n");
	printf("                ###x =###.####X#--###  ###;                 \n");
	printf("                   #- .X###;+X;+###=  X=                    \n");
	printf("               x+   #+  ;###xxX##+   #.  -+                 \n");
	printf("              #  -= +,+x   -+++   -X;=- x  ##               \n");
	printf("               ##  . #  ##x    -X#+ +- . =#,                \n");
	printf("                 #x  #     #+=#=    ##  #X                  \n");
	printf("                  +##      ;#;+      +##                    \n");
	printf("                             X;-X          ++++xxxXx        \n");
	printf("                              ,# .xx    xX  ##X,    #-      \n");
	printf("                                x#+ +XX= =#+   +X   #=      \n");
	printf("                                   Xxx+xX        ###        \n");
	printf("\n");
}

void DrawCrazyRat()
{
	printf("\n");
	printf("                x+++x  ++++  +x==x.                         \n");
	printf("  =#. #X      +#  x+;+x;...+x-=X. ##      x#. ##            \n");
	printf("  X# +X #=    ##  ,#,         #-  x#     # +x x#    -;;;    \n");
	printf("  =#; .=X#=     +-=;          ,=-=,    ,X#+,.-+= =x+.;###,  \n");
	printf(" .++#=-#, ;X-.   # XX=+;  ,==+# #,  .,X=  #=-; .=  ;#x;,=   \n");
	printf("     ###x.  ;+x+## *  =+;;++  * +#+x+-   +##= =#  =#+       \n");
	printf("         #x     -#x ,=,    .=; +#=     =#,   =, =#X         \n");
	printf("          =#;=    =X+,      .+X+    =;#X   ;x   =#          \n");
	printf("           ##-     ,=##x=;x##=-     ,##    #=  +#           \n");
	printf("            #-    +=;=##,###---x.   .#    #   ##            \n");
	printf("            #=  ;X  =+=.+#-;+=  x-  -#   #,  ;#+            \n");
	printf("           #,     =X.         xx      #x,+  ,#x             \n");
	printf("           #,     -            ,     .##   ;#+              \n");
	printf("         ,#,.                          X+ ,##               \n");
	printf("         ,#  .                    .    +#x#.                \n");
	printf("         ;#+.,                    ., ;.x#-                  \n");
	printf("          =#,-;  .    ,     ,   , .=;x#=                    \n");
	printf("          =##X-=+. ;..,. , ,; . .,-X+##+                    \n");
	printf("        ## =-x##x-;x-,===,;x+.=;;+##X;= =#                  \n");
	printf("        =##  #-.##################;.#. x##                  \n");
	printf("          Xx#++x#. .=======-==-  #X++#xX.                   \n");
	printf("\n");	
}

void DrawSkeleton()
{
	printf("\n");
	printf("                      ;;,;;                       \n");
	printf("                    x+  #  +x                     \n");
	printf("                  #-    .=   -#                   \n");
	printf("                 -+      x.   +-                  \n");
	printf("                 #     ;   ,   #                  \n");
	printf("                 # .;       ,. #                  \n");
	printf("                 ## -.      - ##                  \n");
	printf("    ..           + x###   ###x +                  \n");
	printf("   #. ==        # +####   ####+ #                 \n");
	printf("   .+ . ---   -;# .x#X  -  X#x. #--               \n");
	printf("    +x,;.  --+ =#x.   .###.   .x#+ =,.            \n");
	printf("     ##,.-.  - xXXX X       X XXX+  X##XXX        \n");
	printf("    -+x#+.,-   x#x= #,# ###.# -x##  =xxX####=     \n");
	printf("  -#=..=##-.;;  ,#X =#######= X##   #++++xxX##-   \n");
	printf("  ##+-++=x#X,.-.  +# +=#-#-+ x##  +#+=++++xX###   \n");
	printf("    ##x+===X#x.,-   -       =+  ,##+==+++x##X     \n");
	printf("     .#x+=+=+##=.;-  ,#;   -+ ++#x+=++++x##.      \n");
	printf("       ##x====x#X;.-,  -X+--#xx+=+=+=x+###        \n");
	printf("      = .X#++===X#x.,-   X#x+++=+==++x##. =       \n");
	printf("    +;    ###x===+##=.,-   ##+===++x###    -==    \n");
	printf("  .++-  -,  -#X+++=x##-.-,  ;##+x+X#-  ;; .   #   \n");
	printf("  #  +  #     #X+++++##x,,-   +#XX#     #  #,.#   \n");
	printf("   +   =       #x+++++###x,,-   ##      #, X   #  \n");
	printf(" . #;,=# .     ,#xxxX#;  =#=.-,  ;       .-#   #  \n");
	printf(" ##xXX####      #==+X  -.+=+X,.-.  -       #.  #  \n");
	printf("  #+=+x##       #x-=- #x=XX x#+.,-  ;=-+-=-##x #  \n");
	printf("  #x==-+#       ##Xx#X.;.,.x####- -+++==-=,;####  \n");
	printf("  ##+X=+X##    #X====X#;,;#x-+X##X+=x##Xx##- +##  \n");
	printf("  #####xx###   #+-+XX==+++Xx+Xx=#+=#X+x===+#X X   \n");
	printf("    #######.  #XX+-+x+++++x++++XX##.X#X+x==X#;.#  \n");
	printf("      ----   ##+xXxx======+X#xX+=+## ;###=x#X-=-  \n");
	printf("              ##XxxXX#X#X#XX=++x##=    X####  +#  \n");
	printf("             ;#XXX#########X###XX#         +x##.  \n");
	printf("            .#xx+x#,        ##++=x#         --    \n");
	printf("            #=-=X#-          ##+xx##              \n");
	printf("            #-;=##            ##=--#              \n");
	printf("           ,##x+X##X#-        ##+-=#              \n");
	printf("          #;X####x;, #       ##xxx#-              \n");
	printf("          #         -X    XxX###xx#-+             \n");
	printf("          .=     +###     # .  -#+#X #            \n");
	printf("            ###XxxxX##    ;+         #            \n");
	printf("             #x=====x#X    ####X;--==             \n");
	printf("            -##Xx+==x##   ##x++xxX##              \n");
	printf("          .#==xXX+=###-  ##x=X###X##..            \n");
	printf("         ##-;--+x##xx    ##x=++==-,;x##           \n");
	printf("          #######         ###x===;,,  +#x         \n");
	printf("                           .;######xxx###         \n");
	printf("                                 ++++++           \n");
	printf("\n");	
}

// TODO: Implement function to draw player and enemy life 	

// EXTRA: Check that player/enemy life is not lower than 0	
void DrawPlayerEnemyLife(int pLife, int eLife)
{
	printf("\nPlayer Life = %i", pLife);
    printf("\nEnemy Life = %i", eLife);
}