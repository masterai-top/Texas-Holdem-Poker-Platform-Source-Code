#ifndef __ONLINE_INFO_USER_LIST_H__
#define __ONLINE_INFO_USER_LIST_H__
class OnlineInfoUserListRequest
{
    friend class OnlineInfoUserListResponse;
public:
    OnlineInfoUserListRequest() {}
    OnlineInfoUserListRequest(const string &json)
    {
        this->Deserialize(json);
    }
    template <typename Writer>
    void Serialize(Writer &writer) const
    {
        writer.StartObject();
        SERIALIZE_MEMBER(writer, iType);
        writer.EndObject();
    }

    void toString(std::string &json)
    {
        StringBuffer sb;
        Writer<StringBuffer> writer(sb);
        Serialize(writer);
        json = sb.GetString();
    }

    void Deserialize(const string &json)
    {
        try
        {
            Document d;
            if (d.Parse(json.c_str()).HasParseError())
            {
                throw logic_error("parse json error. raw data : " + json);
            }
            SET_DOC_MEMBER(d, iType);
        }
        catch (const std::exception &e)
        {
            std::string errInfo = ::toString(__FILE__, ":", __LINE__, ":OnlineInfoUserListRequest decode error!");
            throw logic_error(errInfo);
        }
    }

    static tars::Int32 handler(const vector<tars::Char> &reqBuf, const map<std::string, std::string> &extraInfo, vector<tars::Char> &rspBuf)
    {
        return 0;
    }

private:
    CInteger _iType;  //在线信息获取类型:1-真实玩家数量

};
class OnlineInfoUserListResponse
{
public:
    OnlineInfoUserListResponse() {}
    OnlineInfoUserListResponse(const string &json)
    {
        this->Deserialize(json);
    }
    template <typename Writer>
    void Serialize(Writer &writer) const
    {
        writer.StartObject();
        SERIALIZE_MEMBER(writer, iType);
        SERIALIZE_MEMBER(writer, iUserCount);
        writer.EndObject();
    }

    void toString(std::string &json)
    {
        StringBuffer sb;
        Writer<StringBuffer> writer(sb);
        Serialize(writer);
        json = sb.GetString();
    }

    void Deserialize(const string &json)
    {
        Document d;
        if (d.Parse(json.c_str()).HasParseError())
        {
            throw logic_error("parse json error. raw data : " + json);
        }
        SET_DOC_MEMBER(d, iType);
        SET_DOC_MEMBER(d, iUserCount);
    }

    static tars::Int32 handler(const vector<tars::Char> &reqBuf, const map<std::string, std::string> &extraInfo, vector<tars::Char> &rspBuf)
    {
        // STEP1 解码
        OnlineInfoUserListRequest request;
        decode(reqBuf, request);

        // STEP2 具体业务处理
        int32_t iUserCount = 0;
        int64_t resultCode = RESULT_CODE_SUCCESS;
        int iRet = g_app.getOuterFactoryPtr()->getPushServerPrx(request._iType)->onlineInfoUserList(request._iType, iUserCount);
        if (iRet != 0)
        {
            ROLLLOG_ERROR << "getPushServerPrx failed, iRet:" << iRet << ", request._iType:" << request._iType << endl;
            resultCode = RESULT_CODE_FAIL;
        }

        // STEP3 填充数据
        encode(resultCode, iUserCount, request, rspBuf);
        return 0;
    }

private:

    static void encode(int64_t resultCode, int32_t iUserCount, OnlineInfoUserListRequest &request, vector<tars::Char> &rspBuf)
    {
        OnlineInfoUserListResponse  response;
        response._iType.assign(request._iType);
        response._iUserCount.assign(iUserCount);

        // resultData是数组
        std::string json;
        response.toString(json);
        std::string resultData = "[" + json + "]";

        int64_t totalItems = 1;  //总条数
        int64_t totalPages = 1;  //总页数
        GMResponse rsp(resultCode, "", resultData, totalItems, totalPages);
        std::string resultJson;
        rsp.toString(resultJson);
        rspBuf.assign(resultJson.begin(), resultJson.end());
    }

private:
    CInteger _iType;     //在线信息获取类型:1-真实玩家数量
    CInteger _iUserCount;//真实玩家数量

};
#endif