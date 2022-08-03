import sys
import os
from socket import gethostname

c_dir = "11root11/"
dir = "11root11/"
err = "chyba"
login = gethostname()

filesystem = open("filesystem.txt", "w")
dirsystem = open("directorysystem.txt", "a")
dirsystem.write(dir + ":" + "rwx" + "\n")
dirsystem.close()
error_state = True

while True:
    error_state = True

    user_input = input("# ")

    user_input_splitted = user_input.split(' ')
    user_input_len = len(user_input_splitted)

    ls = [] * 1000 
    
    if user_input == "":
        error_state = False
        print(err)
        
    if user_input_splitted[0] == "quit":
        error_state = False
        if user_input_len == 1:
            os.remove("filesystem.txt")
            os.remove("directorysystem.txt")

            sys.exit(1)
        else: 
            print(err)
            
    #ls
    if user_input_splitted[0] == "ls":
        error_state = False

        if user_input_len < 3:
            rights = 0
            right_1 = 'r--'
            right_2 = 'rw-'
            right_3 = 'rwx'
            right_4 = 'r-x'
            list_of_dirs = open("directorysystem.txt","r")
            lines = list_of_dirs.readlines()
            list_of_dirs.close()
            checking_dir = dir + ":"

            for riadok in lines:
                riadok_1 = riadok
                if checking_dir in riadok_1:
                    if right_1 in riadok_1:
                        rights = 1
                    elif right_2 in riadok_1:
                        rights = 1
                    elif right_3 in riadok_1:
                        rights = 1
                    elif right_4 in riadok_1:
                        rights = 1	
            if rights == 1:
                spravne = 0
                subory = open("filesystem.txt", "r")
                lines = subory.readlines()

                if user_input_len == 1:
                    spravne = 1
                    for riadok in lines:
                        dir_of_file = riadok[:riadok.index(":")]
                        if dir_of_file == dir:
                            zapis = riadok[riadok.index(":") + 1:]
                            ls.append(zapis)

                    if len(ls) == 0:	
                        print("ziaden subor")
                    else:
                        vypis = ''.join(ls)
                        vypis_suborov = vypis.replace(':subor\n','\n').replace(':',' ')
                        print(vypis_suborov[:-1])
                if user_input_len == 2:
                    spravne = 1
                    for riadok in lines:
                        na_vypis = dir + ":" + user_input_splitted[1] + ":"
                        if na_vypis in riadok:
                            vypis_suborov=riadok.replace(':subor\n', '\n').replace(':', ' ').replace(dir + " ", '')
                            print(vypis_suborov[:-1])
                if spravne == 0: print(err)

            else: print(err)
            
        else: print(err)

    #touch	
    if user_input_splitted[0] == "touch":
        error_state = False
        if user_input_len == 2:
            rights = 0
            right_1 = '-wx'
            right_2 = 'rw-'
            right_3 = 'rwx'
            right_4 = '-w-'
            list_of_dirs = open("directorysystem.txt", "r")
            lines = list_of_dirs.readlines()
            list_of_dirs.close()
            checking_dir = dir + ":"
            for riadok in lines:
                riadok_1 = riadok
                if checking_dir in riadok_1:
                    if right_1 in riadok_1:
                        rights = 1
                    elif right_2 in riadok_1:
                        rights = 1
                    elif right_3 in riadok_1:
                        rights = 1
                    elif right_4 in riadok_1:
                        rights = 1	
            if rights == 1:
                subory = open("filesystem.txt", "r")
                lines = subory.readlines()
                actual = (dir + ":" + user_input_splitted[1])
                spravne = 0
                premenna = 0
                for riadok in lines:
                    dir_of_file = lines[premenna]
                    check = dir_of_file.split(':')
                    check1 = (check[0] + ":" + check[1])
                    if check1 == actual:
                        print(err)
                        spravne = 1
                    premenna += 1
                if spravne == 0:
                    pridavanie = open("filesystem.txt", "a")
                    filesystem = (dir+ ":" + user_input_splitted[1] + ":" + login + ":" + "rwx" + ":" + "subor" + "\n")
                    pridavanie.write(filesystem)
                    pridavanie.close()
            else: print(err)
        else: print(err)

    #mkdir
    if user_input_splitted[0] == "mkdir":
        error_state = False
        if user_input_len == 2:
            rights = 0
            right_1 = '-wx'
            right_2 = 'rw-'
            right_3 = 'rwx'
            right_4 = '-w-'
            list_of_dirs = open("directorysystem.txt", "r")
            lines = list_of_dirs.readlines()
            list_of_dirs.close()
            checking_dir = dir + ":"
            for riadok in lines:
                riadok_1 = riadok
                if checking_dir in riadok_1:
                    if right_1 in riadok_1:
                        rights = 1
                    elif right_2 in riadok_1:
                        rights = 1
                    elif right_3 in riadok_1:
                        rights = 1
                    elif right_4 in riadok_1:
                        rights = 1	
            if rights == 1:
                spravne = 0	
                cislo_riadka = 0
                zapis_1 = ""
                list_of_dirs = open("filesystem.txt", "r")
                lines = list_of_dirs.readlines()
                list_of_dirs.close()

                for riadok in lines:
                    riadok_1 = riadok
                    str = dir + ":" + user_input_splitted[1] + ":"
                    if str in riadok:
                        print(err)
                        spravne = 1
                        break

                if spravne == 0:
                    writein = open("directorysystem.txt", "a")
                    zapis_1 = zapis_1 + dir + user_input_splitted[1] + "/" + ":" + "rwx" + "\n"
                    writein.write(zapis_1)
                    writein.close()

                    pridavanie = open("filesystem.txt", "a")
                    filesystem = (dir + ":" + user_input_splitted[1] + ":" + login + ":" + "rwx" + "\n")
                    pridavanie.write(filesystem)
                    pridavanie.close()
            else: print(err)
        else: print(err)

    #rm
    if user_input_splitted[0] == "rm":
        error_state = False
        if user_input_len == 2:
            spravne = 0		
            cislo_riadka  =0
            rights = 0
            err_here = 1
            err_here_second = 0
            right_1 = 'rwx'
            right_2 = '-wx'
            right_3 = 'rw-'
            right_4 = '-w-'
            list_of_dirs = open("directorysystem.txt","r")
            lines = list_of_dirs.readlines()
            list_of_dirs.close()
            checking_dir = "/" + user_input_splitted[1] + "/"
            for riadok in lines:
                riadok_1 = riadok
                if checking_dir in riadok_1:
                    err_here_second = 1
                    if right_1 in riadok_1:
                        rights = 1
                    elif right_2 in riadok_1:
                        rights = 1
                    elif right_3 in riadok_1:
                        rights = 1
                    elif right_4 in riadok_1:
                        rights = 1

                    if rights == 1:
                        riadokkk = riadok
                        lines = open("directorysystem.txt",'r').readlines()
                        lines[cislo_riadka] = ""
                        vystup = open("directorysystem.txt",'w')
                        vystup.writelines(lines)
                        vystup.close()
                        spravne = 1
                        rights = 0
                    else: err_here = 0
                else: cislo_riadka += 1
                
            list_of_dirs = open("filesystem.txt","r")
            lines = list_of_dirs.readlines()
            list_of_dirs.close()
            cislo_riadka = 0
            for riadok in lines:
                riadok_1 = riadok
                deleting = dir + ":" + user_input_splitted[1] + ":"
                if deleting in riadok_1:
                    err_here_second = 1
                    if right_1 in riadok_1:
                        rights = 1
                    elif right_2 in riadok_1:
                        rights = 1
                    elif right_3 in riadok_1:
                        rights = 1
                    elif right_4 in riadok_1:
                        rights = 1

                    if rights == 1:
                        riadokkk = riadok
                        lines = open("filesystem.txt",'r').readlines()
                        lines[cislo_riadka] = ""
                        vystup = open("filesystem.txt",'w')
                        vystup.writelines(lines)
                        vystup.close()
                        spravne = 1
                    else: err_here=0
                else: cislo_riadka += 1
            if err_here == 0: print(err)
            if err_here_second == 0: print(err)
        else: print(err)

    #cd
    if user_input_splitted[0] == "cd":
        error_state = False
        if user_input_len == 2:
            spravne = 0
            rights = 0
            right_1 = '--x'
            right_2 = '-wx'
            right_3 = 'r-x'
            right_4 = 'rwx'
            if user_input_splitted[1] == "..":
                previous_dir = dir.split('/')
                user_input_len = len(previous_dir) - 2
                dir = ""
                for i in range(user_input_len):
                    dir = dir + previous_dir[i] + "/"
                    c_dir = dir
                    spravne = 1

            else:
                list_of_dirs = open("directorysystem.txt", "r")
                lines = list_of_dirs.readlines()
                list_of_dirs.close()
                checking_dir = dir + user_input_splitted[1] + "/"
                for riadok in lines:
                    riadok_1 = riadok
                    if checking_dir in riadok_1:
                        if right_1 in riadok_1:
                            rights = 1
                        elif right_2 in riadok_1:
                            rights = 1
                        elif right_3 in riadok_1:
                            rights = 1
                        elif right_4 in riadok_1:
                            rights = 1	

                        if rights == 1:
                            dir = checking_dir
                            c_dir = dir
                            spravne = 1
                        else: 
                            print(err)
                            spravne = 1
            if spravne == 0: print(err)
        else: print(err)

    #vypis
    if user_input_splitted[0] == "vypis":
        error_state = False
        if user_input_len == 2:
            spravne = 0		
            cislo_riadka = 0
            rights = 0
            err_here = 1
            err_here_second = 0
            right_1 = 'rwx'
            right_2 = 'rw-'
            right_3 = 'r--'
            right_4 = 'r-x'
            list_of_dirs = open("filesystem.txt","r")
            lines = list_of_dirs.readlines()
            list_of_dirs.close()
            checking_dir = dir + ":" + user_input_splitted[1] + ":"
            file_1 = ":subor\n"
            for riadok in lines:
                riadok_1 = riadok
                if file_1 in riadok_1:
                    if checking_dir in riadok_1:
                        err_here_second = 1
                        if right_1 in riadok_1:
                            rights = 1
                        elif right_2 in riadok_1:
                            rights = 1
                        elif right_3 in riadok_1:
                            rights = 1
                        elif right_4 in riadok_1:
                            rights = 1

                        if rights == 1:
                            print("ok")
                        else: err_here = 0
                    else: cislo_riadka += 1
            if err_here_second == 0: print(err)
            if err_here == 0: print(err)
        else: print(err)
    
    #spusti
    if user_input_splitted[0] == "spusti":
        error_state = False
        if user_input_len == 2:
            spravne = 0		
            cislo_riadka = 0
            rights = 0
            err_here = 1
            err_here_second = 0
            right_1 = '--x'
            right_2 = '-wx'
            right_3 = 'rwx'
            right_4 = 'r-x'
            list_of_dirs = open("filesystem.txt","r")
            lines = list_of_dirs.readlines()
            list_of_dirs.close()
            checking_dir = dir + ":" + user_input_splitted[1] + ":"
            file_1 = ":subor\n"
            for riadok in lines:
                riadok_1 = riadok
                if file_1 in riadok_1:
                    if checking_dir in riadok_1:
                        err_here_second = 1
                        if right_1 in riadok_1:
                            rights = 1
                        elif right_2 in riadok_1:
                            rights = 1
                        elif right_3 in riadok_1:
                            rights = 1
                        elif right_4 in riadok_1:
                            rights = 1

                        if rights == 1:
                            print("ok")
                        else: err_here = 0
                    else: cislo_riadka += 1
            if err_here_second == 0: print(err)
            if err_here == 0: print("chyba prav")
        else: print(err)
        
    #zapis
    if user_input_splitted[0] == "zapis":
        error_state = False
        if user_input_len == 2:
            spravne = 0		
            cislo_riadka = 0
            rights = 0
            err_here = 1
            err_here_second = 0
            right_1 = 'rwx'
            right_2 = 'rw-'
            right_3 = '-wx'
            right_4 = '-w-'
            list_of_dirs = open("filesystem.txt","r")
            lines = list_of_dirs.readlines()
            list_of_dirs.close()
            checking_dir = dir + ":" + user_input_splitted[1] + ":"
            for riadok in lines:
                riadok_1 = riadok
                if checking_dir in riadok_1:
                    err_here_second = 1
                    if right_1 in riadok_1:
                        rights = 1
                    elif right_2 in riadok_1:
                        rights = 1
                    elif right_3 in riadok_1:
                        rights = 1
                    elif right_4 in riadok_1:
                        rights = 1

                    if rights == 1:
                        print("ok")
                    else: err_here = 0
                else: cislo_riadka += 1

            if err_here_second == 0: print(err)
            if err_here == 0: print("chyba prav")
        else: print(err)
    
    #chmod
    if user_input_splitted[0] == "chmod":
        error_state = False
        if user_input_len == 3:
            cislo_riadka = 0
            spravne = 1
            premennna = 0
            setting_right = "---"
            if user_input_splitted[1] == "7":
                setting_right = "rwx"
                spravne = 1
            elif user_input_splitted[1]=="6":
                setting_right = "rw-"
                spravne = 1
            elif user_input_splitted[1] == "5":
                setting_right = "r-x"
                spravne = 1
            elif user_input_splitted[1] == "4":
                setting_right = "r--"
                spravne = 1
            elif user_input_splitted[1] == "3":
                setting_right = "-wx"
                spravne = 1
            elif user_input_splitted[1] == "2":
                setting_right = "-w-"
                spravne = 1
            elif user_input_splitted[1] == "1":
                setting_right = "--x"
                spravne = 1
            

            if spravne == 1:
                list_of_dirs = open("filesystem.txt","r")
                lines = list_of_dirs.readlines()
                list_of_dirs.close()
                checking_dir = dir + ":" + user_input_splitted[2] + ":"

                for riadok in lines:
                    riadok_1 = riadok
                    if checking_dir in riadok_1:
                        riadokkk = riadok
                        lines = open("filesystem.txt",'r').readlines()
                        rozdelene = lines[cislo_riadka].split(':')
                        if len(rozdelene) == 4:
                            rozdelene[3] = setting_right + "\n"
                        else:
                            rozdelene[3] = setting_right
                        lines[cislo_riadka] = ':'.join(rozdelene)
                        vystup = open("filesystem.txt",'w')
                        vystup.writelines(lines)
                        vystup.close()
                        premennna = 1
                    else: cislo_riadka += 1

                list_of_dirs = open("directorysystem.txt", "r")
                cislo_riadka = 0
                lines = list_of_dirs.readlines()
                list_of_dirs.close()
                checking_dir = dir + user_input_splitted[2] + "/"

                for riadok in lines:
                    riadok_1 = riadok
                    if checking_dir in riadok_1:
                        riadokkk = riadok
                        lines = open("directorysystem.txt", 'r').readlines()
                        rozdelene = lines[cislo_riadka].split(':')
                        rozdelene[1] = setting_right + "\n"
                        lines[cislo_riadka] = ':'.join(rozdelene)
                        vystup = open("directorysystem.txt",'w')
                        vystup.writelines(lines)
                        vystup.close()
                        premennna = 1
                    else:cislo_riadka = cislo_riadka+1
                if premennna == 0: print(err)	
            else: print(err)
        else: print(err)
        
    #chown
    if user_input_splitted[0] == "chown":
        error_state = False
        if user_input_len == 3:
            cislo_riadka = 0
            spravne = 0
            premennna = 0
            list_of_dirs = open("filesystem.txt","r")
            lines = list_of_dirs.readlines()
            list_of_dirs.close()
            checking_dir = dir + ":" + user_input_splitted[2] + ":"

            for riadok in lines:
                riadok_1 = riadok
                if checking_dir in riadok_1:
                    riadokkk = riadok
                    lines = open("filesystem.txt", 'r').readlines()
                    rozdelene = lines[cislo_riadka].split(':')
                    rozdelene[2] = user_input_splitted[1]
                    lines[cislo_riadka] = ':'.join(rozdelene)
                    vystup = open("filesystem.txt",'w')
                    vystup.writelines(lines)
                    vystup.close()
                    premennna = 1
                else: cislo_riadka += 1
            if premennna == 0: print(err)
        else: print(err)
        
    dir = c_dir
    if error_state == True: print(err)