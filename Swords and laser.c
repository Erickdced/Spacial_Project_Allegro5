#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

//Character type declaration
struct player
{
    int xlog[8];
    int ylog[8];
    int hp[5];
    int visdir[4];
    int menu[4];
    int whb[4];
    int hb[4];
    int anima[3];
    int atack[3];
    int midx;
    int midy;
    int money;
    int potion; 
    int direct;
};

struct player player;

struct enemy
{
    int hp[5];
    int whb[4];
    int hb[4];

}

struct enemy enemy;
struct enemy boss;

struct character
{
    int hb[4];
} 
struct character npc1;

void playerValues () //Player Values
{
	player.hb[2] = player.hb[0] + 32; //Player x2 acctualization
	player.hb[3] = player.hb[1] + 32; //Player y2 actualization
	player.hp[1] = player.hb[0];	  //lifebar x1 & lifebox x1 
	player.hp[2] = player.hb[1] - 8;  //lifebar y1 & lifebox y1
	player.hp[3] = player.hp[1] + 32; //lifebox x2
	player.hp[4] = player.hp[2] + 4;  //lifebox y2 & lifebar y2
	player.midx = (player.hb[0] + player.hb[2]) / 2;
	player.midy = (player.hb[1] + player.hb[3]) / 2;
	
	
	//Weapon direction
	if(player.direc == 0) // key s, Down direction
	{
		player.whb[0] = player.hb[0] + 14;	//x1
		player.whb[2] = player.hb[0] + 18;	//x2
		player.whb[1] = player.hb[3] + 8;	//y1
		player.whb[3] = player.hb[3];		//y2
    }
    if(player.direc == 1) // key a, Right direction
    {
		player.whb[0] = player.hb[0] - 8;	//x1
		player.whb[2] = player.hb[0];   	//x2
		player.whb[1] = player.hb[1] + 14; 	//y1
		player.whb[3] = player.hb[1] + 18;	//y2
	}
	if(player.direc == 2) // key d, Left direction
	{
		player.whb[0] = player.hb[2] + 8;	//x1
		player.whb[2] = player.hb[2];   	//z2
		player.whb[1] = player.hb[1] + 14; 	//y1
		player.whb[3] = player.hb[1] + 18;	//y2
	}
	if(player.direc == 3) // key w, Up direction
	{
		player.whb[0] = player.hb[0] + 14;	//x1
		player.whb[2] = player.hb[0] + 18;	//x2
		player.whb[1] = player.hb[1] - 8;	//y1
		player.whb[3] = player.hb[1];		//y2
	}	
}

void enemyValues () //Enemy Values
{
	enemy.hb[2] = enemy.hb[0] + 32; //x2 actualization
	enemy.hb[3] = enemy.hb[1] + 32; //y2 actualization
	enemy.hp[1] = enemy.hb[0];		//enemy lifebar & lifebox x1
	enemy.hp[2] = enemy.hb[1] - 8;	//enemy lifebar & lifebox y1
	enemy.hp[3] = enemy.hp[1] + 32;	//enemy lifebox x2
	enemy.hp[4] = enemy.hp[2] + 4;  //enemy lifebar & lifebox y2
	//Weapon direction
	if(enemy.direc == 0) //Down follow
	{
		enemy.whb[0] = enemy.hb[0] + 14;	//x1
		enemy.whb[2] = enemy.hb[0] + 18;	//x2
		enemy.whb[1] = enemy.hb[3] + 8;		//y1
		enemy.whb[3] = enemy.hb[3];			//y2
    }
    if(enemy.direc == 1) //Right follow
    {
		enemy.whb[0] = enemy.hb[0] - 8;		//x1
		enemy.whb[2] = enemy.hb[0];   		//x2
		enemy.whb[1] = enemy.hb[1] + 14; 	//y1
		enemy.whb[3] = enemy.hb[1] + 18;	//y2
	}
	if(enemy.direc == 2) //Left follow
	{
		enemy.whb[0] = enemy.hb[2] + 8;		//x1
		enemy.whb[2] = enemy.hb[2];   		//z2
		enemy.whb[1] = enemy.hb[1] + 14; 	//y1
		enemy.whb[3] = enemy.hb[1] + 18;	//y2
	}
	if(enemy.direc == 3) //Up follow
	{
		enemy.whb[0] = enemy.hb[0] + 14;	//x1
		enemy.whb[2] = enemy.hb[0] + 18;	//x2
		enemy.whb[1] = enemy.hb[1] - 8;		//y1
		enemy.whb[3] = enemy.hb[1];			//y2
	}		
}

void bossValues () //Boss actualization
{
	boss.hb[2] = boss.hb[0] + 64; 	//x2 actualization
	boss.hb[3] = boss.hb[1] + 64; 	//y2 actualization
	boss.hp[1] = boss.hb[0];		//enemy lifebar & lifebox x1
	boss.hp[2] = boss.hb[1] - 8;	//enemy lifebar & lifebox y1
	boss.hp[3] = boss.hp[1] + 64;	//enemy lifebox x2
	boss.hp[4] = boss.hp[2] + 4; 	//enemy lifebar & lifebox y2
	//weapon direction
	if(boss.direc == 0) //down follow
	{
		boss.whb[0] = boss.hb[0] + 28;	//x1
		boss.whb[2] = boss.hb[0] + 36;	//x2
		boss.whb[1] = boss.hb[3] + 16;	//y1
		boss.whb[3] = boss.hb[3];		//y2
    }
    if(boss.direc == 1) //right follow
    {
		boss.whb[0] = boss.hb[0] - 16;	//x1
		boss.whb[2] = boss.hb[0];   	//x2
		boss.whb[1] = boss.hb[1] + 28; 	//y1
		boss.whb[3] = boss.hb[1] + 36;	//y2
	}
	if(boss.direc == 2) //left follow
	{
		boss.whb[0] = boss.hb[2] + 16;	//x1
		boss.whb[2] = boss.hb[2];   	//z2
		boss.whb[1] = boss.hb[1] + 28; 	//y1
		boss.whb[3] = boss.hb[1] + 36;	//y2
	}
	if(boss.direc == 3) //up follow
	{
		boss.whb[0] = boss.hb[0] + 28;	//x1
		boss.whb[2] = boss.hb[0] + 36;	//x2
		boss.whb[1] = boss.hb[1] - 16;	//y1
		boss.whb[3] = boss.hb[1];		//y2
	}		
}

void npcValues() //npc actualization
{
	npc1.hb[2] = npc1.hb[0] + 32; //x2
	npc1.hb[3] = npc1.hb[1] + 32; //y2
}

