[简体中文](README.md) | [繁體中文](README.zh-TW.md) | [English](README.en.md) | [圖文網站](https://masterai-top.github.io/Texas-Holdem-Poker-Platform-Source-Code/zh-tw/)

# 德州撲克線上賽事平台原始碼

面向線上比賽、賽事報名和參賽權益兌換的德州撲克平台原始碼資料。倉庫包含 C++ 房間/牌桌邏輯、Tars 公共協議、MySQL/Protobuf 相依、Unity UI 元件、牌型動畫及真實產品畫面。

> 本倉庫是程式與資源集合，不代表可直接上線的完整客戶端、賽事後台或飯店預訂系統。請依實際程式與交付清單核驗。

## 產品功能與流程

- 賽事首頁和線上比賽入口。
- 比賽資訊、報名流程及參賽權益兌換畫面。
- 玩家登入、進入房間、入座、離線及離桌邏輯。
- 遊戲設定、開局檢查、莊家、回合計時與結束流程入口。
- Unity 滾動、音訊、牌型動畫、倒數與進度資源。

玩家流程：登入 → 瀏覽線上賽事 → 查看條件 → 報名或兌換權益 → 進入房間 → 服務端處理入座與開局 → 計時並廣播狀態 → 結束與清理。

## 產品截圖

| 賽事首頁 | 線上賽事 | 比賽報名 |
| --- | --- | --- |
| ![德州撲克賽事首頁](docs/assets/images/home.jpg) | ![線上德州比賽](docs/assets/images/online-events.jpg) | ![德州撲克比賽報名](docs/assets/images/registration.jpg) |

| 權益兌換 | 兌換詳情 | 勝率工具 |
| --- | --- | --- |
| ![賽事權益兌換](docs/assets/images/exchange-list.jpg) | ![賽事兌換詳情](docs/assets/images/exchange-detail.jpg) | ![德州撲克勝率計算器](docs/assets/images/odds.jpg) |

## 技術架構

服務端使用 C++ 與 Tars，引用 Protobuf、MySQL、WBL 和 RapidJSON；`core/` 包含房間與玩家流程，計時器處理遊戲階段。客戶端資源包含 Unity C# 元件及 PNG/Atlas/JSON 動畫。Makefile 依賴多個未包含的 `/home/tarsproto/XGame/` 公共模組，須補齊後才能建置。

## 聯絡與核驗

Telegram：[@xuzongbin001](https://t.me/xuzongbin001) · Email：masterai918@gmail.com

使用前請核對源碼範圍、第三方資源授權、公平性及當地法規。本倉庫不保證完整部署、收益或搜尋排名。

