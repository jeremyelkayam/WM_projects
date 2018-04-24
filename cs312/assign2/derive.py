import sys
#Jeremy Elkayam

argv=sys.argv
dict={}
worklist=[]
max_len=3

if len(argv)==3:
    if argv[1][0:2]!="-l":
        raise Exception("Length argument must begin with -l")
    max_len=int(argv[1][2:])
    filename=argv[2]
elif len(argv)==2:
    filename=argv[1]
else:
    raise Exception("Illegal # of arguments")

first_line=True
for line in open(filename,'r'):
    line=line.split()
    if first_line:
        worklist.append(line[0])
        first_line=False

    s=''
    if len(line)>3:
        for z in line[2:]:
            s+=z+" "
        s=s[:-1]
    else:
        s=line[2]
            
        
    if line[0] not in dict:
        dict[line[0]]=[s]
    else:
        dict[line[0]].append(s)
printed=[]
while len(worklist)!=0:
    s=worklist.pop(0)
    s_str=s[:]
    s=s.split()
    sting=''
    if(len(s)>max_len):
        continue
    z=0
    while z < len(s):
        if s[z] not in dict:
            sting += s[z] + ' '
            z += 1
            if z == len(s):
                if sting not in printed:
                    print(sting)
                    printed.append(sting)
        elif s[z] in dict:
            for g in dict[s[z]]:
                stong = sting + g + ' '
    
                # append list's elements to string
                for b in range(z + 1, len(s)):
    
                    stong += s[b] + ' '
    
                # append string to worklist
                worklist.append(stong)
    
            break
        
