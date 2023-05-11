
#include "gen/GetMessageModificationToGlonassNavResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGlonassNavResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGlonassNavResult::CmdName = "GetMessageModificationToGlonassNavResult";
    const char* const GetMessageModificationToGlonassNavResult::Documentation = "Result of GetMessageModificationToGlonassNav.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetMessageModificationToGlonassNavResult);


    GetMessageModificationToGlonassNavResult::GetMessageModificationToGlonassNavResult()
      : CommandResult(CmdName)
    {}

    GetMessageModificationToGlonassNavResult::GetMessageModificationToGlonassNavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id)
      : CommandResult(CmdName)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setFrame(frame);
      setStringNumber(stringNumber);
      setUpdateHammingCode(updateHammingCode);
      setStringModification(stringModification);
      setId(id);
    }

    GetMessageModificationToGlonassNavResult::GetMessageModificationToGlonassNavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setFrame(frame);
      setStringNumber(stringNumber);
      setUpdateHammingCode(updateHammingCode);
      setStringModification(stringModification);
      setId(id);
    }


    GetMessageModificationToGlonassNavResultPtr GetMessageModificationToGlonassNavResult::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGlonassNavResult>(signalArray, svId, startTime, stopTime, frame, stringNumber, updateHammingCode, stringModification, id);
    }

    GetMessageModificationToGlonassNavResultPtr GetMessageModificationToGlonassNavResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGlonassNavResult>(relatedCommand, signalArray, svId, startTime, stopTime, frame, stringNumber, updateHammingCode, stringModification, id);
    }

    GetMessageModificationToGlonassNavResultPtr GetMessageModificationToGlonassNavResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGlonassNavResult>(ptr);
    }

    bool GetMessageModificationToGlonassNavResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["Frame"])
          && parse_json<int>::is_valid(m_values["StringNumber"])
          && parse_json<bool>::is_valid(m_values["UpdateHammingCode"])
          && parse_json<std::string>::is_valid(m_values["StringModification"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGlonassNavResult::documentation() const { return Documentation; }


    std::vector<std::string> GetMessageModificationToGlonassNavResult::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetMessageModificationToGlonassNavResult::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGlonassNavResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetMessageModificationToGlonassNavResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGlonassNavResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetMessageModificationToGlonassNavResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGlonassNavResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetMessageModificationToGlonassNavResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGlonassNavResult::frame() const
    {
      return parse_json<int>::parse(m_values["Frame"]);
    }

    void GetMessageModificationToGlonassNavResult::setFrame(int frame)
    {
      m_values.AddMember("Frame", parse_json<int>::format(frame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMessageModificationToGlonassNavResult::stringNumber() const
    {
      return parse_json<int>::parse(m_values["StringNumber"]);
    }

    void GetMessageModificationToGlonassNavResult::setStringNumber(int stringNumber)
    {
      m_values.AddMember("StringNumber", parse_json<int>::format(stringNumber, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetMessageModificationToGlonassNavResult::updateHammingCode() const
    {
      return parse_json<bool>::parse(m_values["UpdateHammingCode"]);
    }

    void GetMessageModificationToGlonassNavResult::setUpdateHammingCode(bool updateHammingCode)
    {
      m_values.AddMember("UpdateHammingCode", parse_json<bool>::format(updateHammingCode, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToGlonassNavResult::stringModification() const
    {
      return parse_json<std::string>::parse(m_values["StringModification"]);
    }

    void GetMessageModificationToGlonassNavResult::setStringModification(const std::string& stringModification)
    {
      m_values.AddMember("StringModification", parse_json<std::string>::format(stringModification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMessageModificationToGlonassNavResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGlonassNavResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
