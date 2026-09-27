[简体中文](README.md) | [繁體中文](README.zh-TW.md) | [English](README.en.md) | [图文网站](https://masterai-top.github.io/Texas-Holdem-Poker-Platform-Source-Code/)

# 德州扑克线上赛事平台源码

面向线上比赛、赛事报名和参赛权益兑换的德州扑克平台源码资料。仓库包含 C++ 房间/牌桌逻辑入口、Tars 公共协议、MySQL/Protobuf 构建依赖、Unity UI 组件、牌型动画资源以及真实产品截图。

> 当前仓库是代码与资源集合，不代表可直接上线的完整客户端、赛事后台或酒店预订系统。功能、依赖、授权及合规要求应以实际代码和交付清单为准。

## 平台定位

项目围绕“赛事首页—线上比赛—查看报名—兑换参赛权益—进入牌桌”的用户路径组织界面，并提供入座、离线、离桌、开始游戏、计时器、庄家与结算等牌桌逻辑接口。它适合用于研究德州扑克线上赛事平台、资格赛入口和比赛客户端的技术组成。

## 产品功能

| 功能域 | 说明 | 仓库依据 |
| --- | --- | --- |
| 赛事首页 | 展示比赛内容和赛事入口 | `Screenshots/0首页 - 副本.jpg` |
| 线上赛事 | 浏览线上比赛与资格活动 | `Screenshots/0线上赛事.jpg` |
| 比赛报名 | 查看赛事信息并进入报名流程 | `Screenshots/报名.jpg` |
| 权益兑换 | 展示赛事权益列表与详情 | `Screenshots/兑换01.jpg`、`兑换02.jpg` |
| 牌桌流程 | 用户入座/离桌、游戏开始、计时器、庄家与结束流程 | `core/`、`game*.h`、`*timer.*` |
| 客户端表现 | 牌型动画、进度条、倒计时、滚动和音频组件 | PNG/Atlas/JSON、FancyScrollView、Eazy Sound Manager |

## 赛事和牌桌流程

1. 玩家登录并进入赛事首页。
2. 浏览线上比赛或资格赛入口。
3. 查看比赛条件、时间与报名信息。
4. 完成报名或兑换对应参赛权益。
5. 进入房间，由服务端处理配置、入座和游戏开始。
6. 计时器驱动回合阶段，服务端向客户端广播状态。
7. 比赛结束后清理牌桌状态并衔接战绩或赛事结果模块；完整赛事后台需按实际交付范围核验。

## 产品截图

| 赛事首页 | 线上赛事 | 比赛报名 |
| --- | --- | --- |
| ![德州扑克赛事平台首页](docs/assets/images/home.jpg) | ![德州扑克线上赛事](docs/assets/images/online-events.jpg) | ![德州扑克比赛报名](docs/assets/images/registration.jpg) |

| 权益兑换 | 兑换详情 | 胜率工具 |
| --- | --- | --- |
| ![赛事参赛权益兑换](docs/assets/images/exchange-list.jpg) | ![德州扑克赛事兑换详情](docs/assets/images/exchange-detail.jpg) | ![德州扑克胜率计算器](docs/assets/images/odds.jpg) |

## 技术结构

| 层级 | 可由仓库确认的内容 |
| --- | --- |
| 服务端 | C++ 游戏/房间逻辑、GMServer、用户状态与计时器 |
| 服务框架 | Tars Application、服务代理与 `.tars` 公共协议 |
| 通信 | Protobuf 生成消息引用与客户端/房间消息发送 |
| 数据 | Tars MySQL 客户端和配置读取 |
| 客户端资源 | Unity C# 组件、Atlas/JSON/PNG 动画与音频资源 |
| 辅助能力 | GeoLite2 IP 国家查询、SMTP/cURL、SHA1/HMAC 工具 |

## 代码导读

- `core/`：用户入座、离线、离桌、配置和游戏开始等房间逻辑。
- `begintimer.*`、`endtimer.*`、`xtimer.*`：回合及通用定时任务。
- `gamebanker.h`、`gameend.h`、`checkbegin.h`：庄家、结束和开局检查入口。
- `CommonStruct.tars`：请求动作、响应头和俱乐部/房间通知类型。
- `GMServer.*`：Tars 管理服务入口。
- `CardType` 及根目录 PNG/Atlas/JSON：牌型和界面动画资源。

## 构建说明

Makefile 目标为 `GMServer`，依赖 Tars、WBL、RapidJSON、Protobuf、MySQL，以及 `/home/tarsproto/XGame/` 下多个未随仓库包含的公共服务模块。因此不能把单独 `make` 当作完整部署步骤。请先完成依赖清单、配置、数据库与协议版本审计，再在隔离环境构建。

## 搜索定位

重点关键词：**德州扑克赛事平台源码、线上德州比赛源码、德州报名系统、资格赛平台、赛事权益兑换、Texas Holdem tournament platform、online poker event source**。不再使用没有代码证据的“酒店预订完整源码”和“直接上架”作为主描述。

## 联系与核验

Telegram：[@xuzongbin001](https://t.me/xuzongbin001) · Email：masterai918@gmail.com

使用前请核对演示、源码范围、第三方资源许可、支付或账户流程、公平性和当地法规。本仓库不构成并发、完整部署、收益或搜索排名承诺。

