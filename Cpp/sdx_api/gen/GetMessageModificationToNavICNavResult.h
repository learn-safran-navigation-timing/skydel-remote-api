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
    /// Result of GetMessageModificationToNavICNav.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ ----------------------------------------------------------------------------------------
    /// SignalArray      array string Array of signals to apply the message modification to, accepts "NAVICL5" (empty for all)
    /// SvId             int          The satellite's SV ID 1..14 (use 0 to apply modification to all SVs)
    /// StartTime        int          Elapsed time in seconds since start of simulation
    /// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// Subframe         int          Subframe 1..4 (use 0 to apply modification to all subframes)
    /// MessageType      int          NAV Message type (use -1 to apply modification to all message types)
    /// Condition        string       Optional condition to match message content, ex: "EQUAL(45, 10, 0x3f)"
    /// UpdateCRC        bool         Recalculate CRC after making modification
    /// BitModifications string       Comma separated bit modifications
    /// Id               string       Unique identifier of the event
    ///

    class GetMessageModificationToNavICNavResult;
    typedef std::shared_ptr<GetMessageModificationToNavICNavResult> GetMessageModificationToNavICNavResultPtr;
    
    
    class GetMessageModificationToNavICNavResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToNavICNavResult();

      GetMessageModificationToNavICNavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      GetMessageModificationToNavICNavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToNavICNavResultPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToNavICNavResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);
      static GetMessageModificationToNavICNavResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** subframe ****
      int subframe() const;
      void setSubframe(int subframe);


      // **** messageType ****
      int messageType() const;
      void setMessageType(int messageType);


      // **** condition ****
      std::string condition() const;
      void setCondition(const std::string& condition);


      // **** updateCRC ****
      bool updateCRC() const;
      void setUpdateCRC(bool updateCRC);


      // **** bitModifications ****
      std::string bitModifications() const;
      void setBitModifications(const std::string& bitModifications);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetMessageModificationToNavICNavResult);
  }
}

