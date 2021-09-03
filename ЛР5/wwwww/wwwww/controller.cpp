#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
#include "map.h"
#include "snake.h"
#include "food.h"

void Controller::Start()//¿ªÊ¼½çÃæ
{
    SetWindowSize(41, 32);//ÉèÖÃ´°¿Ú´óĞ¡
    SetColor(2);//ÉèÖÃ¿ªÊ¼¶¯»­ÑÕÉ«
    StartInterface *start = new StartInterface();//¶¯Ì¬·ÖÅäÒ»¸öStartInterfaceÀàstart
    start->Action();//¿ªÊ¼¶¯»­
    delete start;//ÊÍ·ÅÄÚ´æ¿Õ¼ä

    /*ÉèÖÃ¹Ø±êÎ»ÖÃ£¬²¢Êä³öÌáÊ¾Óï£¬µÈ´ıÈÎÒâ¼üÊäÈë½áÊø*/
    SetCursorPosition(13, 26);
    std::cout << "Press any key to start... " ;
    SetCursorPosition(13, 27);
    system("pause");
}

void Controller::Select()//Ñ¡Ôñ½çÃæ
{
    /*³õÊ¼»¯½çÃæÑ¡Ïî*/
    SetColor(3);
    SetCursorPosition(13, 26);
    std::cout << "                          " ;
    SetCursorPosition(13, 27);
    std::cout << "                          " ;
    SetCursorPosition(6, 21);
    std::cout << "SnakeOFVitya" ;
    SetCursorPosition(6, 22);
    std::cout << "(Âèèèèèèòÿ)" ;
    SetCursorPosition(27, 22);
    SetBackColor();//µÚÒ»¸öÑ¡ÏîÉèÖÃ±³¾°É«ÒÔ±íÊ¾µ±Ç°Ñ¡ÖĞ
    std::cout << "Óğîâåíü1" ;
    SetCursorPosition(27, 24);
    SetColor(3);
    std::cout << "Óğîâåíü2" ;
    SetCursorPosition(27, 26);
    std::cout << "Óğîâåíü3" ;
    SetCursorPosition(27, 28);
    std::cout << "Óğîâåíü4" ;
    SetCursorPosition(0, 31);
    score = 0;

    /*ÉÏÏÂ·½Ïò¼üÑ¡ÔñÄ£¿é*/
    int ch;//¼ÇÂ¼¼üÈëÖµ
    key = 1;//¼ÇÂ¼Ñ¡ÖĞÏî£¬³õÊ¼Ñ¡ÔñµÚÒ»¸ö
    bool flag = false;//¼ÇÂ¼ÊÇ·ñ¼üÈëEnter¼ü±ê¼Ç£¬³õÊ¼ÖÃÎª·ñ
    while ((ch = _getch()))
    {
        switch (ch)//¼ì²âÊäÈë¼ü
        {
        case 72://UPÉÏ·½Ïò¼ü
            if (key > 1)//µ±´ËÊ±Ñ¡ÖĞÏîÎªµÚÒ»ÏîÊ±£¬UPÉÏ·½Ïò¼üÎŞĞ§
            {
                switch (key)
                {
                case 2:
                    SetCursorPosition(27, 22);//¸ø´ıÑ¡ÖĞÏîÉèÖÃ±³¾°É«
                    SetBackColor();
                    std::cout << "Óğîâåíü1" ;

                    SetCursorPosition(27, 24);//½«ÒÑÑ¡ÖĞÏîÈ¡ÏûÎÒ±³¾°É«
                    SetColor(3);
                    std::cout << "Óğîâåíü2" ;

                    --key;
                    break;
                case 3:
                    SetCursorPosition(27, 24);
                    SetBackColor();
                    std::cout << "Óğîâåíü2" ;

                    SetCursorPosition(27, 26);
                    SetColor(3);
                    std::cout << "Óğîâåíü3" ;

                    --key;
                    break;
                case 4:
                    SetCursorPosition(27, 26);
                    SetBackColor();
                    std::cout << "Óğîâåíü3" ;

                    SetCursorPosition(27, 28);
                    SetColor(3);
                    std::cout << "Óğîâåíü4" ;

                    --key;
                    break;
                }
            }
            break;

        case 80://DOWNÏÂ·½Ïò¼ü
            if (key < 4)
            {
                switch (key)
                {
                case 1:
                    SetCursorPosition(27, 24);
                    SetBackColor();
                    std::cout << "Óğîâåíü2" ;
                    SetCursorPosition(27, 22);
                    SetColor(3);
                    std::cout << "Óğîâåíü1" ;

                    ++key;
                    break;
                case 2:
                    SetCursorPosition(27, 26);
                    SetBackColor();
                    std::cout << "Óğîâåíü3" ;
                    SetCursorPosition(27, 24);
                    SetColor(3);
                    std::cout << "Óğîâåíü2" ;

                    ++key;
                    break;
                case 3:
                    SetCursorPosition(27, 28);
                    SetBackColor();
                    std::cout << "Óğîâåíü4" ;
                    SetCursorPosition(27, 26);
                    SetColor(3);
                    std::cout << "Óğîâåíü3" ;

                    ++key;
                    break;
                }
            }
            break;

        case 13://Enter»Ø³µ¼ü
            flag = true;
            break;
        default://ÎŞĞ§°´¼ü
            break;
        }
        if (flag) break;//ÊäÈëEnter»Ø³µ¼üÈ·ÈÏ£¬ÍË³ö¼ì²éÊäÈëÑ­»·

        SetCursorPosition(0, 31);//½«¹â±êÖÃÓÚ×óÏÂ½Ç£¬±ÜÃâ¹Ø±êÉÁË¸Ó°ÏìÓÎÏ·ÌåÑé
    }

    switch (key)//¸ù¾İËùÑ¡Ñ¡ÏîÉèÖÃÉßµÄÒÆ¶¯ËÙ¶È£¬speedÖµÔ½Ğ¡£¬ËÙ¶ÈÔ½¿ì
    {
    case 1:
        speed = 135;
        break;
    case 2:
        speed = 100;
        break;
    case 3:
        speed = 60;
        break;
    case 4:
        speed = 30;
        break;
    default:
        break;
    }
}

