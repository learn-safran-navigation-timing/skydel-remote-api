#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPerturbations
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------
    /// System string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// SvId   int    The satellite's SV ID.
    /// Crs    double Crs (meter)
    /// Crc    double Crc (meter)
    /// Cis    double Crs (rad)
    /// Cic    double Crc (rad)
    /// Cus    double Cus (rad)
    /// Cuc    double Cuc (rad)
    ///

    class GetPerturbationsResult;
    typedef std::shared_ptr<GetPerturbationsResult> GetPerturbationsResultPtr;
    
    
    class GetPerturbationsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPerturbationsResult();

      GetPerturbationsResult(CommandBasePtr relatedCommand, const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc);
  
      static GetPerturbationsResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc);
      static GetPerturbationsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** crs ****
      double crs() const;
      void setCrs(double crs);


      // **** crc ****
      double crc() const;
      void setCrc(double crc);


      // **** cis ****
      double cis() const;
      void setCis(double cis);


      // **** cic ****
      double cic() const;
      void setCic(double cic);


      // **** cus ****
      double cus() const;
      void setCus(double cus);


      // **** cuc ****
      double cuc() const;
      void setCuc(double cuc);
    };
  }
}

