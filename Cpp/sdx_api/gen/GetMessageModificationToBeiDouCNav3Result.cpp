
#include "GetMessageModificationToBeiDouCNav3Result.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToBeiDouCNav3Result
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToBeiDouCNav3Result::CmdName = "GetMessageModificationToBeiDouCNav3Result";
    const char* const GetMessageModificationToBeiDouCNav3Result::Documentation = "Result of GetMessageModificationToBeiDouCNav3.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ ------------------------------------------------------------------------------------\n"
      "SignalArray      array string Array of signals to apply the message modification to, accepts \"B2b\" (empty for all)\n"
      "SvId             int          The satellite's SV ID 1..63 (use 0 to apply modification to all SVs)\n"
      "StartTime        int          Elapsed time in seconds since start of simulation\n"
      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "MessageType      int          CNAV3 Message type (use 0 to apply modification to all message types)\n"
      "Condition        string       Optional condition to match message content, ex: \"EQUAL(45, 10, 0x3f)\"\n"
      "UpdateCRC        bool         Recalculate CRC after making modification\n"
      "BitModifications string       Comma separated bit modifications\n"
      "Id               string       Unique identifier of the event";
    const char* const GetMessageModificationToBeiDouCNav3Result::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToBeiDouCNav3Result);


    GetMessageModificationToBeiDouCNav3Result::GetMessageModificationToBeiDouCNav3Result()
      : CommandResult(CmdName, TargetId)
    {}

    GetMessageModificationToBeiDouCNav3Result::GetMessageModificationToBeiDouCNav3Result(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setMessageType(messageType);
      setCondition(condition);
      setUpdateCRC(updateCRC);
      setBitModifications(bitModifications);
      setId(id);
    }

    GetMessageModificationToBeiDouCNav3Result::GetMessageModificationToBeiDouCNav3Result(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setMessageType(messageType);
      setCondition(condition);
      setUpdateCRC(updateCRC);
      setBitModifications(bitModifications);
      setId(id);
    }


    GetMessageModificationToBeiDouCNav3ResultPtr GetMessageModificationToBeiDouCNav3Result::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouCNav3Result>(signalArray, svId, startTime, stopTime, messageType, condition, updateCRC, bitModifications, id);
    }

    GetMessageModificationToBeiDouCNav3ResultPtr GetMessageModificationToBeiDouCNav3Result::create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouCNav3Result>(relatedCommand, signalArray, svId, startTime, stopTime, messageType, condition, updateCRC, bitModifications, id);
    }

    GetMessageModificationToBeiDouCNav3ResultPtr GetMessageModificationToBeiDouCNav3Result::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToBeiDouCNav3Result>(ptr);
    }

    bool GetMessageModificationToBeiDouCNav3Result::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["MessageType"])
          && parse_json<std::string>::is_valid(m_values["Condition"])
          && parse_json<bool>::is_valid(m_values["UpdateCRC"])
          && parse_json<std::string>::is_valid(m_values["BitModifications"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToBeiDouCNav3Result::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToBeiDouCNav3Result::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "MessageType", "Condition", "UpdateCRC", "BitModifications", "Id"}; 
      return names; 
    }


    std::vector<std::string> GetMessageModificationToBeiDouCNav3Result::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetMessageModificationToBeiDouCNav3Result::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav3Result::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetMessageModificationToBeiDouCNav3Result::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav3Result::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetMessageModificationToBeiDouCNav3Result::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav3Result::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetMessageModificationToBeiDouCNav3Result::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav3Result::messageType() const
    {
      return parse_json<int>::parse(m_values["MessageType"]);
    }

    void GetMessageModificationToBeiDouCNav3Result::setMessageType(int messageType)
    {
      m_values.AddMember("MessageType", parse_json<int>::format(messageType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToBeiDouCNav3Result::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetMessageModificationToBeiDouCNav3Result::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetMessageModificationToBeiDouCNav3Result::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetMessageModificationToBeiDouCNav3Result::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToBeiDouCNav3Result::bitModifications() const
    {
      return parse_json<std::string>::parse(m_values["BitModifications"]);
    }

    void GetMessageModificationToBeiDouCNav3Result::setBitModifications(const std::string& bitModifications)
    {
      m_values.AddMember("BitModifications", parse_json<std::string>::format(bitModifications, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToBeiDouCNav3Result::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToBeiDouCNav3Result::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
