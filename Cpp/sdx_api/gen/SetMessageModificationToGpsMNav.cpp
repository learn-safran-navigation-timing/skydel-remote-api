
#include "gen/SetMessageModificationToGpsMNav.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetMessageModificationToGpsMNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetMessageModificationToGpsMNav::CmdName = "SetMessageModificationToGpsMNav";
    const char* const SetMessageModificationToGpsMNav::Documentation = "Set (or Modify) event to change GPS MNAV message bits. If you send this command without setting the ID\nparameter, or if you set the ID with a value never used before, a new Modification event will be\ncreated. If you reuse the same event ID, it will modify the existing event.\n\nNote that start and stop time are automatically extended to beginning and ending of overlapped\nmessages.\n\nThe Condition parameter is optional and allows you to add content matching condition before applying\nbit modifications.\n\nBitModifications can be an empty string. The Modification will have no effect until you modify it with at\nleast one bits mod.\n\nA bits mod is represented with a string using the following format: \"I:Bits\" where I is a bit\nindex (1 refers to the first transmitted bit) and Bits is a modification mask where each\ncharacter describes a modification to a single bit. The allowed characters are:\n   0 : force bit to 0\n   1 : force bit to 1\n   - : leave bit unchanged\n   X : revert bit (0 becomes 1 and 1 becomes 0)\n\nFor example: \"24:X---10XX\" will: revert bits 24, 30 and 31\n                 set bit 28 to 1\n                 set bit 29 to 0\nThe other bits are not affected.\n\nYou can add multiple bit modifications using commas. For example: \"24:X---10XX,127:100X,231:01\"";

    REGISTER_COMMAND_FACTORY(SetMessageModificationToGpsMNav);


    SetMessageModificationToGpsMNav::SetMessageModificationToGpsMNav()
      : CommandBase(CmdName)
    {}

    SetMessageModificationToGpsMNav::SetMessageModificationToGpsMNav(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, int occurrence, const std::string& condition, const std::string& bitModifications, const std::string& id)
      : CommandBase(CmdName)
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

    SetMessageModificationToGpsMNavPtr SetMessageModificationToGpsMNav::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, int occurrence, const std::string& condition, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<SetMessageModificationToGpsMNav>(signalArray, svId, startTime, stopTime, messageType, occurrence, condition, bitModifications, id);
    }

    SetMessageModificationToGpsMNavPtr SetMessageModificationToGpsMNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetMessageModificationToGpsMNav>(ptr);
    }

    bool SetMessageModificationToGpsMNav::isValid() const
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

    std::string SetMessageModificationToGpsMNav::documentation() const { return Documentation; }


    int SetMessageModificationToGpsMNav::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::vector<std::string> SetMessageModificationToGpsMNav::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void SetMessageModificationToGpsMNav::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGpsMNav::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetMessageModificationToGpsMNav::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGpsMNav::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetMessageModificationToGpsMNav::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGpsMNav::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetMessageModificationToGpsMNav::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGpsMNav::messageType() const
    {
      return parse_json<int>::parse(m_values["MessageType"]);
    }

    void SetMessageModificationToGpsMNav::setMessageType(int messageType)
    {
      m_values.AddMember("MessageType", parse_json<int>::format(messageType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGpsMNav::occurrence() const
    {
      return parse_json<int>::parse(m_values["Occurrence"]);
    }

    void SetMessageModificationToGpsMNav::setOccurrence(int occurrence)
    {
      m_values.AddMember("Occurrence", parse_json<int>::format(occurrence, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToGpsMNav::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void SetMessageModificationToGpsMNav::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToGpsMNav::bitModifications() const
    {
      return parse_json<std::string>::parse(m_values["BitModifications"]);
    }

    void SetMessageModificationToGpsMNav::setBitModifications(const std::string& bitModifications)
    {
      m_values.AddMember("BitModifications", parse_json<std::string>::format(bitModifications, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToGpsMNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetMessageModificationToGpsMNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
