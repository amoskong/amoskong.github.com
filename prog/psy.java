//本程序在命令行简单实现了漂三页（翻天花or三P），仅供学习研究！
//简单命令 :
//cat1 : 翻开第一家牌
//cat2 : 翻开第二家牌
//add1 $N : 第一家增加赌注
//add2 $N : 第二家增加赌注
//open : 启牌
//Copyright (C) kongjianjun@gmail.com

import java.util.Random; 
import java.io.*;
class cards{
	int[] num = new int[3];		// 2 3 4 5 6 7 8 9 10 J Q K A
	int[] kinds = new int[3];	// 1 红桃; 2 方块; 3 梅花; 4 黑桃
	int status;	// 1 小头; 2 对子; 3 青一色; 4 链子; 5 母豹子; 6 豹子
	int hidden;	// 1 隐藏; 0 显示
	int money;
	cards(){
		Random random = new Random();
		for (int i=0; i<3; i++){
			int k = random.nextInt();
			int j = Math.abs(k % 52)+1;
			num[i] = j%13 + 1;
			if(num[i] == 1)
				num[i] = 14;
			kinds[i] = (j-1)/13 + 1;
			//System.out.println("j:"+j+"\tnum[i]="+num[i]+"kinds[i]="+kinds[i]);
		}
		hidden = 1;
		money = 1;
	}
	public void print(){
		if(hidden == 1){
			System.out.println(" _________ \t _________ \t _________ ");
			System.out.println("|         |\t|         |\t|         |");
			System.out.println("|         |\t|         |\t|         |");
			System.out.println("|   隐藏  |\t|   隐藏  |\t|   隐藏  |");
			System.out.println("|         |\t|         |\t|         |");
			System.out.println("|_________|\t|_________|\t|_________|");
			return;
		}
		System.out.println(" _________ \t _________\t _________");
		for (int i=0; i<3; i++){
			switch (this.num[i]){
				case 10: System.out.print("|"+10+"       |");break;
				case 11: System.out.print("|"+'J'+"        |");break;
				case 12: System.out.print("|"+'Q'+"        |");break;
				case 13: System.out.print("|"+'K'+"        |");break;
				case 14: System.out.print("|"+'A'+"        |");break;
				default: System.out.print("|"+this.num[i]+"        |");
			}
			System.out.print("\t");
		}
		System.out.print("\n");
		System.out.println("|         |\t|         |\t|         |");
		for (int i=0; i<3; i++){
			switch (this.kinds[i]){
				case 1: System.out.print("|    "+'\u2665'+"    |");break;
				case 2: System.out.print("|    "+'\u2660'+"    |");break;
				case 3: System.out.print("|    "+'\u2663'+"    |");break;
				case 4: System.out.print("|    "+'\u2666'+"    |");
				default: ;
			}
			System.out.print("\t");
		}
		System.out.print("\n");
		System.out.println("|         |\t|         |\t|         |");
		for (int i=0; i<3; i++){
			switch (this.num[i]){
				case 10: System.out.print("|_______"+10+"|");break;
				case 11: System.out.print("|________"+'J'+"|");break;
				case 12: System.out.print("|________"+'Q'+"|");break;
				case 13: System.out.print("|________"+'K'+"|");break;
				case 14: System.out.print("|________"+'A'+"|");break;
				default: System.out.print("|________"+this.num[i]+"|");
			}
			System.out.print("\t");
		}
		System.out.print("\n");
	}
}

public class psy{
	public static int MAX(cards C){
		int max_n = ((C.num[0] >= C.num[1]) ? C.num[0] : C.num[1]);
		return ((max_n<=C.num[2]) ? C.num[2] : max_n);
	}
	public static int MIN(cards C){
		int min_n = ((C.num[0] <= C.num[1]) ? C.num[0] : C.num[1]);
		return ((min_n >= C.num[2]) ? C.num[2] : min_n);
	}
	public static int MAX2(cards C){
		return (C.num[0] + C.num[1] + C.num[0] - MAX(C) - MIN(C)) ;
	}
	public static void degree(cards C){
		if(C.num[0] == C.num[1] && C.num[1] == C.num[2]){
			C.status = 6;
			return;
		}
		int sum = C.num[0] + C.num[1] + C.num[2];
		if(C.kinds[0] == C.kinds[1] && C.kinds[1] == C.kinds[2] && 
				(sum%3==0 && 3*MAX(C)-sum==3 &&
				 (sum/3==C.num[0] || sum/3==C.num[1] || sum/3==C.num[2]))){
			C.status = 5;
			return;
		}
		if(sum%3==0 && 3*MAX(C)-sum==3 && 
				(sum/3==C.num[0] || sum/3==C.num[1] || sum/3==C.num[2])){
			C.status = 4;
			return;
		}
		if(C.kinds[0]==C.kinds[1] && C.kinds[1]==C.kinds[2]){
			C.status = 3;
			return;
		}
		if(C.num[0]==C.num[1] || C.num[1]==C.num[2] || C.num[0]==C.num[2]){
			C.status = 2;
			return;
		}
		C.status = 1;
	}

