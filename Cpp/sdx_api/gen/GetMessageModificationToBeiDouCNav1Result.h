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
    /// Result of GetMessageModificationToBeiDouCNav1.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ ------------------------------------------------------------------------------------
    /// SignalArray      array string Array of signals to apply the message modification to, accepts "B1C" (empty for all)
    /// SvId             int          The satellite's SV ID 1..35 (use 0 to apply modification to all SVs)
    /// StartTime        int          Elapsed time in seconds since start of simulation
    /// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// Page             int          CNAV1 page (use 0 to apply modification to all pages)
    /// Condition        string       Optional condition to match message content, ex: "EQUAL(45, 10, 0x3f)"
    /// UpdateCRC        bool         Recalculate CRC after making modification
    /// BitModifications string       Comma separated bit modifications
    /// Id               string       Unique identifier of the event
    ///

    class GetMessageModificationToBeiDouCNav1Result;
    typedef std::shared_ptr<GetMessageModificationToBeiDouCNav1Result> GetMessageModificationToBeiDouCNav1ResultPtr;
    
    
    class GetMessageModificationToBeiDouCNav1Result : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageModificationToBeiDouCNav1Result();

      GetMessageModificationToBeiDouCNav1Result(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      GetMessageModificationToBeiDouCNav1Result(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToBeiDouCNav1ResultPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToBeiDouCNav1ResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int page, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id);
      static GetMessageModificationToBeiDouCNav1ResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** page ****
      int page() const;
      void setPage(int page);


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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToBeiDouCNav1Result);
  }
}

