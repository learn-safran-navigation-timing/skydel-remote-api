#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Mapping PRN to the corresponding SV ID. Get a list of SV IDs based on a specific signal. Accepted signal keys: "GPS_L1_CA", "GPS_L1C", "GPS_L2C", "GPS_L5", "GLONASS_G1", "GLONASS_G2", "GALILEO_E1", "GALILEO_E5a", "GALILEO_E5b", "GALILEO_E6", "BEIDOU_B1", "BEIDOU_B2", "BEIDOU_B1C", "BEIDOU_B2a", "SBAS_L1", "SBAS_L5", "QZSS_L1_CA", "QZSS_L1C", "QZSS_L5", "QZSS_L1S", "QZSS_L5S", "NAVIC_L5", "CS1", "CS2", "CS3", "CS4", "CS5", "CS6", "CS7", "CS8", "SIGNAL_COUNT"
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------
    /// Signal string Signal key - see command description for possible values
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

