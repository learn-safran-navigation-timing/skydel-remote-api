#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPrnOfSVID.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string Accepted signal keys: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1"
    /// SvId   int    Satellite SV ID.
    /// Prn    int    PRN number.
    ///

    class GetPrnOfSVIDResult;
    typedef std::shared_ptr<GetPrnOfSVIDResult> GetPrnOfSVIDResultPtr;
    
    
    class GetPrnOfSVIDResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPrnOfSVIDResult();

      GetPrnOfSVIDResult(const std::string& signal, int svId, int prn);

      GetPrnOfSVIDResult(CommandBasePtr relatedCommand, const std::string& signal, int svId, int prn);

      static GetPrnOfSVIDResultPtr create(const std::string& signal, int svId, int prn);

      static GetPrnOfSVIDResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, int svId, int prn);
      static GetPrnOfSVIDResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetPrnOfSVIDResult);
  }
}