	public static void compare(cards C1, cards C2){
		if(C1.status < C2.status){
			System.out.print("第二家赢!");
			return;
		}
		if(C1.status > C2.status){
			System.out.print("第一家赢!");
			return;
		}
		if(MAX(C1) <= MAX(C2)){
			System.out.print("第二家赢!");
			return;
		}
		if(MAX2(C1) <= MAX2(C2)){
			System.out.print("第二家赢!");
			return;
		}
		if(MIN(C1) <= MIN(C2)){
			System.out.print("第二家赢!");
			return;
		}
		System.out.print("第一家赢!");
	}
	public static String printDegree(int status){
		switch (status){
			case 1: return "小头";
			case 2: return "对子";
			case 3: return "青一色";
			case 4: return "链子";
			case 5: return "母豹子";
			case 6: return "豹子";
			default:return null;
		}
	}

	public static void main(String args[]){
		cards C1 = new cards();
		cards C2 = new cards();
		int AddTo = 1;
		int AddM = 1;
		String Version=new String("Get help with command \"help\"");
		int open = 0;

		System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		System.out.println("漂三页游戏\tCopyright (C) kongjianjun@gmail.com");
		while(open == 0){
			try{
				System.out.println("\n");
				System.out.println("--第一家牌--"+"\t压注："+C1.money);
				C1.print();
				System.out.println("\n--第二家牌--"+"\t压注："+C2.money);
				C2.print();
				System.out.println("\n"+"提示信息："+Version);
				Version = "Get help with command \"help\"";
				System.out.println("\n\n");
				System.out.print("cmd $ ");
				BufferedReader Buf = new BufferedReader(new InputStreamReader(System.in));
				String In = Buf.readLine();
				if(In.startsWith("help")){
					Version = "本程序在命令行简单实现了漂三页（翻天花or三P），仅供学习研究！\n简单命令 :\ncat1 : 翻开第一家牌\ncat2 : 翻开第二家牌\nadd1 $N : 第一家增加赌注\nadd2 $N : 第二家增加赌注\nopen : 启牌";
					continue;
				}
				if (In.startsWith("cat1"))
					C1.hidden = 0;
				if (In.startsWith("cat2"))
					C2.hidden = 0;
				if (AddTo==1 && In.startsWith("add1")){
					String[] m = In.split("[\t ]+");
					int m1 = Integer.parseInt(m[1]);
					if ((C1.hidden<C2.hidden && m1<AddM*2) ||
							(C1.hidden==C2.hidden&&m1<AddM )){
						Version = "Fail to add1!";
						continue;
					}
					C1.money += m1;
					AddM = m1;
					AddTo = 2;
				} else if (AddTo == 2 && In.startsWith("add2")){
					String[] m = In.split("[\t ]+");
					int m1 = Integer.parseInt(m[1]);
					if ((C1.hidden > C2.hidden && m1<AddM*2) || 
							(C1.hidden==C2.hidden && m1<AddM )){
						Version = "Fail to add2!";
						continue;
					}
					C2.money += m1;
					AddM = m1;
					AddTo = 1;
				}else if (In.startsWith("add"))
					Version = "Fail to add!";

				if (In.equals("open"))
					open = 1;
			}
			catch(IOException e){
			}
		}
		degree(C1);
		degree(C2);
		System.out.println("第一家："+printDegree(C1.status)+"\t第二家："+printDegree(C2.status));
		if (AddTo == 1)
			compare(C1, C2);
		else
			compare(C2, C1);
		int GetMoney = C1.money + C2.money;
		System.out.println("\t得到总金钱: "+GetMoney);
	}
}
