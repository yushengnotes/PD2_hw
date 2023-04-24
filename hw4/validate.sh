rm -r result answer 
mkdir answer result 
cp /home/share/hw4/* answer/ 
echo 1 2 3 4| xargs -n 1 > args
cat args | xargs -I {} bash -c "./hw4 answer /hw4_test{}.csv > result/answer_{}" 
cat args I xargs -I {} bash -C "diff answer/result_{} result/answer_
{}"
