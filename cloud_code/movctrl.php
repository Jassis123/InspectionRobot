<?php
function create_table($db)
{
    //创建数据表并初始化
    $sql = "CREATE TABLE velctrl (
	id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
    status int(6) NOT NULL,
	movpos int(6) NOT NULL, 
	total int(6) NOT NULL,
	deltatime float ,
	reg_date TIMESTAMP 
	) ";
	if ($db->query($sql) === TRUE) {
    	//echo "Table velctrl created successfully\n";
    	for($i=1;$i<=4;$i++)
        {
            $sql="INSERT INTO velctrl (status,movpos,total) VALUES(0,0,0) ";
			if($db->query($sql)==TRUE)
			{
				;//echo "数据表为空，新建数据初始化完成\n";
			}
        }
        
	} else {
	    echo "数据表已存在，无需再创建（可以忽略此条信息）: " . $db->error."\n";
	}
}

function update_date($db,$data)
{
    $sql = "update velctrl set status=$data,movpos=$data,total=total+1  where id=$data";
    if ($db->query($sql) === TRUE) {
	    ;//echo "新记录更新成功\n";
	} else {
	    echo "Error: " . $sql . "<br>" . $db->error;
	}
    //修改所有当前状态
    $sql = "update velctrl set status=$data";
    $db->query($sql);
}
?>

<?php

// 连主库
$hs = 'w.rdc.sae.sina.com.cn' . ':' . '3306';
$db = mysqli_connect($hs,'mlj1myy543','215wj14mlh03wylwzmhzl02lm02hyl4x3ywyz54h');

// 连从库
// $db = mysql_connect(SAE_MYSQL_HOST_S.':'.SAE_MYSQL_PORT,SAE_MYSQL_USER,SAE_MYSQL_PASS);


$data=(int)$_POST['movpos'];
//$data=2;
if ($db) {
	echo "连上了。";
	// mysqli_get_server_version() ;
    mysqli_select_db( $db,'app_garbagesorting');
    
    //创建数据表并初始化,创建四条数据（数据表已存在就可以不再需要这句了）
    //create_table($db);
    
    //更新数据
    update_date($db,$data);
    
    //设置total最大值，total>5000重新计数
    $sqldata = "SELECT id,movpos,total FROM velctrl";
	$result = $db->query($sqldata);
    while($row = $result->fetch_assoc()) 
    {
        if($row["movpos"]>5000)
        {
            $i=$row['id'];
            $sql = "update velctrl set total=0  where id=$i" ;
        	$db->query($sql);
        }
    }
    

}
	mysqli_close($db);

?>