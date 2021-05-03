#    模拟即可， 不必要写trie树
#    用python写的话，示例末尾有误导人的空行
#


while True:
    try:
        inp = input()
        commands = inp.split()
        if len(commands) == 1:
            if commands[0] in "reset":
                print("reset what")
            else:
                print("unknown command")
        elif len(commands) == 2:
            if commands[0] in "board" and commands[1] in "delete":
                print("no board at all")
                continue
            
            f1 = f2 = False
            if commands[0] in "reset" and commands[1] in "board":
                f1 = True
            if commands[0] in "reboot" and commands[1] in "backplane":
                f2 = True
            if f1 and f2:
                print("unknown command")
                continue
            elif f1:
                print("board fault")
                continue
            elif f2:
                print("impossible")
                continue
            
            f1 = f2 = False
            if commands[0] in "board" and commands[1] in "add":
                f1 = True
            if commands[0] in "backplane" and commands[1] in "abort":
                f2 = True
            if f1 and f2:
                print("unknown command")
                continue
            elif f1:
                print("where to add")
                continue
            elif f2:
                print("install first")
                continue
            print("unknown command")
            
        else:
            print("unknown command")
            
    except EOFError as e:
        break