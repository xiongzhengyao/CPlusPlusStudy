check_time() {
    while true; do
        # 获取当前小时
        current_hour=$(date +%H)
        
        # 转换为数字进行比较
        hour_num=$((10#$current_hour))
        
        # 判断是否在3点到20点之间
        if [ $hour_num -ge 3 ] && [ $hour_num -lt 20 ]; then
            # 在指定时间范围内,退出循环
            break
        else
            # 不在时间范围内,等待1分钟后重试
            echo "当前时间 $(date +%H:%M) 不在执行时间范围内(03:00-20:00),等待中..."
            sleep 60
        fi
    done
    
    echo "当前时间 $(date +%H:%M) 在执行时间范围内,继续执行..."
}

check_time