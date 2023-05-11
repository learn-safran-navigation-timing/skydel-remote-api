#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetMessageModificationToGpsMNav.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ ------------------------------------------------------------------------------------------------
    /// SignalArray      array string Array of signals to apply the message modification to, accepts "L1ME" and "L2ME" (empty for all)
    /// SvId             int          The satellite's SV ID 1..32 (use 0 to apply modification to all SVs)
    /// StartTime        int          Elapsed time in seconds since start of simulation
    /// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// MessageType      int          MNAV Message type
    /// Occurrence       int          Occurrence number in message sequence (1 based, or use -1 to match any occurrence)
    /// Condition        string       Optional condition to match message content, ex: "EQUAL(45, 10, 0x3f)"
    /// BitModifications string       Comma separated bit modifications
    /// Id               string       Unique identifier automatically set by simulator
    ///

    class GetMessageModificationToGpsMNavResult;
    typedef std::shared_ptr<GetMessageModificationToGpsMNavResult> GetMessageModificationToGpsMNavResultPtr;
    
    
    class GetMessageModificationToGpsMNavResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToGpsMNavResult();

      GetMessageModificationToGpsMNavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, int occurrence, const std::string& condition, const std::string& bitModifications, const std::string& id);

      GetMessageModificationToGpsMNavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, int occurrence, const std::string& condition, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToGpsMNavResultPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, int occurrence, const std::string& condition, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToGpsMNavResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, int occurrence, const std::string& condition, const std::string& bitModifications, const std::string& id);
      static GetMessageModificationToGpsMNavResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signalArray ****
      std::vector<std::string> signalArray() const;
      void setSignalArray(const std::vector<std::string>& signalArray);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** startTime ****
      int startTime() const;
      void setStartTime(int startTime);


      // **** stopTime ****
      int stopTime() const;
      void setStopTime(int stopTime);


      // **** messageType ****
      int messageType() const;
      void setMessageType(int messageType);


      // **** occurrence ****
      int occurrence() const;
      void setOccurrence(int occurrence);


      // **** condition ****
      std::string condition() const;
      void setCondition(const std::string& condition);


      // **** bitModifications ****
      std::string bitModifications() const;
      void setBitModifications(const std::string& bitModifications);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetMessageModificationToGpsMNavResult);
  }
}

