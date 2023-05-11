#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Mapping PRN to the corresponding SV ID. Get a list of SV IDs based on a specific signal. Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L5", "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS", "B1", "B2", "B2a", "B1C", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S" and "NAVICL5"
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------
    /// Signal string Signal key - see GetSVIDsOfPrn command description for possible values
    /// Prn    int    Satellite PRN number
    ///

    class GetSVIDsOfPrn;
    typedef std::shared_ptr<GetSVIDsOfPrn> GetSVIDsOfPrnPtr;
    
    
    class GetSVIDsOfPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVIDsOfPrn();

      GetSVIDsOfPrn(const std::string& signal, int prn);

      static GetSVIDsOfPrnPtr create(const std::string& signal, int prn);
      static GetSVIDsOfPrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
    
  }
}

