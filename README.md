# Plants vs Zombies 2 Remake

Demo game: https://youtu.be/EblWeJ6Xlm0

## Giới thiệu
Plants vs Zombies 2 Remake lấy ý tưởng từ Plants vs. Zombies 2 (PopCap/EA), được xây dựng bằng thư viện SDL2, tương thích với các thiết bị máy tính để bàn (thay vì chỉ tương thích với các thiết bị di động như bản gốc). Plants vs Zombies 2 Remake thuộc thể loại tower defense, người chơi phải chiến đấu với zombie bằng cách trồng các loại cây trên sân.

## Hướng dẫn tải

Tải game được nén thành zip ở https://github.com/Strkss/PvZ2_Remake/releases  
Giải nén và ấn vào file exe để chạy.  

**Lưu ý:** Do được phát triển trên Microsoft Visual Studio nên game cần Microsoft Visual C++ Redistributable để chạy https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170

## Hướng dẫn chơi

Khi bắt đầu chạy, game sẽ hiện màn hình chờ, ấn chuột để được chuyển đến World Map (Bản đồ thế giới).

![image](https://github.com/user-attachments/assets/a5ef7cf5-41e0-42ad-8fca-98735a45d43a)

World Map là nơi có thể chọn level (màn chơi). Có tổng cộng 5 level với độ khó tăng dần. Để chọn level, chỉ cần ấn chuột vào một trong các ô level đã được đánh số. Ngoài ra trong World Map còn có nút Exit để người chơi thoát game.

![{78F14C0B-108E-4749-ACE3-B7C6C8746425}](https://github.com/user-attachments/assets/3fadfab3-278a-4b6e-9af7-81c80c419951)

Đây là bố cục cơ bản của một level:

![{0FC61A65-F566-45B3-91A7-1303348AF416}](https://github.com/user-attachments/assets/992938b4-d4b8-40f0-8fda-c1552e523824)

Các thành phần của một level:

- Tên level: Cho biết tên level hiện tại đang chơi.  
![{7750A38B-59B3-4C1B-B857-3D205AF9E134}](https://github.com/user-attachments/assets/789dc2f6-6796-4c57-b78b-03278f02da5b)

- Progress bar (thanh tiến trình): Cho biết tiến trình người chơi trong level, thời điểm và số cuộc tấn công lớn của zombie (kí hiệu bằng lá cờ).  
![{6E9C3509-0B40-4342-B087-3725E1AD1219}](https://github.com/user-attachments/assets/ce47fb52-c764-4244-9914-37e80edf3e2f)

- Sun (mặt trời) và sun counter (bộ đếm mặt trời): Sun là đơn vị tiền tệ chính trong game, sử dụng sun để mua và trồng cây trên sân. Để thu thập sun, chỉ cần click chuột vào nó. Sun counter cho biết số lượng sun người chơi hiện có.  
![{A3D8C4E7-A1BE-46C4-9D7E-FFDBFA696DF0}](https://github.com/user-attachments/assets/4ab0fff0-bdd0-48bf-a604-62c57cafb086)

- Seed packet (hạt giống cây): Cho biết số loại cây có thể trồng trên sân và giá của chúng. Ấn phím 1, 2, 3, 4 để chọn cây rồi nhấp chuột vào một ô bất kì trên sân để trồng loại cây tương ứng. Seed packet sau khi được mua sẽ ở trạng thái nghỉ, cần đợi một lúc để mua tiếp.  
![{21B19CEB-29AF-438B-9662-766EA5602158}](https://github.com/user-attachments/assets/1c44f255-a8b0-4353-8b11-222d017c3009)

- Shovel (xẻng): Dùng để xóa đi một cây trên sân. Ấn phím Q rồi nhấp chuột vào cây muốn xóa.  
![{40A24040-F02F-4D23-B725-9B6B59A660F4}](https://github.com/user-attachments/assets/664cef84-52c9-494a-bc38-ca7859ec3d8e)

- Lawn (sân cỏ): Là khu vực người chơi trồng cây bảo vệ ngôi nhà đằng sau khỏi sự tấn công của zombie.
![{92497652-A409-4702-BC7D-D34FEC410381}](https://github.com/user-attachments/assets/cd6d3695-25b7-47aa-aa41-26d588b969c7)

- Pause menu (màn hình dừng): Được kích hoạt khi ấn phím Escape, sẽ tạm dừng toàn bộ level. Tại đây người chơi có thể chỉnh âm lượng, tiếp tục hoặc thoát level.  
![{AC12FB68-6750-4787-AA8A-EC8C19522F86}](https://github.com/user-attachments/assets/d47962f3-fc3a-4890-b2af-b982bd11c0d3)

Nếu thành công tiêu diệt tất cả zombie trong level, người chơi sẽ thắng cuộc.  
![{F0B18C15-AA3D-4BB2-8FE9-0D66554743E0}](https://github.com/user-attachments/assets/4f60355f-8874-41bc-9591-6ec5eae1f8f0)

Ngược lại, nếu zombie thành công vượt qua sân cỏ và tiến đến ngôi nhà, người chơi sẽ thua cuộc.  
![{B6EB914C-3E90-407C-97EF-EC1EA195995D}](https://github.com/user-attachments/assets/57732070-f663-4f88-b531-a6c44e6cd287)

## Các loại cây và zombie

### Các loại cây

Peashooter: Bắn ra hạt đậu để tấn công zombie trước mặt.  
![Peashooter2](https://github.com/user-attachments/assets/d5884b43-fce8-4e02-8b83-8aad96f2ce8a)  

Sunflower: Tạo ra sun sau một khoảng thời gian nhất định.  
![Sunflower2](https://github.com/user-attachments/assets/e27bbb22-9686-41ab-b691-8736a89f93c6)  

Wall-nut: Có vỏ ngoài rất cứng, chịu được nhiều nhát cắn của zombie.  
![Wall-nut2](https://github.com/user-attachments/assets/a3767d64-3006-472e-9caf-a2ae7df080c0)

Potato Mine: Ngay lập tức phát nổ và tiêu diệt zombie nếu chúng đến gần nhưng cần thời gian để chuẩn bị.  
![Potato_Mine2](https://github.com/user-attachments/assets/a157aee8-c814-49f7-b9da-d3c9077a9746)

### Các loại zombie

Zombie luôn tiến về phía ngôi nhà, có thể ăn cây nếu cây đó chặn đường.

Basic Zombie: Lượng HP thấp.  
![Basic_Zombie2](https://github.com/user-attachments/assets/b669cae5-0556-467c-84c1-3bc1f64db02c)

Conehead Zombie: Do đội cọc tiêu nên có lượng HP gấp 3 lần Basic Zombie.  
![Conehead_Zombie2](https://github.com/user-attachments/assets/cb4dfc93-58bc-4b3d-b1b5-b751052c39a4)

Buckethead Zombie: Do đội xô sắt nên có lượng HP gấp gần 7 lần Basic Zombie.   
![Buckethead_Zombie2](https://github.com/user-attachments/assets/feefdfd2-4509-4ea7-8c25-f8ceda6927f3)

Flag Zombie: Lượng HP thấp, tuy nhiên sự xuất hiện của Flag Zombie báo hiệu một cuộc tấn công lớn của zombie.   
![Flag_Zombie2](https://github.com/user-attachments/assets/dbfe8963-6757-4a1b-83ef-5756a544cb0d)

## Đồ họa và âm thanh

### Đồ họa
Đồ họa của game được lấy trực tiếp hoặc được tạo gián tiếp từ các tài nguyên trong game Plants vs. Zombies 2 (PopCap/EA). Toàn bộ các bước giải nén đều sử dụng [Sen Environment](https://github.com/harumazzz/Sen.Environment). Các file đồ họa của game được lấy như sau:
- Animation của cây và zombie: Tham khảo https://www.youtube.com/watch?v=fSXOXuL7sUo
- UI, Etc, Lawn và SeedPacket: Giải nén file `UI_AlwaysLoaded.scg`,  `DelayLoad_Background_Modern_Compressed.scg` và `UI_SeedPackets.scg`.
- Font: Tải ở https://plantsvszombies.fandom.com/f/p/2519622733529499385
- Các file `worldmap.png`, `pausemenu.png`, `sun_counter.png` được tạo sử dụng [GIMP](https://www.gimp.org/) với các tài nguyên có từ việc giải nén ở trên.

### Âm thanh
Âm thanh của game được tải từ nhiều nguồn khác nhau trên internet:
- Âm nhạc của game được tải ở https://plantsvszombies.fandom.com/wiki/Music
- Hiệu ứng âm thanh của game được tải ở:
  -  https://plantsvszombies.fandom.com/wiki/Zombie_(PvZ)
  -  https://plantsvszombies.fandom.com/wiki/Headwear
  -  https://plantsvszombies.fandom.com/wiki/Pea
  -  https://plantsvszombies.fandom.com/wiki/Sun
  -  https://plantsvszombies.fandom.com/wiki/Potato_Mine_(PvZ2)
  -  https://plantsvszombies.fandom.com/wiki/Plants_(PvZ)

## Cấu trúc project

