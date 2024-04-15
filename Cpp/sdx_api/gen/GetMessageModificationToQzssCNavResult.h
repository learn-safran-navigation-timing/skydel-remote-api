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
    /// Result of GetMessageModificationToQzssCNav.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ -----------------------------------------------------------------------------------------------------
    /// SignalArray      array string Array of signals to apply the message modification to, accepts "QZSSL2C" and "QZSSL5" (empty for all)
    /// SvId             int          The satellite's SV ID 1..10 (use 0 to apply modification to all SVs)
    /// StartTime        int          Elapsed time in seconds since start of simulation
    /// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// MessageType      int          CNAV Message type (use -1 to apply modification to all message types)
    /// Condition        string       Optional condition to match message content, ex: "EQUAL(45, 10, 0x3f)"
    /// UpdateCRC        bool         Recalculate CRC after making modification
    /// BitModifications string       Comma separated bit modifications
    /// Id               string       Unique identifier of the event
    ///

    class GetMessageModificationToQzssCNavResult;
    typedef std::shared_ptr<GetMessageModificationToQzssCNavResult> GetMessageModificationToQzssCNavResultPtr;
    
    
    class GetMessageModificationToQzssCNavResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageModificationToQzssCNavResult();

      GetMessageModificationToQzssCNavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      GetMessageModificationToQzssCNavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToQzssCNavResultPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToQzssCNavResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);
      static GetMessageModificationToQzssCNavResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToQzssCNavResult);
  }
}