void Controller::DrawGame()//»æÖÆÓÎÏ·½çÃæ
{
    system("cls");//ÇåÆÁ

    /*»æÖÆµØÍ¼*/
    SetColor(3);
    Map *init_map = new Map();
    init_map->PrintInitmap();
    delete init_map;

    /*»æÖÆ²à±ßÀ¸*/
    SetColor(3);
    SetCursorPosition(33, 1);
    std::cout << "Victor gay" ;
    SetCursorPosition(34, 2);
    std::cout << "Âèêòîğ ıé" ;
    SetCursorPosition(31, 4);
    std::cout << "Âèêòîğ ıé" ;
    SetCursorPosition(36, 5);
    switch (key)
    {
    case 1:
        std::cout << "SCORE:" ;
        break;
    case 2:
        std::cout << "BOK2" ;
        break;
    case 3:
        std::cout << "BOK3" ;
        break;
    case 4:
        std::cout << "SCORE" ;
        break;
    default:
        break;
    }
    SetCursorPosition(31, 7);
    std::cout << "----------" ;
    SetCursorPosition(37, 8);
    std::cout << "     0" ;
    SetCursorPosition(33, 13);
    std::cout << " PAUSE" ;
    SetCursorPosition(33, 15);
    std::cout << " ESC" ;
}

