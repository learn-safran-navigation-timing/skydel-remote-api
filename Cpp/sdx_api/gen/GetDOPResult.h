#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDOP.
    ///
    /// Name       Type   Description
    /// ---------- ------ ----------------------------------------
    /// Horizontal double Horizontal dilution of precision (HDOP).
    /// Vertical   double Vertical dilution of precision (VDOP).
    /// Time       double Time dilution of precision (TDOP).
    /// Position   double Position dilution of precision (PDOP).
    ///

    class GetDOPResult;
    typedef std::shared_ptr<GetDOPResult> GetDOPResultPtr;
    
    
    class GetDOPResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetDOPResult();

      GetDOPResult(double horizontal, double vertical, double time, double position);

      GetDOPResult(CommandBasePtr relatedCommand, double horizontal, double vertical, double time, double position);

      static GetDOPResultPtr create(double horizontal, double vertical, double time, double position);

      static GetDOPResultPtr create(CommandBasePtr relatedCommand, double horizontal, double vertical, double time, double position);
      static GetDOPResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** horizontal ****
      double horizontal() const;
      void setHorizontal(double horizontal);


      // **** vertical ****
      double vertical() const;
      void setVertical(double vertical);


      // **** time ****
      double time() const;
      void setTime(double time);


      // **** position ****
      double position() const;
      void setPosition(double position);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetDOPResult);
  }
}

