
#include "GetMessageModificationToPulsarX1Result.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToPulsarX1Result
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToPulsarX1Result::CmdName = "GetMessageModificationToPulsarX1Result";
    const char* const GetMessageModificationToPulsarX1Result::Documentation = "Result of GetMessageModificationToPulsarX1.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ -----------------------------------------------------------------------------------------\n"
      "SignalArray      array string Array of signals to apply the message modification to, accepts \"PULSARX1\" (empty for all)\n"
      "SvId             int          The satellite's SV ID 1..258 (use 0 to apply modification to all SVs)\n"
      "StartTime        int          Elapsed time in seconds since start of simulation\n"
      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "MessageType      int          Message type (use -1 to apply modification to all message types)\n"
      "Condition        string       Optional condition to match message content, ex: \"EQUAL(45, 10, 0x3f)\"\n"
      "UpdateCRC        bool         Recalculate CRC after making modification\n"
      "BitModifications string       Comma separated bit modifications\n"
      "Id               string       Unique identifier of the event";
    const char* const GetMessageModificationToPulsarX1Result::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToPulsarX1Result);


    GetMessageModificationToPulsarX1Result::GetMessageModificationToPulsarX1Result()
      : CommandResult(CmdName, TargetId)
    {}

    GetMessageModificationToPulsarX1Result::GetMessageModificationToPulsarX1Result(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
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

    GetMessageModificationToPulsarX1Result::GetMessageModificationToPulsarX1Result(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
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


    GetMessageModificationToPulsarX1ResultPtr GetMessageModificationToPulsarX1Result::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToPulsarX1Result>(signalArray, svId, startTime, stopTime, messageType, condition, updateCRC, bitModifications, id);
    }

    GetMessageModificationToPulsarX1ResultPtr GetMessageModificationToPulsarX1Result::create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToPulsarX1Result>(relatedCommand, signalArray, svId, startTime, stopTime, messageType, condition, updateCRC, bitModifications, id);
    }

    GetMessageModificationToPulsarX1ResultPtr GetMessageModificationToPulsarX1Result::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToPulsarX1Result>(ptr);
    }

    bool GetMessageModificationToPulsarX1Result::isValid() const
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

    std::string GetMessageModificationToPulsarX1Result::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToPulsarX1Result::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "MessageType", "Condition", "UpdateCRC", "BitModifications", "Id"}; 
      return names; 
    }


    std::vector<std::string> GetMessageModificationToPulsarX1Result::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetMessageModificationToPulsarX1Result::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToPulsarX1Result::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetMessageModificationToPulsarX1Result::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToPulsarX1Result::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetMessageModificationToPulsarX1Result::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToPulsarX1Result::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetMessageModificationToPulsarX1Result::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToPulsarX1Result::messageType() const
    {
      return parse_json<int>::parse(m_values["MessageType"]);
    }

    void GetMessageModificationToPulsarX1Result::setMessageType(int messageType)
    {
      m_values.AddMember("MessageType", parse_json<int>::format(messageType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToPulsarX1Result::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetMessageModificationToPulsarX1Result::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetMessageModificationToPulsarX1Result::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetMessageModificationToPulsarX1Result::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToPulsarX1Result::bitModifications() const
    {
      return parse_json<std::string>::parse(m_values["BitModifications"]);
    }

    void GetMessageModificationToPulsarX1Result::setBitModifications(const std::string& bitModifications)
    {
      m_values.AddMember("BitModifications", parse_json<std::string>::format(bitModifications, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToPulsarX1Result::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToPulsarX1Result::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
