
#include "GetMessageModificationToGpsLNavResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGpsLNavResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGpsLNavResult::CmdName = "GetMessageModificationToGpsLNavResult";
    const char* const GetMessageModificationToGpsLNavResult::Documentation = "Result of GetMessageModificationToGpsLNav.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ ------------------------------------------------------------------------------------------------------\n"
      "SignalArray      array string Array of signals to apply the message modification to, accepts \"L1CA\", \"L1P\" and \"L2P\" (empty for all)\n"
      "SvId             int          The satellite's SV ID 1..32 (use 0 to apply modification to all SVs)\n"
      "StartTime        int          Elapsed time in seconds since start of simulation\n"
      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "Subframe         int          Subframe 1..5 (use 0 to apply modification to all subframes)\n"
      "Page             int          Page 1..25 (use 0 to apply modification to all pages)\n"
      "Word             int          Word 1..10 (use 0 to apply modification to all words)\n"
      "UpdateParity     bool         Recalculate parity after making modification\n"
      "WordModification string       Modification string must be 30 bits long\n"
      "Id               string       Unique identifier of the event";
    const char* const GetMessageModificationToGpsLNavResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGpsLNavResult);


    GetMessageModificationToGpsLNavResult::GetMessageModificationToGpsLNavResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetMessageModificationToGpsLNavResult::GetMessageModificationToGpsLNavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setSubframe(subframe);
      setPage(page);
      setWord(word);
      setUpdateParity(updateParity);
      setWordModification(wordModification);
      setId(id);
    }

    GetMessageModificationToGpsLNavResult::GetMessageModificationToGpsLNavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setSubframe(subframe);
      setPage(page);
      setWord(word);
      setUpdateParity(updateParity);
      setWordModification(wordModification);
      setId(id);
    }


    GetMessageModificationToGpsLNavResultPtr GetMessageModificationToGpsLNavResult::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGpsLNavResult>(signalArray, svId, startTime, stopTime, subframe, page, word, updateParity, wordModification, id);
    }

    GetMessageModificationToGpsLNavResultPtr GetMessageModificationToGpsLNavResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGpsLNavResult>(relatedCommand, signalArray, svId, startTime, stopTime, subframe, page, word, updateParity, wordModification, id);
    }

    GetMessageModificationToGpsLNavResultPtr GetMessageModificationToGpsLNavResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGpsLNavResult>(ptr);
    }

    bool GetMessageModificationToGpsLNavResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["Subframe"])
          && parse_json<int>::is_valid(m_values["Page"])
          && parse_json<int>::is_valid(m_values["Word"])
          && parse_json<bool>::is_valid(m_values["UpdateParity"])
          && parse_json<std::string>::is_valid(m_values["WordModification"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGpsLNavResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGpsLNavResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "Subframe", "Page", "Word", "UpdateParity", "WordModification", "Id"}; 
      return names; 
    }


    std::vector<std::string> GetMessageModificationToGpsLNavResult::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetMessageModificationToGpsLNavResult::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGpsLNavResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetMessageModificationToGpsLNavResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGpsLNavResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetMessageModificationToGpsLNavResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGpsLNavResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetMessageModificationToGpsLNavResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGpsLNavResult::subframe() const
    {
      return parse_json<int>::parse(m_values["Subframe"]);
    }

    void GetMessageModificationToGpsLNavResult::setSubframe(int subframe)
    {
      m_values.AddMember("Subframe", parse_json<int>::format(subframe, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGpsLNavResult::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void GetMessageModificationToGpsLNavResult::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGpsLNavResult::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void GetMessageModificationToGpsLNavResult::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetMessageModificationToGpsLNavResult::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void GetMessageModificationToGpsLNavResult::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToGpsLNavResult::wordModification() const
    {
      return parse_json<std::string>::parse(m_values["WordModification"]);
    }

    void GetMessageModificationToGpsLNavResult::setWordModification(const std::string& wordModification)
    {
      m_values.AddMember("WordModification", parse_json<std::string>::format(wordModification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToGpsLNavResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGpsLNavResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
