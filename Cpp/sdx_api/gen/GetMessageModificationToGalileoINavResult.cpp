
#include "GetMessageModificationToGalileoINavResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGalileoINavResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGalileoINavResult::CmdName = "GetMessageModificationToGalileoINavResult";
    const char* const GetMessageModificationToGalileoINavResult::Documentation = "Result of GetMessageModificationToGalileoINav.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ ---------------------------------------------------------------------------------------------\n"
      "SignalArray      array string Array of signals to apply the message modification to, accepts \"E1\" and \"E5b\" (empty for all)\n"
      "SvId             int          The satellite's SV ID 1..36 (use 0 to apply modification to all SVs)\n"
      "StartTime        int          Elapsed time in seconds since start of simulation\n"
      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "Subframe         int          Subframe 1..24 (use 0 to apply modification to all subframes)\n"
      "Page             int          Page 1..15 (use 0 to apply modification to all pages)\n"
      "Condition        string       Optional condition to match message content, ex: \"EQUAL(45, 10, 0x3f)\"\n"
      "UpdateCRC        bool         Recalculate CRC after making modification\n"
      "BitModifications string       Comma separated bit modifications\n"
      "Id               string       Unique identifier of the event";
    const char* const GetMessageModificationToGalileoINavResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGalileoINavResult);


    GetMessageModificationToGalileoINavResult::GetMessageModificationToGalileoINavResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetMessageModificationToGalileoINavResult::GetMessageModificationToGalileoINavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setSubframe(subframe);
      setPage(page);
      setCondition(condition);
      setUpdateCRC(updateCRC);
      setBitModifications(bitModifications);
      setId(id);
    }

    GetMessageModificationToGalileoINavResult::GetMessageModificationToGalileoINavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setSubframe(subframe);
      setPage(page);
      setCondition(condition);
      setUpdateCRC(updateCRC);
      setBitModifications(bitModifications);
      setId(id);
    }


    GetMessageModificationToGalileoINavResultPtr GetMessageModificationToGalileoINavResult::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGalileoINavResult>(signalArray, svId, startTime, stopTime, subframe, page, condition, updateCRC, bitModifications, id);
    }

    GetMessageModificationToGalileoINavResultPtr GetMessageModificationToGalileoINavResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGalileoINavResult>(relatedCommand, signalArray, svId, startTime, stopTime, subframe, page, condition, updateCRC, bitModifications, id);
    }

    GetMessageModificationToGalileoINavResultPtr GetMessageModificationToGalileoINavResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGalileoINavResult>(ptr);
    }

    bool GetMessageModificationToGalileoINavResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["Subframe"])
          && parse_json<int>::is_valid(m_values["Page"])
          && parse_json<std::string>::is_valid(m_values["Condition"])
          && parse_json<bool>::is_valid(m_values["UpdateCRC"])
          && parse_json<std::string>::is_valid(m_values["BitModifications"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGalileoINavResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGalileoINavResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "Subframe", "Page", "Condition", "UpdateCRC", "BitModifications", "Id"}; 
      return names; 
    }


    std::vector<std::string> GetMessageModificationToGalileoINavResult::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetMessageModificationToGalileoINavResult::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGalileoINavResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetMessageModificationToGalileoINavResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGalileoINavResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetMessageModificationToGalileoINavResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGalileoINavResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetMessageModificationToGalileoINavResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGalileoINavResult::subframe() const
    {
      return parse_json<int>::parse(m_values["Subframe"]);
    }

    void GetMessageModificationToGalileoINavResult::setSubframe(int subframe)
    {
      m_values.AddMember("Subframe", parse_json<int>::format(subframe, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGalileoINavResult::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void GetMessageModificationToGalileoINavResult::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToGalileoINavResult::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetMessageModificationToGalileoINavResult::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetMessageModificationToGalileoINavResult::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetMessageModificationToGalileoINavResult::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToGalileoINavResult::bitModifications() const
    {
      return parse_json<std::string>::parse(m_values["BitModifications"]);
    }

    void GetMessageModificationToGalileoINavResult::setBitModifications(const std::string& bitModifications)
    {
      m_values.AddMember("BitModifications", parse_json<std::string>::format(bitModifications, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToGalileoINavResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGalileoINavResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
