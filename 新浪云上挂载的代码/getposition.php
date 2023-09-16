<?php
function create_table($db)
{
    //创建数据表并初始化
   $sql = "CREATE TABLE CarPos (
	id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
	position_x float(6) NOT NULL, 
	position_y float(6) NOT NULL,
	position_z float(6) NOT NULL,
    EulerRx float(6) NOT NULL,
    EulerRy float(6) NOT NULL,
    EulerRz float(6) NOT NULL,
	reg_date TIMESTAMP
	)";
	if ($db->query($sql) === TRUE) {
    	echo "Table velctrl created successfully\n";
    	for($i=1;$i<=2;$i++)
        {
            $sql="INSERT INTO CarPos (position_x,position_y,position_z,
            EulerRx,EulerRy,EulerRz) 
            VALUES 
            (0.0,0.0,0.0,0.0,0.0,0.0) ";
			if($db->query($sql)==TRUE)
			{
				echo "数据表为空，新建数据初始化完成\n";
			}
        }
        
	} else {
	    echo "数据表已存在，无需再创建（可以忽略此条信息）: " . $db->error."\n";
	}
    
}

function update_date($db,$pos_x,$pos_y,$pos_z,$EulerRx,$EulerRy,$EulerRz)
{
    $sql = "update CarPos set 
    	position_x=$pos_x,position_y=$pos_y,position_z=$pos_z,
    	EulerRx=$EulerRx,EulerRy=$EulerRy,EulerRz=$EulerRz
        where id=2";
    if ($db->query($sql) === TRUE) {
	    echo "新记录更新成功\n";
	} else {
	    echo "Error: " . $sql . "<br>" . $db->error;
	}
}

?>


<?php
// 连主库
echo "start!";
$hs = 'w.rdc.sae.sina.com.cn' . ':' . '3306';
$db = mysqli_connect($hs,'mlj1myy543','215wj14mlh03wylwzmhzl02lm02hyl4x3ywyz54h');

$position_x=(float)$_POST['position_x'];
$position_y=(float)$_POST['position_y'];
$position_z=(float)$_POST['position_z'];
$EulerRx=(float)$_POST['EulerRx'];
$EulerRy=(float)$_POST['EulerRy'];
$EulerRz=(float)$_POST['EulerRz'];

//$position_x=1.0;
//$position_y=2.0;
//$position_z=3.0;
//$EulerRx=4.0;
//$EulerRy=5.0;
//$EulerRz=6.0;


if ($db) {
	echo "连上了。";
    mysqli_select_db( $db,'app_garbagesorting');
    
    create_table($db);
    
    update_date($db,$position_x,$position_y,$position_z,$EulerRx,$EulerRy,$EulerRz);
}

mysqli_close($db);

?>

