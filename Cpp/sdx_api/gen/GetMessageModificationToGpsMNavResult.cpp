
#include "GetMessageModificationToGpsMNavResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGpsMNavResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGpsMNavResult::CmdName = "GetMessageModificationToGpsMNavResult";
    const char* const GetMessageModificationToGpsMNavResult::Documentation = "Result of GetMessageModificationToGpsMNav.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ ------------------------------------------------------------------------------------------------\n"
      "SignalArray      array string Array of signals to apply the message modification to, accepts \"L1ME\" and \"L2ME\" (empty for all)\n"
      "SvId             int          The satellite's SV ID 1..32 (use 0 to apply modification to all SVs)\n"
      "StartTime        int          Elapsed time in seconds since start of simulation\n"
      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "MessageType      int          MNAV Message type\n"
      "Occurrence       int          Occurrence number in message sequence (1 based, or use -1 to match any occurrence)\n"
      "Condition        string       Optional condition to match message content, ex: \"EQUAL(45, 10, 0x3f)\"\n"
      "BitModifications string       Comma separated bit modifications\n"
      "Id               string       Unique identifier automatically set by simulator";
    const char* const GetMessageModificationToGpsMNavResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGpsMNavResult);


    GetMessageModificationToGpsMNavResult::GetMessageModificationToGpsMNavResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetMessageModificationToGpsMNavResult::GetMessageModificationToGpsMNavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, int occurrence, const std::string& condition, const std::string& bitModifications, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setMessageType(messageType);
      setOccurrence(occurrence);
      setCondition(condition);
      setBitModifications(bitModifications);
      setId(id);
    }

    GetMessageModificationToGpsMNavResult::GetMessageModificationToGpsMNavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, int occurrence, const std::string& condition, const std::string& bitModifications, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setMessageType(messageType);
      setOccurrence(occurrence);
      setCondition(condition);
      setBitModifications(bitModifications);
      setId(id);
    }


    GetMessageModificationToGpsMNavResultPtr GetMessageModificationToGpsMNavResult::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, int occurrence, const std::string& condition, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGpsMNavResult>(signalArray, svId, startTime, stopTime, messageType, occurrence, condition, bitModifications, id);
    }

    GetMessageModificationToGpsMNavResultPtr GetMessageModificationToGpsMNavResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, int occurrence, const std::string& condition, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGpsMNavResult>(relatedCommand, signalArray, svId, startTime, stopTime, messageType, occurrence, condition, bitModifications, id);
    }

    GetMessageModificationToGpsMNavResultPtr GetMessageModificationToGpsMNavResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGpsMNavResult>(ptr);
    }

    bool GetMessageModificationToGpsMNavResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["MessageType"])
          && parse_json<int>::is_valid(m_values["Occurrence"])
          && parse_json<std::string>::is_valid(m_values["Condition"])
          && parse_json<std::string>::is_valid(m_values["BitModifications"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGpsMNavResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGpsMNavResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "MessageType", "Occurrence", "Condition", "BitModifications", "Id"}; 
      return names; 
    }


    std::vector<std::string> GetMessageModificationToGpsMNavResult::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetMessageModificationToGpsMNavResult::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGpsMNavResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetMessageModificationToGpsMNavResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGpsMNavResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetMessageModificationToGpsMNavResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGpsMNavResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetMessageModificationToGpsMNavResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGpsMNavResult::messageType() const
    {
      return parse_json<int>::parse(m_values["MessageType"]);
    }

    void GetMessageModificationToGpsMNavResult::setMessageType(int messageType)
    {
      m_values.AddMember("MessageType", parse_json<int>::format(messageType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGpsMNavResult::occurrence() const
    {
      return parse_json<int>::parse(m_values["Occurrence"]);
    }

    void GetMessageModificationToGpsMNavResult::setOccurrence(int occurrence)
    {
      m_values.AddMember("Occurrence", parse_json<int>::format(occurrence, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToGpsMNavResult::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetMessageModificationToGpsMNavResult::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToGpsMNavResult::bitModifications() const
    {
      return parse_json<std::string>::parse(m_values["BitModifications"]);
    }

    void GetMessageModificationToGpsMNavResult::setBitModifications(const std::string& bitModifications)
    {
      m_values.AddMember("BitModifications", parse_json<std::string>::format(bitModifications, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToGpsMNavResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGpsMNavResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
