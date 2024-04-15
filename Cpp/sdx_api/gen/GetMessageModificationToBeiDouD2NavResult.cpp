
#include "GetMessageModificationToBeiDouD2NavResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToBeiDouD2NavResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToBeiDouD2NavResult::CmdName = "GetMessageModificationToBeiDouD2NavResult";
    const char* const GetMessageModificationToBeiDouD2NavResult::Documentation = "Result of GetMessageModificationToBeiDouD2Nav.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ ---------------------------------------------------------------------------------------------------\n"
      "SignalArray      array string Array of signals to apply the message modification to, accepts \"B1\", \"B2\" and \"B3I\" (empty for all)\n"
      "SvId             int          The satellite's SV ID 1..35 (use 0 to apply modification to all SVs)\n"
      "StartTime        int          Elapsed time in seconds since start of simulation\n"
      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "Subframe         int          Subframe 1..5 (use 0 to apply modification to all subframes)\n"
      "Page             int          Page 1..120 (use 0 to apply modification to all pages)\n"
      "Word             int          Word 1..10 (use 0 to apply modification to all words)\n"
      "UpdateParity     bool         Recalculate parity after making modification\n"
      "WordModification string       Modification string must be 30 bits long\n"
      "Id               string       Unique identifier of the event";
    const char* const GetMessageModificationToBeiDouD2NavResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToBeiDouD2NavResult);


    GetMessageModificationToBeiDouD2NavResult::GetMessageModificationToBeiDouD2NavResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetMessageModificationToBeiDouD2NavResult::GetMessageModificationToBeiDouD2NavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
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

    GetMessageModificationToBeiDouD2NavResult::GetMessageModificationToBeiDouD2NavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
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


    GetMessageModificationToBeiDouD2NavResultPtr GetMessageModificationToBeiDouD2NavResult::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouD2NavResult>(signalArray, svId, startTime, stopTime, subframe, page, word, updateParity, wordModification, id);
    }

    GetMessageModificationToBeiDouD2NavResultPtr GetMessageModificationToBeiDouD2NavResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToBeiDouD2NavResult>(relatedCommand, signalArray, svId, startTime, stopTime, subframe, page, word, updateParity, wordModification, id);
    }

    GetMessageModificationToBeiDouD2NavResultPtr GetMessageModificationToBeiDouD2NavResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToBeiDouD2NavResult>(ptr);
    }

    bool GetMessageModificationToBeiDouD2NavResult::isValid() const
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

    std::string GetMessageModificationToBeiDouD2NavResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToBeiDouD2NavResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "Subframe", "Page", "Word", "UpdateParity", "WordModification", "Id"}; 
      return names; 
    }


    std::vector<std::string> GetMessageModificationToBeiDouD2NavResult::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetMessageModificationToBeiDouD2NavResult::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouD2NavResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetMessageModificationToBeiDouD2NavResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouD2NavResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetMessageModificationToBeiDouD2NavResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouD2NavResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetMessageModificationToBeiDouD2NavResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouD2NavResult::subframe() const
    {
      return parse_json<int>::parse(m_values["Subframe"]);
    }

    void GetMessageModificationToBeiDouD2NavResult::setSubframe(int subframe)
    {
      m_values.AddMember("Subframe", parse_json<int>::format(subframe, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouD2NavResult::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void GetMessageModificationToBeiDouD2NavResult::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToBeiDouD2NavResult::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void GetMessageModificationToBeiDouD2NavResult::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetMessageModificationToBeiDouD2NavResult::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void GetMessageModificationToBeiDouD2NavResult::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToBeiDouD2NavResult::wordModification() const
    {
      return parse_json<std::string>::parse(m_values["WordModification"]);
    }

    void GetMessageModificationToBeiDouD2NavResult::setWordModification(const std::string& wordModification)
    {
      m_values.AddMember("WordModification", parse_json<std::string>::format(wordModification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToBeiDouD2NavResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToBeiDouD2NavResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
