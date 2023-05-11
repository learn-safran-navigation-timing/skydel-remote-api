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
    /// Result of GetMessageModificationToBeiDouD1Nav.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ ---------------------------------------------------------------------------------------------------
    /// SignalArray      array string Array of signals to apply the message modification to, accepts "B1", "B2" and "B3I" (empty for all)
    /// SvId             int          The satellite's SV ID 1..35 (use 0 to apply modification to all SVs)
    /// StartTime        int          Elapsed time in seconds since start of simulation
    /// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// Subframe         int          Subframe 1..5 (use 0 to apply modification to all subframes)
    /// Page             int          Page 1..24 (use 0 to apply modification to all pages)
    /// Word             int          Word 1..10 (use 0 to apply modification to all words)
    /// UpdateParity     bool         Recalculate parity after making modification
    /// WordModification string       Modification string must be 30 bits long
    /// Id               string       Unique identifier of the event
    ///

    class GetMessageModificationToBeiDouD1NavResult;
    typedef std::shared_ptr<GetMessageModificationToBeiDouD1NavResult> GetMessageModificationToBeiDouD1NavResultPtr;
    
    
    class GetMessageModificationToBeiDouD1NavResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToBeiDouD1NavResult();

      GetMessageModificationToBeiDouD1NavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id);

      GetMessageModificationToBeiDouD1NavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id);

      static GetMessageModificationToBeiDouD1NavResultPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id);

      static GetMessageModificationToBeiDouD1NavResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id);
      static GetMessageModificationToBeiDouD1NavResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** page ****
      int page() const;
      void setPage(int page);


      // **** word ****
      int word() const;
      void setWord(int word);


      // **** updateParity ****
      bool updateParity() const;
      void setUpdateParity(bool updateParity);


      // **** wordModification ****
      std::string wordModification() const;
      void setWordModification(const std::string& wordModification);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetMessageModificationToBeiDouD1NavResult);
  }
}

