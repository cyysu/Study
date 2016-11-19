#include "stu_xlp.h"

void menue(void)
{
	int i, j, log_conf, reg_conf, chg_conf, mov_conf, sel_conf;//分别接受登录，注册，修改，移除，选课是否成功的参数
	int k = 0; 	//密码登录的次数
	int ret, course;	//选课ID号
	char sel;	//接受选课确认
	char code[128], conf_code[128];//接受用户密码输入
	char buf[8], name[128];//name接受用户名输入

	LLIST *stu_handle = stu_load();
	LLIST *teach_handle = teach_load();

	LLIST *course_handle = course_load();

	/*course_handle  = llist_create(sizeof(struct course_t));*/

	system("stty -echo");
	system("stty -icanon");

	system("clear");
	printf("\033[1;1H");
	while(1)
	{
stu:	system("clear");
		printf("***********学生管理系统************\n");
		printf("选择登录身份\n");
		printf("1. 学生	2. 老师	3. 管理员  4. 退出\n");

		k = 0;
		if (ret == -1)
		{
			return ;
		}
		if(buf[0] == 27 && ret == 1)
		{
			break;
		}

		ret = read(0, buf, sizeof(buf));
		switch(buf[0])
		{
			case 49:	//student界面
			  {
stu1:			  system("clear");
				  printf("1. 登录	2. 注册	 3. 退出\n");
				  
				  ret = read(0, buf, sizeof(buf));
				  switch(buf[0])
				  {
					  case 49:	//登录帐号
						  {
	login:		  	        system("clear");
							printf("login name : ");	//输入登录名
							
							system("stty echo icanon");
							fgets(name, sizeof(name), stdin);
							if(name[strlen(name) - 1] == '\n')
								name[strlen(name) - 1] = '\0';
							
							printf("login code : ");	//调用密码函数
                            /*
							 *fgets(code, sizeof(code), stdin);
							 *if(code[strlen(code) - 1] == '\n')
							 *    code[strlen(code) - 1] = '\0';
                             */
							//log_conf = find_name_code(name, code), 如果用户和密码正确返回1，错误返回0
							passwd(code, sizeof(code));

							log_conf = stu_login(name, code, stu_handle);
							system("stty -echo -icanon");
							if(k < 5)	//密码用户名只能输错5次
							{
								/*log_conf = 1;*/
								if(log_conf)	//用户名和密码是否都正确
								{
login_look:							system("clear");
									printf("1. 查看课程信息		2. 查看个人信息		3. 选课		4. 退出登录\n");
									ret = read(0, buf, sizeof(buf));
									switch(buf[0])
									{
										case 49:	//查看课程信息
											{
login_cur:										system("clear");
												printf("1. 必修 2. 选修 3. 全部 4. 退出\n");
	
												ret = read(0, buf, sizeof(buf));
												switch(buf[0])
												{
													case 49:	//查看必修
														{
															/*printf("\nbixiu\n");*/
															stu_cls(name, stu_handle);
															getchar();
															goto login_cur;
														}
													case 50:	//查看选修
														{
															/*printf("\nxuanxiu\n");*/
															stu_ls_course(name, stu_handle, course_handle);
															getchar();
															goto login_cur;
														}
													case 51:	//查看全部
														{
															/*printf("\nall course\n");*/
															stu_cls(name, stu_handle);
															stu_ls_course(name, stu_handle, course_handle);
															getchar();
															goto login_cur;
														}
													case 52:	//退出查看课程信息子菜单
														{
															goto login_look;
														}
													default:
														{
															printf("\ninput error!\n");
															sleep(2);
															goto login_cur;
														}
												}
											}
										case 50:	//查看学生个人信息
											{
stu_look:										system("clear");
												//show students message ;//显示学生信息 
												stu_pls(name, stu_handle);
												printf("1. 修改个人信息		2. 返回\n");
												ret = read(0, buf, sizeof(buf));
												switch(buf[0])
												{
													case 49:	//修改个人信息
														{
												//		system("stty echo icanon");
														/*
														 *printf("please input old code : ");	//输入原密码
														 *fgets(code, sizeof(code), stdin);
														 *if(code[strlen(code) - 1] == '\n')
														 *    code[strlen(code) - 1] = '\0';
														 *//*log_code = find_code(code);	//比较原密码
														 *printf("please input new code : ");	//输入新密码
														 *fgets(code, sizeof(code), stdin);
														 *if(code[strlen(code) - 1] == '\n')
														 *    code[strlen(code) - 1] = '\0';
														 */
		//=====================================================================================
		stu_chag:										system("clear");
														printf("1. 修改姓名  2. 修改年龄  3. 修改性别 4. 修改密码  5. 退出\n");
														ret = read(0, buf, sizeof(buf));
														switch(buf[0])
														{
															case 49:	//修改姓名
																{
																	printf("change name\n");
																	stu_mod(name, 1, stu_handle);
																	getchar();
																	goto stu_chag;
																}
															case 50:	//修改年龄
																{
																	printf("change age\n");
																	stu_mod(name, 2, stu_handle);
																	getchar();
																	getchar();
																	goto stu_chag;

																}
															case 51:	//修改性别
																{
																	printf("change sex\n");
																	stu_mod(name, 3, stu_handle);
																	getchar();
																	getchar();
																	goto stu_chag;

																}
															case 52:	//修改密码
																{
																	printf("change code\n");
																	stu_mod(name, 4, stu_handle);
																	getchar();
																	goto stu_chag;

																}
															case 53:	//退出
																{
																	goto stu_look;
																}
															default :
																{
																	printf("input error!\n");
																	sleep(2);
																	goto stu_chag;
																}
														}
												//		system("stty -echo -icanon");

														/*
														 *if(log_code)	//与原密码相同就修改
														 *{
														 *    printf("密码修改成功!\n");
														 *    sleep(2);
														 *    goto login_look;
														 *}
														 *else	//否则退出
														 *{
														 *    printf("old code error!\n");
														 *    sleep(2);
														 *    goto login_look;
														 *}
														 */
													
															goto stu_look;

														}
												case 50:	//返回登录界面
													{
														goto login_look;
													}
												default :
													{
														printf("input error!\n");
														sleep(2);
														goto stu_look;
													}
												}
											}
										case 51:	//学生选课
											{
stu_sel:										system("clear");
												course_ls_all(course_handle);
												//show course ;//显示选修课程
                                                /*
												 *printf("输入选修课程ID : ");
												 *system("stty echo icanon");
												 *scanf("%d", &course);
												 *getchar();
                                                 */
												//sel_conf = select_course(course, name); //调用选课函数
												sel_conf = choose_course(name, stu_handle, course_handle);
												if(sel_conf)	//是否选课成功
												{
													printf("选课成功!\n");
stu_sel1:											printf("是否继续选课(Y / N)：");
													scanf("%c", &sel);
													system("stty -echo -icanon");

													if(sel == 'Y' || sel == 'y')
													{
														goto stu_sel;
													}
													else if(sel == 'N' || sel == 'n')
													{
														goto login_look;
													}
													else
													{
														printf("input error!\n");
														sleep(2);
														goto stu_sel;
													}
												}
												else
												{
													printf("选课失败!\n");
													/*sleep(2);*/
													goto stu_sel1;
												}

											}
										case 52:	//退出登录
											{
												k = 0;
												log_conf = 0;
												reg_conf = 0;
												memset(code, 0, sizeof(code));
												memset(name, 0, sizeof(name));
												goto stu1;
											}
									}

								}
								else	//用户名或密码不正确就退出重新输入
								{
									printf("用户名不存在或密码错误！\n");
									sleep(2);
									k++;
									goto login;
								}
							}
							else	//用户或密码错误5次及以上禁止登录
							{
								printf("密码用户名错误次数过多！\n");
							}

						  }
					  case 50: //学生身份注册
						  {
stu_reg:					  system("clear");
							  printf("student regist!\n"); 
							  // reg_conf = regist(handle);//调用注册函数
							  /*reg_conf = 0;*/
							  reg_conf = stu_create(stu_handle);
							  if(reg_conf)
							  {
								 printf("注册成功！\n");
								 sleep(2);
								 goto stu1;
							  }
							  else
							  {
								printf("注册失败！\n");
stu_failed:						printf("1.继续注册	2.放弃\n");

				  				ret = read(0, buf, sizeof(buf));
								switch(buf[0])
								{
									case 49:
										{
											goto stu_reg;
										}
									case 50:
										{
											goto stu1;
										}
									default :
										{
											printf("input error!\n");
											sleep(2);
											system("clear");
											goto stu_failed;
										}
								}

							  }
							  
/*
 *                              system("stty echo icanon");
 *                              printf("please input registe name : ");
 *                              fgets(name, sizeof(name), stdin);	//输入注册名
 *                              if(name[strlen(name) - 1] == '\n')
 *                                  name[strlen(name) - 1] = '\0';
 *
 *                            //  log_name = find_name(name);	//判断用户名是否存在
 *                              if(log_name)
 *                              {
 *                                  printf("次用户已存在！\n");
 *                                  memset(name, 0, sizeof(name));
 *                                  goto stu_reg;	//若存在则继续回到注册
 *                              }
 *                              else
 *                              {
 *                                  printf("请输入密码：");
 *                                    fgets(code, sizeof(code), stdin);
 *                                    if(code[strlen(code) - 1] == '\n')
 *                                        code[strlen(code) - 1] = '\0';
 *                        
 *                                  
 *                                  printf("请再次确认密码：");
 *                                    fgets(conf_code, sizeof(conf_code), stdin);
 *                                    if(conf_code[strlen(conf_code) - 1] == '\n')
 *                                        conf_code[strlen(conf_code) - 1] = '\0';
 *                                  system("stty -echo -icanon");
 *                              
 *                                  if(!strcmp(code, conf_code))	//判断两次输入的密码是否一样
 *                                  {
 *                                      printf("注册成功！\n");
 *                                      sleep(3);
 *                                      goto stu1;
 *                                  }
 *                                  else
 *                                  {
 *                                      printf("两次密码不一致！\n");
 *                                      memset(code, 0, sizeof(code));
 *                                      memset(conf_code, -1, sizeof(conf_code));
 *                                      memset(name, 0, sizeof(name));
 *                              
 *                                      printf("1. 继续注册	2. 放弃\n");
 *                                        
 *                                          ret = read(0, buf, sizeof(buf));
 *                                        switch(buf[0])
 *                                        {
 *                                            case 49:
 *                                                goto stu_reg;
 *                                            case 50:
 *                                                goto stu1; 
 *                                        }
 *                              
 *                                  }
 *                              }
 */
							  
							  
						  }
					  case 51:
						  {
							break;
						  }
					  default :	//输入错误则提示2秒钟
						  {
							  printf("input error!\n");
							  sleep(2);
							  goto stu1;
						  }
				  }
				  goto stu;	//重新回到主菜单
			  }
			case 50:	//teacher界面
			  {	
tea1:			  system("clear");
				  printf("1. 登录	2.退出\n");
				  
				  ret = read(0, buf, sizeof(buf));
				  switch(buf[0])
				  {
					  case 49:	//教师登录
						  {
tea_login:					  system("clear");
                              system("stty echo icanon");
							  printf("login name : ");

                              fgets(name, sizeof(name), stdin);
                                if(name[strlen(name) - 1] == '\n')
                                  name[strlen(name) - 1] = '\0';
								
							  printf("login code : ");
                              /*
                               *fgets(code, sizeof(code), stdin);
                               *  if(code[strlen(code) - 1] == '\n')
                               *    code[strlen(code) - 1] = '\0';
                               */

							  passwd(code, sizeof(code));
                              system("stty -echo -icanon");

							  //log_conf = find_name_code(name, code);//教师用户名和密码都正确则返回1， 否则返回0
							  log_conf = teach_login(name, code, teach_handle);
							  if(log_conf)	//登录成功则进入执行界面
							  {
tea_look:						  system("clear");
								  printf("1. 查看学生信息	2. 查看个人信息	  3. 查看成绩	4. 添加新课程    5.退出登录\n");
				  				  ret = read(0, buf, sizeof(buf));
								  switch(buf[0])
								  {
								  	case 49:	//查看学生信息
										{
tea_look1:									system("clear");
											ls_all_stu(stu_handle);
											printf("1. 修改学生信息	 2. 查找学生信息  3. 移除学生档案	4. 返回\n");
				  				  			ret = read(0, buf, sizeof(buf));
											switch(buf[0])
											{
												case 49:	//修改学生信息
													{
tea_look2:												system("clear");
														//show stidents messages
														ls_all_stu(stu_handle);
														printf("1. 修改姓名	 2. 修改性别  3. 修改年龄  4. 退出\n");
				  				  						ret = read(0, buf, sizeof(buf));
														switch(buf[0])
														{
															case 49:	//修改姓名
																{
																//	chg_conf = chang(1, handle);	//调用修改参数
																	chg_conf = mod_stu(stu_handle, 1);
																	if(chg_conf)
																		printf("修改成功！\n");
																	getchar();
																	goto tea_look2;
																}
															case 50:
																{
																//	chg_conf = chang(3, handle);	//调用修改参数
																	/*chg_conf = 1;*/
																	chg_conf = mod_stu(stu_handle, 3);
																	if(chg_conf)
																		printf("修改成功！\n");
																	getchar();
																	goto tea_look2;
																}
															case 51:	//修改年龄
																{
																//	chg_conf = chang(4, handle);	//调用修改参数
																	/*chg_conf = 1;*/
																	chg_conf = mod_stu(stu_handle, 2);
																	if(chg_conf)
																		printf("修改成功！\n");
																	getchar();
																	goto tea_look2;
																}
															case 52:	//退出
																{
																	goto tea_look1;
																}
															default :
																{
																	printf("input error!\n");
																	sleep(2);
																	goto tea_look2;
																}
														}

													}
												case 50:	//查找学生信息
													{
tea_look3:												system("clear");
														printf("1. 按ID查找   2. 按姓名查找   3. 按年龄查找   4. 按性别查找	5. 退出\n");
				  				  						ret = read(0, buf, sizeof(buf));
														switch(buf[0])
														{
															case 49:	//按ID查找
																{
																	// 调用ID查找函数
																	printf("ID\n");
																	find_stu(stu_handle, 1);
																	getchar();
																	goto tea_look3;
																}
															case 50:	//按姓名查找
																{
																	//调用姓名查找函数
																	printf("name\n");
																	find_stu(stu_handle, 2);
																	getchar();
																	goto tea_look3;
																}
															case 51:	//按年龄查找
																{
																	//调用年龄查找函数
																	printf("age\n");
																	find_stu(stu_handle, 3);
																	getchar();
																	goto tea_look3;
																}
															case 52:	//按性别查找
																{
																	//调用性别查找函数
																	printf("sex\n");
																	find_stu(stu_handle, 4);
																	getchar();
																	goto tea_look3;
																}
															case 53:	//退出
																{
																	goto tea_look1;
																}
															default :
																{
																	printf("input error!\n");
																	sleep(2);
																	goto tea_look3;
																}
														}

													}
												case 51:	//移除学生档案
													{
														//mov_conf = move(id); //调用移除函数
														mov_conf = move_stu(stu_handle);
														if(mov_conf)
														{
															printf("移除成功!\n");
														}
														else
														{
															printf("没有此用户!\n");
														}
														sleep(2);
														goto tea_look1;

													}
												case 52:	//返回老师登录界面
													{
														goto tea_look;
													}
												default :
													{
														printf("input error!\n");
														sleep(2);
														goto tea_look1;
													}
											}
										}
									case 50:	//查看个人信息
										{
tea_look4:									system("clear");
											teach_pls(name, teach_handle);
											printf("1. 修改个人信息	  2. 退出\n");
				  				  			ret = read(0, buf, sizeof(buf));
											switch(buf[0])
											{
												case 49:
													{
tea_look5:												system("clear");
														printf("1. 修改姓名	   2. 修改性别   3. 修改密码    4. 退出\n");
				  				  						ret = read(0, buf, sizeof(buf));
														switch(buf[0])
														{
															case 49:
																{
																	printf("name\n");
																	teach_mod(name, 1, teach_handle);
																	getchar();
																	goto tea_look5;
																}
															case 50:
																{
																	printf("sex\n");
																	teach_mod(name, 3, teach_handle);
																	getchar();
																	getchar();
																	goto tea_look5;
																}
															case 51:
																{
																	printf("code\n");
																	teach_mod(name, 4, teach_handle);
																	getchar();
																	goto tea_look5;
																}
															case 52:
																{
																	goto tea_look4;
																}
															default :
																{
																	printf("input error!\n");
																	sleep(2);
																	goto tea_look5;
																}

														}

													}
												case 50:	//退出
													{
														goto tea_look;
													}
												default :
													{
														printf("input error!\n");
														sleep(2);
														goto tea_look4;
													}
											}
										}
									case 51:	//查看课程成绩
										{
tea_look6:									system("clear");
											//show course 打印课程成绩
											grad_ls(stu_handle, course_handle);
											printf("1. 选修   2. 必修   3. 退出\n");

											ret = read(0, buf, sizeof(buf));
											switch(buf[0])
											{
												case 49:
													{
tea_look7:												system("clear");
														
														//show course 打印课程成绩
														grad_elec_ls(stu_handle, course_handle);
														printf("1. 修改成绩    2. 退出\n");

														ret = read(0, buf, sizeof(buf));
														switch(buf[0])
														{
															case 49:
																{
																	//调用修改函数
																	printf("change mark!\n");
																	mod_elec(course_handle, stu_handle);
																	getchar();
																	goto tea_look7;
																}
															case 50:
																{
																	goto tea_look6;
																}
															default :
																{
																	printf("input error!\n");
																	sleep(2);
																	goto tea_look7;
																}
														}
													}
												case 50:
													{
tea_look8:												system("clear");
														//show course 打印课程成绩
														grad_comp_ls(stu_handle);
														printf("1. 修改成绩    2. 退出\n");

														ret = read(0, buf, sizeof(buf));
														switch(buf[0])
														{
															case 49:
																{
																	//调用修改函数
																	printf("change mark!\n");
																	mod_comp(stu_handle);
																	getchar();
																	goto tea_look8;
																}
															case 50:
																{
																	goto tea_look6;
																}
															default :
																{
																	printf("input error!\n");
																	sleep(2);
																	goto tea_look8;
																}
														}
													}
												case 51:
													{
														goto tea_look;
													}
												default :
													{
														printf("input error!\n");
														sleep(2);
														goto tea_look6;
													}
											}
										}
									case 52:	//添加新课程
										{
tea_cou:									system("clear");
											//调用添加课程函数
											course_ls_all(course_handle);
											printf("add course\n");
											course_add(course_handle);
											printf("1. 是否继续添加    2. 放弃\n");

											ret = read(0, buf, sizeof(buf));
											switch(buf[0])
											{
												case 49:
													{
														goto tea_cou;
													}
												case 50:
													{
														goto tea_look;
													}
												default :
													{
														printf("input error!\n");
														sleep(2);
														goto tea_cou;
													}
											}

										}
									case 53:	//退出教师登录
										{
											goto tea1;
										}
									default :
										{
											printf("input error!\n");
											sleep(2);
											goto tea_look;
										}
								  }

							  }
							  else
							  {
								  printf("帐号不存在或密码错误！\n");
								  sleep(2);
								  goto tea1;
							  }


						  }
					  case 50:	//教师退出
						  {
							 goto stu;
						  }
					  default :
						  {
							  printf("input error!\n");
							  sleep(2);
							  goto tea1;
						  }
				  }

			  }
			 case 51:	//admin
			  {
admin:			  system("clear");
				  printf("1. 登录	2. 退出\n");
				  ret = read(0, buf, sizeof(buf));
				  switch(buf[0])
				  {
					  case 49:	//登录管理员用户
						  {
							  system("clear");
							  printf("login name : ");
							  system("stty echo icanon");

							  fgets(name, sizeof(name), stdin);		//输入用户名
							  if(name[strlen(name) - 1] == '\n')
							  	  name[strlen(name) - 1] = '\0';

							  printf("login code : ");
                              /*
							   *fgets(code, sizeof(code), stdin);	//输入管理员密码
							   *if(code[strlen(code) - 1] == '\n')
							   *    code[strlen(code) - 1] = '\0';
                               */
							  passwd(code, sizeof(code));
							  system("stty -echo -icanon");

							  //log_conf = find(name, code, handle); //用户名和密码都正确则进入
							  log_conf = root_login(name, code);
							  if(log_conf)
							  {
admin_chg:						  system("clear");
							  	  printf("1. 修改教师帐号信息	2. 修改学生帐号信息	  3. 退出登录\n");
				  				  ret = read(0, buf, sizeof(buf));
								  switch(buf[0])
								  {
									  case 49:	//修改教师的帐号
										  {
admin_chg1:									  system("clear");
											  printf("1. 修改教师密码	2. 添加教师帐号   3. 删除教师帐号   4. 退出\n");
											  ret = read(0, buf, sizeof(buf));
											  switch(buf[0])
											  {
												  case 49: //修改教师用户登录密码
													  {	
														  system("clear");
														  ls_all_teach(teach_handle);
														  printf("请输入用户名：");
														  system("stty echo icanon");
														  fgets(buf, sizeof(buf), stdin);
														  if(buf[strlen(buf) - 1] == '\n')
															  buf[strlen(buf) - 1] = '\0';
														  system("stty -echo -icanon");
														  //change_code(name);	//调用修改函数

														  printf("teacher code\n");//调用修改函数
														  teach_mod(buf, 5, teach_handle);
														  getchar();
														  goto admin_chg1; 
													  }
												  case 50:	//添加教师用户帐号
													  {
admin_chg2:												  system("clear");
														  printf("teacher register!\n");
														  //reg_conf = fiand(); //调用教师注册函数
														  reg_conf = teach_add(teach_handle);		//是否注册成功，返回1 表示成功注册，0 表示注册失败
														  if(reg_conf)
														  {
															  printf("添加成功!\n");
															  sleep(2);
															  goto admin_chg3;
														  }
														  else
														  {
															  printf("添加失败!\n");
admin_chg3:													  printf("1. 继续添加	2. 放弃\n");
															  ret = read(0, buf, sizeof(buf));
															  switch(buf[0])
															  {
																  case 49:
																	  {
																		  goto admin_chg2;
																	  }
																  case 50:
																	  {
																		  goto admin_chg1;
																	  }
																  default :
																	  {
																		  printf("input error!\n");
																		  sleep(2);
																		  system("clear");
																		  goto admin_chg3;
																	  }
															  }
														  }
													  }
												  case 51:	//删除教师帐号
													  {
														  //show teacher ;//显示老师的信息
														  ls_all_teach(teach_handle);
														  printf("del teacher messages!\n");
														  del_teach(teach_handle);
														  getchar();
														  goto admin_chg1;
													  }
												  case 52:	//退出
													  {
														  goto admin_chg;
													  }
												  default :
													  {
														  printf("input error!\n");
														  sleep(2);
														  goto admin_chg1;
													  }
											  }

										  }
									  case 50:	//修改学生帐号信息
										  {
admin_chg4:									  system("clear");
											  ls_all_stu1(stu_handle);
											  printf("1. 删除学生帐号	 2. 修改学生密码	3. 退出\n");
											  ret = read(0, buf, sizeof(buf));
											  switch(buf[0])
											  {
												  case 49: //删除学生帐号
													  {
														  //show student message;//显示学生信息
														  printf("del student message!\n"); //调用删除函数
														  del_stu(stu_handle);
														  getchar();
														  goto admin_chg4;
													  }
												  case 50:	//修改学生密码
													  {
														  system("clear");
														  printf("请输入用户名：");
														  system("stty echo icanon");
														  fgets(buf, sizeof(buf), stdin);
														  if(buf[strlen(buf) - 1] == '\n')
															  buf[strlen(buf) - 1] = '\0';
														  system("stty -echo -icanon");

														  stu_pls(buf, stu_handle);
														  printf("change students!\n");
														  stu_mod(buf, 5, stu_handle);
														  getchar();
														  goto admin_chg4;
													  }
												  case 51: //返回
													  {
														  goto admin_chg;
													  }
												  default :
													  {
														  printf("input error!\n");
														  sleep(2);
														  goto admin_chg4;
													  }
											  }

										  }
									  case 51:	//退出登录
										  {
											  goto admin;	
										  }
									  default :
										  {
											  printf("input error!\n");
											  sleep(2);
											  goto admin_chg;
										  }
								  }

							  }
							  else
							  {
								  printf("帐号不存在或密码错误！\n");
								  sleep(2);
								  goto admin;
							  }

						  }
					  case 50:	//退出管理员用户
						  {
							  goto stu;
						  }
					  default :
						  {
							  printf("input error!\n");
							  sleep(2);
							  goto admin;
						  }

				  }

			  }
			 case 52:	//exit
			  {
			  	  stu_store(stu_handle);
			  	  teach_store(teach_handle);
			  	  course_store(course_handle);
				  goto out;
			  }
			 default :
			  {
				  printf("input error!\n");
				  goto stu;
			  }



			fflush(NULL);
			memset(buf, 0, sizeof(buf));
		}

		
		
	
	
	}
out:
	system("stty echo");
	system("stty icanon");

}





