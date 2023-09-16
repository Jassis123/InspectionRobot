<?php
	function str2num($data){
		if(is_string($data))
		{
			echo "begin to revert\n";
			return (float)$data;
		}
		else echo "no useful";
		return ;
	}
?>

<?php
// author:ljs
# time:2021.3.6

$hs = '127.0.0.1' . ':' . '3306';
$db = mysqli_connect($hs,'ljs') OR die("don't connect");
if($db) echo "connet!";
$sqldata = "show databases";
$result = array($db->query($sqldata));
foreach ($result as $value) {
	echo $value;
}


echo "start!\n";
$data=str2num("123456");
echo $data;
$data2=& $data;
$data2="test";
echo $data,' ',$data2;

list($a,$b,$c)=[1,2,3];
echo $a.' ',$b,' ',$c,'\n';

echo round(2.213143,2);
// $datas=fgets(STDIN);

// echo $data."123\n";
// class example{
// 	private $a;
// 	function setnum($num){
// 		$this->a=$num;
// 		echo "chr:".$num;
// 	}
// };

// $tt=new example;
// $tt->setnum(5);
// delete($tt);

?>