int Controller::PlayGame()//ÓÎÏ·¶ş¼¶Ñ­»·
{
    /*³õÊ¼»¯ÉßºÍÊ³Îï*/
    Snake *csnake = new Snake();
    Food *cfood = new Food();
    SetColor(6);
    csnake->InitSnake();
    srand((unsigned)time(NULL));//ÉèÖÃËæ»úÊıÖÖ×Ó£¬Èç¹ûÃ»ÓĞ Ê³ÎïµÄ³öÏÖÎ»ÖÃ½«»á¹Ì¶¨
    cfood->DrawFood(*csnake);

    /*ÓÎÏ·Ñ­»·*/
    while (csnake->OverEdge() && csnake->HitItself()) //ÅĞ¶ÏÊÇ·ñ×²Ç½»ò×²µ½×ÔÉí£¬¼´ÊÇ·ñ»¹ÓĞÉúÃü
    {
        /*µ÷³öÑ¡Ôñ²Ëµ¥*/
        if (!csnake->ChangeDirection()) //°´Esc¼üÊ±
        {
            int tmp = Menu();//»æÖÆ²Ëµ¥£¬²¢µÃµ½·µ»ØÖµ
            switch (tmp)
            {
            case 1://¼ÌĞøÓÎÏ·
                break;

            case 2://ÖØĞÂ¿ªÊ¼
                delete csnake;
                delete cfood;
                return 1;//½«1×÷ÎªPlayGameº¯ÊıµÄ·µ»ØÖµ·µ»Øµ½Gameº¯ÊıÖĞ£¬±íÊ¾ÖØĞÂ¿ªÊ¼

            case 3://ÍË³öÓÎÏ·
                delete csnake;
                delete cfood;
                return 2;//½«2×÷ÎªPlayGameº¯ÊıµÄ·µ»ØÖµ·µ»Øµ½Gameº¯ÊıÖĞ£¬±íÊ¾ÍË³öÓÎÏ·

            default:
                break;
            }
        }

        if (csnake->GetFood(*cfood)) //³Ôµ½Ê³Îï
        {
            csnake->Move();//ÉßÔö³¤
            UpdateScore(1);//¸üĞÂ·ÖÊı£¬1Îª·ÖÊıÈ¨ÖØ
            RewriteScore();//ÖØĞÂ»æÖÆ·ÖÊı
            cfood->DrawFood(*csnake);//»æÖÆĞÂÊ³Îï
        }
        else
        {
            csnake->NormalMove();//ÉßÕı³£ÒÆ¶¯
        }

        if (csnake->GetBigFood(*cfood)) //³Ôµ½ÏŞÊ±Ê³Îï
        {
            csnake->Move();
            UpdateScore(cfood->GetProgressBar()/5);//·ÖÊı¸ù¾İÏŞÊ±Ê³Îï½ø¶ÈÌõÈ·¶¨
            RewriteScore();
        }

        if (cfood->GetBigFlag()) //Èç¹û´ËÊ±ÓĞÏŞÊ±Ê³Îï£¬ÉÁË¸Ëü
        {
            cfood->FlashBigFood();
        }

        Sleep(speed);//ÖÆÔìÉßµÄÒÆ¶¯Ğ§¹û
    }

    /*ÉßËÀÍö*/
    delete csnake;//ÊÍ·Å·ÖÅäµÄÄÚ´æ¿Õ¼ä
    delete cfood;
    int tmp = GameOver();//»æÖÆÓÎÏ·½áÊø½çÃæ£¬²¢·µ»ØËùÑ¡Ïî
    switch (tmp)
    {
    case 1:
        return 1;//ÖØĞÂ¿ªÊ¼
    case 2:
        return 2;//ÍË³öÓÎÏ·
    default:
        return 2;
    }
}

void Controller::UpdateScore(const int& tmp)//¸üĞÂ·ÖÊı
{
    score += key * 10 * tmp;//ËùµÃ·ÖÊı¸ù¾İÓÎÏ·ÄÑ¶È¼°´«ÈËµÄ²ÎÊıtmpÈ·¶¨
}

void Controller::RewriteScore()//ÖØ»æ·ÖÊı
{
    /*Îª±£³Ö·ÖÊıÎ²²¿¶ÔÆë£¬½«×î´ó·ÖÊıÉèÖÃÎª6Î»£¬¼ÆËãµ±Ç°·ÖÊıÎ»Êı£¬½«Ê£ÓàÎ»ÊıÓÃ¿Õ¸ñ²¹È«£¬ÔÙÊä³ö·ÖÊı*/
    SetCursorPosition(37, 8);
    SetColor(11);
    int bit = 0;
    int tmp = score;
    while (tmp != 0)
    {
        ++bit;
        tmp /= 10;
    }
    for (int i = 0; i < (6 - bit); ++i)
    {
        std::cout << " " ;
    }
    std::cout << score ;
}

