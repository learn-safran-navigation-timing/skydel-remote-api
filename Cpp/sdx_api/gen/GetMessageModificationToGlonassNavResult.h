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
    /// Result of GetMessageModificationToGlonassNav.
    ///
    /// Name               Type         Description
    /// ------------------ ------------ --------------------------------------------------------------------------------------------
    /// SignalArray        array string Array of signals to apply the message modification to, accepts "G1" and "G2" (empty for all)
    /// SvId               int          The satellite's SV ID number 1..24 (use 0 to apply modification to all SVs)
    /// StartTime          int          Elapsed time in seconds since start of simulation
    /// StopTime           int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// Frame              int          Frame 1..5 (use 0 to apply modification to all frames)
    /// StringNumber       int          String 1..15 (use 0 to apply modification to all strings)
    /// UpdateHammingCode  bool         Recalculate Hamming Code after making modification
    /// StringModification string       Modification string must be 85 bits long (or more if using white spaces)
    /// Id                 string       Unique identifier of the event
    ///

    class GetMessageModificationToGlonassNavResult;
    typedef std::shared_ptr<GetMessageModificationToGlonassNavResult> GetMessageModificationToGlonassNavResultPtr;
    
    
    class GetMessageModificationToGlonassNavResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageModificationToGlonassNavResult();

      GetMessageModificationToGlonassNavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id);

      GetMessageModificationToGlonassNavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id);

      static GetMessageModificationToGlonassNavResultPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id);

      static GetMessageModificationToGlonassNavResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id);
      static GetMessageModificationToGlonassNavResultPtr dynamicCast(CommandBasePtr ptr);
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


      // **** frame ****
      int frame() const;
      void setFrame(int frame);


      // **** stringNumber ****
      int stringNumber() const;
      void setStringNumber(int stringNumber);


      // **** updateHammingCode ****
      bool updateHammingCode() const;
      void setUpdateHammingCode(bool updateHammingCode);


      // **** stringModification ****
      std::string stringModification() const;
      void setStringModification(const std::string& stringModification);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToGlonassNavResult);
  }
}

