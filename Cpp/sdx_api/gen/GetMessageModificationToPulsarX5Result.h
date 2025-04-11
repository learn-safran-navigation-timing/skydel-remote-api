#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetMessageModificationToPulsarX5.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ -----------------------------------------------------------------------------------------
    /// SignalArray      array string Array of signals to apply the message modification to, accepts "PULSARX5" (empty for all)
    /// SvId             int          The satellite's SV ID 1..258 (use 0 to apply modification to all SVs)
    /// StartTime        int          Elapsed time in seconds since start of simulation
    /// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// Condition        string       Optional condition to match message content, ex: "EQUAL(45, 10, 0x3f)"
    /// UpdateCRC        bool         Recalculate CRC after making modification
    /// BitModifications string       Comma separated bit modifications
    /// Id               string       Unique identifier of the event
    ///

    class GetMessageModificationToPulsarX5Result;
    typedef std::shared_ptr<GetMessageModificationToPulsarX5Result> GetMessageModificationToPulsarX5ResultPtr;
    
    
    class GetMessageModificationToPulsarX5Result : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageModificationToPulsarX5Result();

      GetMessageModificationToPulsarX5Result(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      GetMessageModificationToPulsarX5Result(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToPulsarX5ResultPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToPulsarX5ResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);
      static GetMessageModificationToPulsarX5ResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToPulsarX5Result);
  }
}

