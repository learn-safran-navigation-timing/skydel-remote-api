
#include "GetMessageModificationToBeiDouCNav2Result.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToBeiDouCNav2Result
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToBeiDouCNav2Result::CmdName = "GetMessageModificationToBeiDouCNav2Result";
    const char* const GetMessageModificationToBeiDouCNav2Result::Documentation = "Result of GetMessageModificationToBeiDouCNav2.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ ------------------------------------------------------------------------------------\n"
      "SignalArray      array string Array of signals to apply the message modification to, accepts \"B2a\" (empty for all)\n"
      "SvId             int          The satellite's SV ID 1..35 (use 0 to apply modification to all SVs)\n"
      "StartTime        int          Elapsed time in seconds since start of simulation\n"
      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "MessageType      int          CNAV2 Message type (use 0 to apply modification to all message types)\n"
      "Condition        string       Optional condition to match message content, ex: \"EQUAL(45, 10, 0x3f)\"\n"
      "UpdateCRC        bool         Recalculate CRC after making modification\n"
      "BitModifications string       Comma separated bit modifications\n"
      "Id               string       Unique identifier of the event";
    const char* const GetMessageModificationToBeiDouCNav2Result::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToBeiDouCNav2Result);


    GetMessageModificationToBeiDouCNav2Result::GetMessageModificationToBeiDouCNav2Result()
      : CommandResult(CmdName, TargetId)
    {}

    GetMessageModificationToBeiDouCNav2Result::GetMessageModificationToBeiDouCNav2Result(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
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

    GetMessageModificationToBeiDouCNav2Result::GetMessageModificationToBeiDouCNav2Result(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
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


    GetMessageModificationToBeiDouCNav2ResultPtr GetMessageModificationToBeiDouCNav2Result::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouCNav2Result>(signalArray, svId, startTime, stopTime, messageType, condition, updateCRC, bitModifications, id);
    }

    GetMessageModificationToBeiDouCNav2ResultPtr GetMessageModificationToBeiDouCNav2Result::create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouCNav2Result>(relatedCommand, signalArray, svId, startTime, stopTime, messageType, condition, updateCRC, bitModifications, id);
    }

    GetMessageModificationToBeiDouCNav2ResultPtr GetMessageModificationToBeiDouCNav2Result::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToBeiDouCNav2Result>(ptr);
    }

    bool GetMessageModificationToBeiDouCNav2Result::isValid() const
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

    std::string GetMessageModificationToBeiDouCNav2Result::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToBeiDouCNav2Result::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "MessageType", "Condition", "UpdateCRC", "BitModifications", "Id"}; 
      return names; 
    }


    std::vector<std::string> GetMessageModificationToBeiDouCNav2Result::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetMessageModificationToBeiDouCNav2Result::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav2Result::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetMessageModificationToBeiDouCNav2Result::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav2Result::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetMessageModificationToBeiDouCNav2Result::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav2Result::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetMessageModificationToBeiDouCNav2Result::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav2Result::messageType() const
    {
      return parse_json<int>::parse(m_values["MessageType"]);
    }

    void GetMessageModificationToBeiDouCNav2Result::setMessageType(int messageType)
    {
      m_values.AddMember("MessageType", parse_json<int>::format(messageType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToBeiDouCNav2Result::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetMessageModificationToBeiDouCNav2Result::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetMessageModificationToBeiDouCNav2Result::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetMessageModificationToBeiDouCNav2Result::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToBeiDouCNav2Result::bitModifications() const
    {
      return parse_json<std::string>::parse(m_values["BitModifications"]);
    }

    void GetMessageModificationToBeiDouCNav2Result::setBitModifications(const std::string& bitModifications)
    {
      m_values.AddMember("BitModifications", parse_json<std::string>::format(bitModifications, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToBeiDouCNav2Result::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToBeiDouCNav2Result::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
