
#include "GetMessageModificationToBeiDouCNav1Result.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToBeiDouCNav1Result
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToBeiDouCNav1Result::CmdName = "GetMessageModificationToBeiDouCNav1Result";
    const char* const GetMessageModificationToBeiDouCNav1Result::Documentation = "Result of GetMessageModificationToBeiDouCNav1.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ ------------------------------------------------------------------------------------\n"
      "SignalArray      array string Array of signals to apply the message modification to, accepts \"B1C\" (empty for all)\n"
      "SvId             int          The satellite's SV ID 1..35 (use 0 to apply modification to all SVs)\n"
      "StartTime        int          Elapsed time in seconds since start of simulation\n"
      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "Page             int          CNAV1 page (use 0 to apply modification to all pages)\n"
      "Condition        string       Optional condition to match message content, ex: \"EQUAL(45, 10, 0x3f)\"\n"
      "UpdateCRC        bool         Recalculate CRC after making modification\n"
      "BitModifications string       Comma separated bit modifications\n"
      "Id               string       Unique identifier of the event";
    const char* const GetMessageModificationToBeiDouCNav1Result::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToBeiDouCNav1Result);


    GetMessageModificationToBeiDouCNav1Result::GetMessageModificationToBeiDouCNav1Result()
      : CommandResult(CmdName, TargetId)
    {}

    GetMessageModificationToBeiDouCNav1Result::GetMessageModificationToBeiDouCNav1Result(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setPage(page);
      setCondition(condition);
      setUpdateCRC(updateCRC);
      setBitModifications(bitModifications);
      setId(id);
    }

    GetMessageModificationToBeiDouCNav1Result::GetMessageModificationToBeiDouCNav1Result(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setPage(page);
      setCondition(condition);
      setUpdateCRC(updateCRC);
      setBitModifications(bitModifications);
      setId(id);
    }


    GetMessageModificationToBeiDouCNav1ResultPtr GetMessageModificationToBeiDouCNav1Result::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouCNav1Result>(signalArray, svId, startTime, stopTime, page, condition, updateCRC, bitModifications, id);
    }

    GetMessageModificationToBeiDouCNav1ResultPtr GetMessageModificationToBeiDouCNav1Result::create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouCNav1Result>(relatedCommand, signalArray, svId, startTime, stopTime, page, condition, updateCRC, bitModifications, id);
    }

    GetMessageModificationToBeiDouCNav1ResultPtr GetMessageModificationToBeiDouCNav1Result::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToBeiDouCNav1Result>(ptr);
    }

    bool GetMessageModificationToBeiDouCNav1Result::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["Page"])
          && parse_json<std::string>::is_valid(m_values["Condition"])
          && parse_json<bool>::is_valid(m_values["UpdateCRC"])
          && parse_json<std::string>::is_valid(m_values["BitModifications"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToBeiDouCNav1Result::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToBeiDouCNav1Result::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "Page", "Condition", "UpdateCRC", "BitModifications", "Id"}; 
      return names; 
    }


    std::vector<std::string> GetMessageModificationToBeiDouCNav1Result::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetMessageModificationToBeiDouCNav1Result::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav1Result::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetMessageModificationToBeiDouCNav1Result::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav1Result::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetMessageModificationToBeiDouCNav1Result::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav1Result::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetMessageModificationToBeiDouCNav1Result::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouCNav1Result::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void GetMessageModificationToBeiDouCNav1Result::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToBeiDouCNav1Result::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetMessageModificationToBeiDouCNav1Result::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetMessageModificationToBeiDouCNav1Result::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetMessageModificationToBeiDouCNav1Result::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToBeiDouCNav1Result::bitModifications() const
    {
      return parse_json<std::string>::parse(m_values["BitModifications"]);
    }

    void GetMessageModificationToBeiDouCNav1Result::setBitModifications(const std::string& bitModifications)
    {
      m_values.AddMember("BitModifications", parse_json<std::string>::format(bitModifications, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToBeiDouCNav1Result::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToBeiDouCNav1Result::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
