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
    /// Result of GetMessageModificationToGlonassG2PNav.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ ------------------------------------------------------------------------------------
    /// SignalArray      array string Array of signals to apply the message modification to, accepts "G2P" (empty for all)
    /// SvId             int          The satellite's SV ID 1..24 (use 0 to apply modification to all SVs)
    /// StartTime        int          Elapsed time in seconds since start of simulation
    /// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// BitModifications string       Comma separated bit modifications
    /// Id               string       Unique identifier of the event
    ///

    class GetMessageModificationToGlonassG2PNavResult;
    typedef std::shared_ptr<GetMessageModificationToGlonassG2PNavResult> GetMessageModificationToGlonassG2PNavResultPtr;
    
    
    class GetMessageModificationToGlonassG2PNavResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageModificationToGlonassG2PNavResult();

      GetMessageModificationToGlonassG2PNavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, const std::string& bitModifications, const std::string& id);

      GetMessageModificationToGlonassG2PNavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToGlonassG2PNavResultPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, const std::string& bitModifications, const std::string& id);

      static GetMessageModificationToGlonassG2PNavResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, const std::string& bitModifications, const std::string& id);
      static GetMessageModificationToGlonassG2PNavResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** bitModifications ****
      std::string bitModifications() const;
      void setBitModifications(const std::string& bitModifications);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToGlonassG2PNavResult);
  }
}

