rm -r result answer
mkdir result answer
cp -r /home/share/hw5/* answer/
echo 1 2 3 4 5 | xargs -n 1 > args
cat args | xargs -I {} bash -c "./hw5 answer/testcase{}/corpus_00{}.txt answer/testcase{}/query_00{}.txt > result/result{}"
cat args | xargs -I {} bash -c "diff answer/testcase{}/result_00{} result/result{}"