int Controller::Menu()//Ñ¡Ôñ²Ëµ¥
{
    /*»æÖÆ²Ëµ¥*/
    SetColor(11);
    SetCursorPosition(32, 19);
    std::cout << "Menu" ;
    Sleep(100);
    SetCursorPosition(34, 21);
    SetBackColor();
    std::cout << "Vict1" ;
    Sleep(100);
    SetCursorPosition(34, 23);
    SetColor(11);
    std::cout << "Vict2" ;
    Sleep(100);
    SetCursorPosition(34, 25);
    std::cout << "Vict3" ;
    SetCursorPosition(0, 31);

    /*Ñ¡Ôñ²¿·Ö*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch()))
    {
        switch (ch)
        {
        case 72://UP
            if (tmp_key > 1)
            {
                switch (tmp_key)
                {
                case 2:
                    SetCursorPosition(34, 21);
                    SetBackColor();
                    std::cout << "Vict1" ;
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "Vict2" ;

                    --tmp_key;
                    break;
                case 3:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "Vict2" ;
                    SetCursorPosition(34, 25);
                    SetColor(11);
                    std::cout << "Vict3" ;

                    --tmp_key;
                    break;
                }
            }
            break;

        case 80://DOWN
            if (tmp_key < 3)
            {
                switch (tmp_key)
                {
                case 1:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "Vict2" ;
                    SetCursorPosition(34, 21);
                    SetColor(11);
                    std::cout << "Vict1" ;

                    ++tmp_key;
                    break;
                case 2:
                    SetCursorPosition(34, 25);
                    SetBackColor();
                    std::cout << "Vict3" ;
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "Vict2" ;

                    ++tmp_key;
                    break;
                }
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        if (flag)
        {
            break;
        }
        SetCursorPosition(0, 31);
    }

    if (tmp_key == 1) //Ñ¡Ôñ¼ÌĞøÓÎÏ·£¬Ôò½«²Ëµ¥²Á³ı
    {
        SetCursorPosition(32, 19);
        std::cout << "      " ;
        SetCursorPosition(34, 21);
        std::cout << "        ";
        SetCursorPosition(34, 23);
        std::cout << "        ";
        SetCursorPosition(34, 25);
        std::cout << "        ";
    }
    return tmp_key;
}

void Controller::Game()//ÓÎÏ·Ò»¼¶Ñ­»·
{
    Start();//¿ªÊ¼½çÃæ
    while (true)//ÓÎÏ·¿ÉÊÓÎªÒ»¸öËÀÑ­»·£¬Ö±µ½ÍË³öÓÎÏ·Ê±Ñ­»·½áÊø
    {
        Select();//Ñ¡Ôñ½çÃæ
        DrawGame();//»æÖÆÓÎÏ·½çÃæ
        int tmp = PlayGame();//¿ªÆôÓÎÏ·Ñ­»·£¬µ±ÖØĞÂ¿ªÊ¼»òÍË³öÓÎÏ·Ê±£¬½áÊøÑ­»·²¢·µ»ØÖµ¸øtmp
        if (tmp == 1) //·µ»ØÖµÎª1Ê±ÖØĞÂ¿ªÊ¼ÓÎÏ·
        {
            system("cls");
            continue;
        }
        else if (tmp == 2) //·µ»ØÖµÎª2Ê±ÍË³öÓÎÏ·
        {
            break;
        }
        else
        {
            break;
        }
    }
}

int Controller::GameOver()//ÓÎÏ·½áÊø½çÃæ
{
    setlocale(LC_ALL, "Russian");
    /*»æÖÆÓÎÏ·½áÊø½çÃæ*/
    Sleep(500);
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "+++++++++++++++++++++++++++++++++++++++" ;
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " |               Victory !!!              |" ;
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " |                                        |" ;
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " |              Âèêòîğ1                   |" ;
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " |                                        |" ;
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " |             Ñ÷¸ò                       |" ;
    SetCursorPosition(24, 13);
    std::cout << score ;
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " |                                        |" ;
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " |   û                                    |" ;
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " |                                        |" ;
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " |                                        |" ;
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " |    Ãëàâíîå ìåíş        Âûõîä           |" ;
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << " |                                        |" ;
    Sleep(30);
    SetCursorPosition(9, 20);
    std::cout << " |                                         |" ;
    Sleep(30);
    SetCursorPosition(10, 21);
    std::cout << "+++++++++++++++++++++++++++++++++++++++" ;

    Sleep(100);
    SetCursorPosition(12, 18);
    SetBackColor();
    std::cout << "àÅ£¬ºÃµÄ" ;
    SetCursorPosition(0, 31);

    /*Ñ¡Ôñ²¿·Ö*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch()))
    {
        switch (ch)
        {
        case 75://LEFT
            if (tmp_key > 1)
            {
                SetCursorPosition(12, 18);
                SetBackColor();
                std::cout << "Ãëàâíîå ìåíş" ;
                SetCursorPosition(20, 18);
                SetColor(11);
                std::cout << "Âûõîä" ;
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                SetCursorPosition(20, 18);
                SetBackColor();
                std::cout << "Âûõîä" ;
                SetCursorPosition(12, 18);
                SetColor(11);
                std::cout << "ÃËàâíîå ìåíş" ;
                ++tmp_key;
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        SetCursorPosition(0, 31);
        if (flag) {
            break;
        }
    }

    SetColor(11);
    switch (tmp_key)
    {
    case 1:
        return 1;//ÖØĞÂ¿ªÊ¼
    case 2:
        return 2;//ÍË³öÓÎÏ·
    default:
        return 1;
    }
}
