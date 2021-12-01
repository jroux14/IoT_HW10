import sys

outputName = "output.txt"
out = []
if __name__ == "__main__":
        file1 = open(sys.argv[1], "r")
        file2 = open(sys.argv[2], "r")

        input1 = file1.read()
        input2 = file2.read()
        inputList1 = input1.split(" ")
        inputList2 = input2.split(" ")
        listLength1 = len(inputList1)
        listLength2 = len(inputList2)

        file1.close()
        file2.close()
        if listLength1 != listLength2:
            if listLength1 > listLength2:
                i = listLength1 - 1
                diff = listLength1 - listLength2
                while i >= 0:
                    if i >= diff:
                        out.append(inputList1[i])
                        out.append(inputList2[i-diff])
                        i-=1
                    else:
                        out.append(inputList1[i])
                        i-=1
                    print("Out list created")
            else:
                i = listLength2 - 1
                diff = listLength2 - listLength1
                while i >= 0:
                    if i >= diff:
                        out.append(inputList1[i-diff])
                        out.append(inputList2[i])
                        i-=1
                    else:
                        out.append(inputListi2[i])
                        i-=1
                    print("Out list created")
        else:
            print("Input files cannot be the same length.")

        outFile = open(outputName, "w")
        for string in out:
            outFile.write(string.strip() + " ")
        outFile.close()

        print("finished")
