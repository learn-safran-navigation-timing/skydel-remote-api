
#include "SetMessageModificationToQzssLNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetMessageModificationToQzssLNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetMessageModificationToQzssLNav::CmdName = "SetMessageModificationToQzssLNav";
    const char* const SetMessageModificationToQzssLNav::Documentation = "Set (or Modify) event to change QZSS LNAV message bits.\n"
      "\n"
      "Note that start and stop time are automatically extended to beginning and ending of overlapped\n"
      "subframes. The Modification parameter is a string where the first character applies to the first\n"
      "bit of subframe word and last character applies to last bit of subframe word.\n"
      "   '0' will force bit to zero\n"
      "   '1' will for bit to one\n"
      "   'X' will negate bit value\n"
      "   any other byte value will have no effect\n"
      "\n"
      "Example: \"-00------------------1-X------\" will force bits 1 and 2 to zero and bit 22 to one\n"
      "                      and negate bit 24\n"
      "\n"
      "Note: if UpdateParity is true, any modification to bits 25..30 will have no effect.\n"
      "\n"
      "The ID parameter is automatically updated with a unique ID by the simulator for future reference.\n"
      "If the ID is set with a value other than an empty string, the simulator will try to find a match\n"
      "with previously added events. If there is a match, the event is updated with this message\n"
      "instead of adding a new event. If there is no match, the event is added and the ID is not\n"
      "changed.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ --------------------------------------------------------------------------------------------------------\n"
      "SignalArray      array string Array of signals to apply the message modification to, accepts \"QZSSL1CA\" and \"QZSSL1CB\" (empty for all)\n"
      "SvId             int          The satellite's SV ID 1..10 (use 0 to apply modification to all SVs)\n"
      "StartTime        int          Elapsed time in seconds since start of simulation\n"
      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "Subframe         int          Subframe 1..5 (use 0 to apply modification to all subframes\n"
      "LNavSvId         int          LNAV SV ID in subframe 4 and 5 (use 0 to apply modification to all LNAV SV ID)\n"
      "Word             int          Word 1..10 (use 0 to apply modification to all words)\n"
      "UpdateParity     bool         Recalculate parity after making modification\n"
      "WordModification string       Modification string must be 30 bits long\n"
      "Id               string       Unique identifier of the event";
    const char* const SetMessageModificationToQzssLNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetMessageModificationToQzssLNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetMessageModificationToQzssLNav);


    SetMessageModificationToQzssLNav::SetMessageModificationToQzssLNav()
      : CommandBase(CmdName, TargetId)
    {}

    SetMessageModificationToQzssLNav::SetMessageModificationToQzssLNav(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int lNavSvId, int word, bool updateParity, const std::string& wordModification, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setSubframe(subframe);
      setLNavSvId(lNavSvId);
      setWord(word);
      setUpdateParity(updateParity);
      setWordModification(wordModification);
      setId(id);
    }

    SetMessageModificationToQzssLNavPtr SetMessageModificationToQzssLNav::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int lNavSvId, int word, bool updateParity, const std::string& wordModification, const std::string& id)
    {
      return std::make_shared<SetMessageModificationToQzssLNav>(signalArray, svId, startTime, stopTime, subframe, lNavSvId, word, updateParity, wordModification, id);
    }

    SetMessageModificationToQzssLNavPtr SetMessageModificationToQzssLNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetMessageModificationToQzssLNav>(ptr);
    }

    bool SetMessageModificationToQzssLNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["Subframe"])
          && parse_json<int>::is_valid(m_values["LNavSvId"])
          && parse_json<int>::is_valid(m_values["Word"])
          && parse_json<bool>::is_valid(m_values["UpdateParity"])
          && parse_json<std::string>::is_valid(m_values["WordModification"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetMessageModificationToQzssLNav::documentation() const { return Documentation; }

    const std::vector<std::string>& SetMessageModificationToQzssLNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "Subframe", "LNavSvId", "Word", "UpdateParity", "WordModification", "Id"}; 
      return names; 
    }


    int SetMessageModificationToQzssLNav::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::vector<std::string> SetMessageModificationToQzssLNav::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void SetMessageModificationToQzssLNav::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToQzssLNav::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetMessageModificationToQzssLNav::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToQzssLNav::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetMessageModificationToQzssLNav::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToQzssLNav::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetMessageModificationToQzssLNav::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToQzssLNav::subframe() const
    {
      return parse_json<int>::parse(m_values["Subframe"]);
    }

    void SetMessageModificationToQzssLNav::setSubframe(int subframe)
    {
      m_values.AddMember("Subframe", parse_json<int>::format(subframe, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToQzssLNav::lNavSvId() const
    {
      return parse_json<int>::parse(m_values["LNavSvId"]);
    }

    void SetMessageModificationToQzssLNav::setLNavSvId(int lNavSvId)
    {
      m_values.AddMember("LNavSvId", parse_json<int>::format(lNavSvId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToQzssLNav::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void SetMessageModificationToQzssLNav::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetMessageModificationToQzssLNav::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void SetMessageModificationToQzssLNav::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToQzssLNav::wordModification() const
    {
      return parse_json<std::string>::parse(m_values["WordModification"]);
    }

    void SetMessageModificationToQzssLNav::setWordModification(const std::string& wordModification)
    {
      m_values.AddMember("WordModification", parse_json<std::string>::format(wordModification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToQzssLNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetMessageModificationToQzssLNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
