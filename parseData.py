from os import listdir
from os.path import join, realpath, dirname
import sys
from time import mktime, strptime


CHUNKS = 50

def main():
    files = listdir(join(dirname(realpath(__file__)), "data"))
    fileOutName = "parsed.data"
    minStartTime = getMinStartTime(files)
    maxEndTime = getMaxEndTime(files)
    print(minStartTime, maxEndTime)
    for chunkNo in range(CHUNKS):
        writeLines(CHUNKS, chunkNo, minStartTime, maxEndTime, files)


def getMinStartTime(files):
    curMin = float('inf')
    for filename in files:
        realFileName = join(dirname(realpath(__file__)), "data", filename)
        fIn = open(realFileName, "r")
        fIn.readline()
        line = fIn.readline()
        lineSplit = line.split(",")
        date = lineSplit[2]
        time = lineSplit[3]

        year = date[:4]
        month = date[4:6]
        day = date[6:]
        hour = time[:2]
        minute = time[2:4]
        timeString = "{0}.{1}.{2} {3}:{4}:00".format(day, month, year, hour, minute);
        epochTime = int(mktime(strptime(timeString, "%d.%m.%Y %H:%M:%S")))
        if epochTime < curMin:
            curMin = epochTime
    return curMin

def getMaxEndTime(files):
    curMax = 0
    for filename in files:
        realFileName = join(dirname(realpath(__file__)), "data", filename)
        fIn = open(realFileName, "r")
        prevLine = ""
        for line in fIn:
            prevLine = line
        line = prevLine
        lineSplit = line.split(",")
        date = lineSplit[2]
        time = lineSplit[3]

        year = date[:4]
        month = date[4:6]
        day = date[6:]
        hour = time[:2]
        minute = time[2:4]
        timeString = "{0}.{1}.{2} {3}:{4}:00".format(day, month, year, hour, minute);
        epochTime = int(mktime(strptime(timeString, "%d.%m.%Y %H:%M:%S")))
        if epochTime > curMax:
            curMax = epochTime
    return curMax


def writeLines(chunks, chunkNo, minStartTime, maxEndTime, files):
    fOut = open("chunk{0}.data".format(chunkNo), "w")
    lines = {}
    chunkSize = (maxEndTime - minStartTime) // chunks
    minTime = minStartTime + chunkNo * chunkSize
    maxTime = minTime + chunkSize
    for filename in files:
        realFileName = join(dirname(realpath(__file__)), "data", filename)
        fIn = open(realFileName, "r")
        fIn.readline()
        for line in fIn:
            lineSplit = line.split(",")
            name = filename
            date = lineSplit[2]
            time = lineSplit[3]
            close = lineSplit[7]

            year = date[:4]
            month = date[4:6]
            day = date[6:]
            hour = time[:2]
            minute = time[2:4]
            timeString = "{0}.{1}.{2} {3}:{4}:00".format(day, month, year, hour, minute);
            epochTime = int(mktime(strptime(timeString, "%d.%m.%Y %H:%M:%S")))

            if epochTime < minTime:
                continue

            elif epochTime > maxTime:
                break

            if epochTime not in lines:
                lines[epochTime] = []
            lines[epochTime].append(name + ":" + close)
        fIn.close()

    keys = sorted(lines.keys())
    for time in keys:
        line = str(time) + "," + ",".join(lines[time]) + "\n"
        fOut.write(line)

    fOut.close()

if __name__ == "__main__":
    main()
